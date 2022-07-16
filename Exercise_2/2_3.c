#include <stdio.h>
#define MAXLINE 100         /* maximum length of input line */

int htoi(char s[], int maxline);

main()
{
    char c;
    char s[MAXLINE];                /* current input line */
    int i, lim = MAXLINE;

    for (i = 0; i < lim-1 && (c = getchar()) != '\n' && c != EOF; ++i)
        s[i] = c;
    s[i] = '\0';

    printf("%d\n", htoi(s, lim));

    return 0;
}

/* htoi: compute decimal from hexadecimal string s of length maxline */
int htoi(char s[], int maxline) {
    int i, n;
    i = n = 0;

    /* check for an optional "0x" or "0X" */
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        i = 2;

    for (i; i < maxline && s[i] != '\0'; ++i)
        if (s[i] >= '0' && s[i] <= '9')
            n = n * 16 + s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            n = n * 16 + s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            n = n * 16 + s[i] - 'A' + 10;

    return n;
}

