#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int);
void ungets(char s[]);

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int main(void)
{
    char str[] = "Hello!";
    ungets(str);
    for (int i = 0; i < bufp; i++)
    {
        printf("%c ", buf[i]);
    }
    putchar('\n');
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

/* ungets: push back an entire string onto the input */
void ungets(char s[])
{
    for (int i = 0; s[i] != '\0'; ++i) {
        ungetch(s[i]);
    }
}


