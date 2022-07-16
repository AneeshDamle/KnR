#include <stdio.h>
#define MAXLINE 100         /* maximum length of input line */

void squeezemini(char s[], char c);
void squeeze(char s1[], char s2[]);

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

    squeeze(s1, s2);
    puts(s1);

    return 0;
}

/* squeezemini: delete all c from s */
void squeezemini(char s[], char c)
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; ++i)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

/* squeeze: delete each character in s1 that matches any character in s2 */
void squeeze(char s1[], char s2[])
{
    int i;

    for (i = 0; s2[i] != '\0'; ++i)
        squeezemini(s1, s2[i]);
}

