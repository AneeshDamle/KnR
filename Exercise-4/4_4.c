#include <stdio.h>
#include <stdlib.h>     /* for atof() */

void push(double);
double pop(void);
void peek(void);
void swap(void);
void clear(void);

main()
{
    push(1.0);
    push(2.0);
    peek();
    swap();
    peek();
    clear();
    peek();
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

/* peek: display top value of stack */
void peek(void)
{
    if (sp > 0)
        printf("Top: %f\n", val[sp-1]);
    else
        printf("Stack is empty\n");
}

/* swap: swap top two elements of stack */
void swap(void)
{
    double temp = val[sp-1];
    val[sp-1] = val[sp-2];
    val[sp-2] = temp;
}

/* clear: clear the stack */
void clear(void)
{
    while (sp > 0)
    {
        val[--sp] = 0.0;
    }
}

