#include <stdio.h>


int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x >>= 1)
        b++;
    return b;
}


/* rightrot: return value of integer x rotated n bitpositions to the right */
unsigned rightrot(unsigned x, int n)
{
    int i, a;
    unsigned y = x;

    for (i = 0; i < n; ++i) {
        a = y & 1;
        y = y >> 1;
        a = a << bitcount(y);
        y = y | a;
    }

    return y;
}


main()
{
    unsigned x;
    int n;

    // Get values
    printf("x: ");
    scanf("%u", &x);
    printf("n: ");
    scanf("%d", &n);

    // Display setbits return
    printf("\n%u\n", rightrot(x, n));

    return 0;
}


