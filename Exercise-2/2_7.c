#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(void)
{
    unsigned x;
    int p, n;

    // Get values
    printf("x: ");
    scanf("%u", &x);
    printf("p: ");
    scanf("%d", &p);
    printf("n: ");
    scanf("%d", &n);

    // Display setbits return
    printf("\n%u\n", invert(x, p, n));

    return 0;
}

/* setbits: set n bits from position p of x to n bits of y */
unsigned invert(unsigned x, int p, int n)
{
    return (x ^ ((~0 << (p-n+1)) & ~(~0 << (p+1))));
}

