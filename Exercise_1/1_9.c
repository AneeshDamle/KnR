#include <stdio.h>

#define FIRSTBLANK 1
#define MOREBLANKS 2

/* Copy input to output, restrict consecutive blanks to single blank */
main()
{
    int c, state;

    state = FIRSTBLANK;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ') {
            if (state == FIRSTBLANK) {
                putchar(c);
                state = MOREBLANKS;
            }
        } else {
            putchar(c);
            state = FIRSTBLANK;
        }
    }
}
