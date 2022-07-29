#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFSIZE 100

int getch(void);
void ungetch(int);

/* The meaning of the question is that instead of a BUFSIZE array for
 * unreading an extra-read character, space for only 1 character is provided
 */
int buffer = 0;

int main(void)
{
    printf("%c\n", getch());
    ungetch(EOF);
    printf("%c\n", getch());
    return 0;
}

int getch(void)
{
    return (buffer > 0) ? buffer : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (buffer > 0)
        printf("ungetch: too many characters\n");
    else
        buffer = c;
}

