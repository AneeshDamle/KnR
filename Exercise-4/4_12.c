#include <stdio.h>

void itoa(int n, char v[]);

int main(void)
{
    int num;

    printf("N: ");
    scanf("%d", &num);
    char str[25];
    itoa(num, str);
    puts(str);

    return 0;
}

/* itoa: convert an integer into a string recursively */
void itoa(int n, char v[])
{
    static int i;
    if (n < 0)
    {
        v[i++] = '-';
        n = -n;
    }
    if (n / 10)
        itoa(n / 10, v);
    v[i++] = (n % 10 + '0');
    v[i] = '\0';
}
