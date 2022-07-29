#include <stdio.h>
#include <string.h>

void reverse(char s[], int len);

int main(void)
{
    char str[25];

    scanf("%s", str);
    reverse(str, strlen(str));
    puts(str);

    return 0;
}

/* reverse: reverses string s in place */
void reverse(char s[], int len)
{
    /* if string contains only/less than 1 character */
    if (len <= 1)
        return;

    // Swap the first and last characters
    char tmp = s[0];
    s[0] = s[len - 1];
    s[len - 1] = tmp;

    /* Each string with starting position one after, and length 2 elements less
     * will reverse itself 
     */
    reverse(s + 1, len - 2);
    return;
}

