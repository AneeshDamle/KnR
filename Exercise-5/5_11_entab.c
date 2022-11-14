#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_TABSTOP (8)     /* default tabstop length */
#define OUT (0)
#define IN (1)

/* replace input blanks by minimum blanks and tabs */
int main(int argc, char *argv[])
{
    int c;          /* character input */
    int bl;         /* counts total blanks in input */
    int t;          /* stores total tabs to replace blanks */
    int state, i;
    int tabstop;

    if (argc > 2 || (argc == 2 && argv[1][0] != '-')) {
        printf("Usage: entab [optional -n]\n");
        return 1;
    }

    if (argc == 1)
        tabstop = DEFAULT_TABSTOP;
    else
        tabstop = atoi(&(argv[1][1]));
    //printf("TS: %d\n", tabstop);

    bl = t = i = 0;
    state = IN;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            state = OUT;
            ++bl;
        } else {
            if (state == OUT) {
                t = bl / tabstop;
                for (i = 0; i < t; ++i)
                    putchar('\t');
                for (i = 0; i < bl - t * tabstop; ++i)
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

