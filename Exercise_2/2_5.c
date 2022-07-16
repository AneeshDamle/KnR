#include <stdio.h>
#include <string.h>
#define MAXLINE 100         /* maximum length of input line */

int any(char s1[], char s2[]);

main() {

    char c;
    char s1[MAXLINE];                /* first input line */
    char s2[MAXLINE];                /* second input line */
    int i, lim = MAXLINE;

    printf("First line:");
    for (i = 0; i < lim-1 && (c = getchar()) != '\n' && c != EOF; ++i)
        s1[i] = c;
    s1[i] = '\0';

    printf("Second line:");
    for (i = 0; i < lim-1 && (c = getchar()) != '\n' && c != EOF; ++i)
        s2[i] = c;
    s2[i] = '\0';

    printf("%d\n", any(s1, s2));
    puts(strpbrk(s1, s2));

    return 0;
}

/* any: returns the first location in s1 where any character from s2 occurs,
 * or -1 if s1 contains no character common to s2*/
int any(char s1[], char s2[]) {

    int i, j;

    for (i = 0; s1[i] != '\0'; ++i)
        for (j = 0 ; s2[j] != '\0'; ++j)
            if (s1[i] == s2[j])
                return i;

    return -1;
}


