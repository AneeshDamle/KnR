#include <stdio.h>

#define TABSTOP (7)
#define OUT (0)
#define IN (1)

/* replace input blanks by minimum blanks and tabs */
main()
{
    int c;          /* character input */
    int bl;         /* counts total blanks in input */
    int t;          /* stores total tabs to replace blanks */
    int state, i;

    bl = t = i = 0;
    state = IN;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            state = OUT;
            ++bl;
        } else {
            if (state == OUT) {
                t = bl / TABSTOP;
                for (i = 0; i < t; ++i)
                    putchar('\t');
                for (i = 0; i < bl - t * TABSTOP; ++i)
                    putchar(' ');
                state = IN;
                bl = 0;
                t = 0;
            }
            putchar(c);
        }
    }
    return 0;
}

