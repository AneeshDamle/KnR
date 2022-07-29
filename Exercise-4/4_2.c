#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINE 100

/* rudimentary calculator */
main()
{
    double sum, AtoF(char []);
    char line[MAXLINE];
    int Getline(char line[], int max);

    sum = 0;
    while (Getline(line, MAXLINE) > 0)
        printf("\t%f\n", sum += AtoF(line));
    return 0;
}


/* Getline: get line into s, return length */
int Getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}


/* atof: convert string s to double, also handle scientific notation */
double AtoF(char s[])
{
    double val, power, scipower, scival;
    int i, sign, scisign;;

    for (i = 0; isspace(s[i]); ++i) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.')    /* decimal point */
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E') /* scientific notation */
        i++;

    scisign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (scipower = 0.0; isdigit(s[i]); i++)
    {
        scipower = 10.0 * scipower + (s[i] - '0');
    }
    for (scival = 1.0; scipower--; scival *= 10.0)
        ;

    if (scisign == 1)
        return sign * val / power * scival;
    else
        return sign * val / power / scival;
}


