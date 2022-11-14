#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 10         /* maximum integers that can be read */
#define BUFSIZE 100

int getch(void);
void ungetch(int);

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int main(void)
{
    int n;
    float array[SIZE];
    int getfloat(float *);

    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
        ;
    for (int i = 0; i < SIZE; ++i) {
        printf("%f-", array[i]);
    }
    return 0;
}

/* getfloat: get next float value from input into *pn */
int getfloat(float *pn)
{
    int c, sign;
    float power;

    while (isspace(c = getch()))    /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    power = 1;
    if (c == '.') /* eval fractional part */
        for (power = 1; isdigit(c = getch()); power *= 10)
            *pn = 10 * *pn + (c - '0');
    *pn *= sign / power;
    if (c != EOF)
        ungetch(c);
    return c;
}

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


