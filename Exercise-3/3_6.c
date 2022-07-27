#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void itoa3(int n, char s[], int w);

int main(void)
{
    int num, width;
    printf("Number: ");
    scanf("%d", &num);
    printf("Width: ");
    scanf("%d", &width);

    char *s = (char *)malloc(sizeof(char) * (width + 1));
    itoa3(num, s, width);
    printf("%s", s);
    free(s);

    return 0;
}


/* reverse:  reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}


void itoa3(int n, char s[], int w) {
    int i, sign;

    // Special case for handling the largest negative number
    if (n == INT_MIN)
    {
        s[0] = '-';
        itoa3(INT_MAX, s+1, w);
        s[w] += 1;
        return;
    }

    if ((sign = n) < 0) /* record sign */
        n = -n;         /* make n positive */

    i = 0;
    do {    /* generate digits in reverse order */
        s[i++] = n % 10 + '0';  /* get next digit */
    } while ((n /= 10) > 0 && i < w);    /* delete it */

    if (sign < 0)
        s[i++] = '-';

    while (i <= w) {
        s[i++] = ' ';
    }
    s[w] = '\0';

    reverse(s);
}

