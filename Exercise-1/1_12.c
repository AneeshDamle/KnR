#include <stdio.h>

#define IN 1
#define OUT 0

/* Print input one word per line */
main()
{
    int c, state;

    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                putchar('\n');
                state = OUT;
            }
        } else {
            printf("%c", c);
            state = IN;
        }
    }
}

