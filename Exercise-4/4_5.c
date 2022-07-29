#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <strings.h>
#include <math.h>

#define MAXOP 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */
#define SIN '1'     /* signal that sine operator was found */
#define EXP '2'     /* signal that exponent operator was found */
#define POW '3'     /* signal that power operator was found */


int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
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
            case SIN:
                op2 = atof(s);
                push(sin(op2));
                break;
            case EXP:
                op2 = atof(s);
                push(exp(op2));
                break;
            case POW:
                op2 = atof(s);
                push(pow(pop(), op2));
                break;
            case '\n':
                printf("\t%.8g\t", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

#define MAXVAL 100  /* maximum length of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
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

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && !isalpha(c))
        return c;       /* not a number */
    i = 0;
    if (isdigit(c))     /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')       /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;

    if (isalpha(c))     /* collect sin, exp, pow operator */
    {
        while (isalpha(s[++i] = c = getch()))
            ;
        if (c == '(')
        {
            s[i] = '\0';
            if (strcasecmp(s, "sin") == 0)
            {
                // Get the operand
                i = -1;
                while (isdigit(s[++i] = c = getch()))
                    ;
                if (c == '.')       /* collect fraction part */
                    while (isdigit(s[++i] = c = getch()))
                        ;
                s[i] = '\0';

                return SIN;
            }
            else if (strcasecmp(s, "exp") == 0)
            {
                // Get the operand
                i = -1;
                while (isdigit(s[++i] = c = getch()))
                    ;
                if (c == '.')       /* collect fraction part */
                    while (isdigit(s[++i] = c = getch()))
                        ;
                s[i] = '\0';

                return EXP;
            }
            else if (strcasecmp(s, "pow") == 0)
            {
                // Get the first operand
                i = -1;
                while (isdigit(s[++i] = c = getch()))
                    ;
                if (c == '.')       /* collect fraction part */
                    while (isdigit(s[++i] = c = getch()))
                        ;
                s[i] = '\0';
                if (c == ',')
                {
                    push(atof(s));
                    while ((s[0] = c = getch()) == ' ' || c == '\t')
                        ;
                    // Get the second operand
                    i = 0;
                    while (isdigit(s[++i] = c = getch()))
                        ;
                    if (c == '.')       /* collect fraction part */
                        while (isdigit(s[++i] = c = getch()))
                            ;
                    s[i] = '\0';
                }
                return POW;
            }
        }
    }

    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

/*! IMPORTANT */

#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp > BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}


