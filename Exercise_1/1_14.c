#include <stdio.h>

/* Histogram of frequencies of different characters in its input */
main()
{
    int alph[26] = {0};
    char c;

    while ((c = getchar()) != EOF) {
        if ('a' < c < 'z') {
            ++alph[c - 'a'];
        } else if ('A' < c < 'Z') {
            ++alph[c - 'A'];
        }
    }

    for (int i = 0; i < 26; i++) {
        printf("\n%3d|\t%d", i, alph[i]);
    }

}
