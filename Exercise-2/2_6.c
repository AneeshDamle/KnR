#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void)
{
    unsigned x, y;
    int p, n;

    // Get values
    printf("x: ");
    scanf("%u", &x);
    printf("p: ");
    scanf("%d", &p);
    printf("n: ");
    scanf("%d", &n);
    printf("y: ");
    scanf("%u", &y);

    // Display setbits return
    printf("\n%u\n", setbits(x, p, n, y));

    return 0;
}

/* setbits: set n bits from position p of x to n bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned a = x & ((~0 << (p+1)) | (~(~0 << (p-n+1))));
    unsigned b = y & ~(~0 << n);
    return (a | (b << (p-n+1)));
}

