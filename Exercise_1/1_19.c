#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 20                     /* maximum input line size */

void reverseline(char line[], int maxline);
int Getline(char s[], int lim);

/* reverse character string s */
main()
{
    int len;                        /* current line length */
    char line[MAXLINE];             /* current input line */

    while ((len = Getline(line, MAXLINE)) > 0) {
        reverseline(line, MAXLINE);
        printf("%s\n", line);
    }

    return 0;
}

/* Getline: read a line into s, return length */
int Getline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* reverseline: reverse string s, keeping it printable */
void reverseline(char line[], int max) {

    int i, j, k;
    char reverse[max];                  /* reversed line stored in temp */

    i = j = k = 0;
    while (line[i] != '\0')
        ++i;

    while (j < i) {
        reverse[j] = line[i - 1 - j];   /* reverse original string in temp */
        ++j;
    }
    reverse[j] = '\0';

    while ((line[k] = reverse[k]) != '\0')  /* copy temp to original string */
        ++k;

}

