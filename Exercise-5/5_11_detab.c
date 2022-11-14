#include <stdio.h>

/* Here, n is a symbolic parameter */
#define DEFAULT_TABSTOP (8)     /* default tabstop length */

/* detab - replace tabs in the input with the proper number of blanks 
 * to space to the next tabstop
 */
int main(int argc, char *argv[])
{
    int ch, i, k, tabstop;

    if (argc > 2 || (argc == 2 && argv[1][0] != '-')) {
        printf("Usage: entab [optional -n]\n");
        return 1;
    }

    if (argc == 1)
        tabstop = DEFAULT_TABSTOP;
    else
        tabstop = atoi(&(argv[1][1]));
    //printf("TS: %d\n", tabstop);


    k = TABSTOP;

    while ((ch = getchar()) != EOF) {
        if (ch == '\t') {
            for (i = 0; i < k; ++i)
                putchar(' ');
        } else {
            putchar(ch);
            --k;
            if (k == 0)
                k = tabstop;
        }
    }

    return 0;
}
