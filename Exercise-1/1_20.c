#include <stdio.h>

/* Here, n is a symbolic parameter */
#define TABSTOP (8)         /* tabstop length */

/* detab - replace tabs in the input with the proper number of blanks 
 * to space to the next tabstop
 */
main() {

    int ch, i, k;

    k = TABSTOP;

    while ((ch = getchar()) != EOF) {
        if (ch == '\t') {
            for (i = 0; i < k; ++i)
                putchar(' ');
        } else {
            putchar(ch);
            --k;
            if (k == 0)
                k = TABSTOP;
        }
    }

    return 0;
}
