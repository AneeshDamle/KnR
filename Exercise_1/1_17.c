#include <stdio.h>
#define LINELENGTH 10

/* Print all input lines with 80+ characters */
main()
{
    int i, len, max;
    char c;
    char line[LINELENGTH];

    len = 0;
    max = LINELENGTH;

    /* Get character input till EOF */
    while ((c = getchar()) != EOF){

        if (c == '\n') {
            len = 0;
        }
        /* Fill the line array till newline character is not encountered */
        else {
            if (len < max) {
                line[len] = c;
                ++len;
            }
            /* If length exceeds max limit, print the stored line, and output
             * every input character after till newline character is not reached
             */
            else if (len == max) {
                for (int i = 0; i < max; i++) {
                    putchar(line[i]);
                    ++len;
                }
                putchar(c);
            }

            else {
                putchar(c);
            }
        }
    }

    return 0;
}

