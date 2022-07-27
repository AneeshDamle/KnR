#include <stdio.h>
#define MAXLINE 100                 /* maximum input line size */

#define     BETWEEN_WORDS   0       /* blank or tab between words */
#define     TRAILING_BLANK  1       /* blanks are trailing characters */
#define     TRAILING_TAB    2       /* tabs are trailing characters */

/* remove trailing blanks and tabs from line, delete blank lines */
main()
{
    int c, state, len;
    int nlc;                /* Count of newlines, blanks, tabs */
    char line[MAXLINE];

    state = BETWEEN_WORDS;
    len = nlc = 0;

    while ((c = getchar()) != EOF) {

        if (len < MAXLINE - 1) {

            if (c == '\n') {
                ++nlc;
                if (nlc == 1) {
                    line[len] = c;
                    ++len;
                }
            } else {
                nlc = 0;
                if (c == ' ')
                    state = TRAILING_BLANK;
                else if (c == '\t')
                    state = TRAILING_TAB;
                else {
                    if (state == TRAILING_BLANK) {
                        line[len] = ' ';
                        ++len;
                    } else if (state == TRAILING_TAB) {
                        line[len] = '\t';
                        ++len;
                    }
                    state = BETWEEN_WORDS;
                    line[len] = c;
                    ++len;
                }
            }
        } else {
            break;
        }
    }

    line[len] = '\0';
    printf("Output : %s", line);

    return 0;
}
