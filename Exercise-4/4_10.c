// Include libraries
#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <ctype.h>
#include <string.h>

// Define constants
#define MAXOP 100       /* max size of operand or operator */
#define NUMBER '0'      /* signal that a number was found */
#define MAXVAL 100      /* maximum length of val stack */

// Function declarations
int getop(char s[]);
void push(double);
double pop(void);

// External variables
int sp = 0;             /* next free stack position */
double val[MAXVAL];     /* value stack */
float num;              /* buffer for float operand */

/* Using getline, we store the string in a character array.
 * Since the string reading can be controlled by an static index, 
 * getch and ungetch functions are unncessary.
 */

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char *s;
    size_t len;

    // Get string from user
    while (getline(&s, &len, stdin) != -1)
        ;

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(num);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\t", pop());
                break;
            case 0:
                free(s);
                return 0;
            default:
                printf("error: unknown command %s\n", s);
                exit(0);
                break;
        }
    }
    free(s); /* free space allocated by getline */
    return 0;
}

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
    {
        printf("error: stack full, can't push %g\n", f);
        exit(0);
    }
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* getop: get next character or numeric operand */
int getop(char s[])
{
    static int i = 0;              /* index of the next character to be read */
    int len = strlen(s);
    for (; i < len; i++)
    {
        while (s[i] == ' ' || s[i] == '\t') /* skip white spaces */
            i++;

        if (!isdigit(s[i]) && s[i] != '.')  /* return non-digits */
            return s[i++];

        if (isdigit(s[i]))
        {
            int k = 0;
            char tmp[len]; /* stores the numeric value */

            while (isdigit(s[i]))
                tmp[k++] = s[i++];

            if (s[i] == '.')
            {
                do {
                    tmp[k++] = s[i++];
                } while (isdigit(s[i]));
            }
            tmp[k] = '\0';
            num = atof(tmp); /* convert string to float and store it in num */
            return NUMBER;
        }
    }
    return 0;
}

