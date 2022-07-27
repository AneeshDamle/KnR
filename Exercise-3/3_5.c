#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void itob(int n, char s[], int b);

int main(void)
{
    int num, base;
    char *s = malloc(sizeof(char) * 15);

    // Get number, base
    printf("Number: ");
    scanf("%d", &num);
    printf("Base: ");
    scanf("%d", &base);

    itob(num, s, base);
    puts(s);
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


/* itoa: convert n to characters in s */
void itob(int n, char s[], int b) {
    int i, sign;
    // Special case for handling the largest negative number
    if (n == INT_MIN)
    {
        switch(b) {

            case (10):
                s[0] = '-';
                itob(INT_MAX, s+1, b);
                s[strlen(s) - 1] += 1;
                return;
            case (2):
                s[0] = '1';
                itob(INT_MAX, s+1, b);
                return;
            case (16):
                itob(INT_MAX, s, b);
                s[0] = 'F';
                return;
        }
    }

    if ((sign = n) < 0 && (n != INT_MIN)) /* record sign */
        n = -n;         /* make n positive */

    i = 0;

    do {    /* generate digits in reverse order */
        int tmp = n % b;
        s[i] = tmp + '0';  /* get next digit */
        // Hexadecimal integer case
        if (tmp >= 10 && tmp <= 15)
            s[i] = 'A' - 10 + (n % b);
        i++;
    } while ((n /= b) > 0);    /* delete it */

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

