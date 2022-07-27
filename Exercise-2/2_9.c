#include <stdio.h>


/* x &= (x-1) deletes the rightmost 1-bit in x.
 * Why so? This bit (pun-intended) is intuitively fantastic!
 * Anding x and x-1 is the same as making all previous 0's '1',
 * and the rightmost 1-bit '0'.
 * Or, in another way, complementing the binary number till the rightmost 1-bit.
 * For example, 6 = 110, 6-1 = 5 = 101.
 * Thus, we just have to AND x and x-1.
 */



/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x-1))
        b++;
    return b;
}


main()
{
    unsigned x;

    // Get values
    printf("x: ");
    scanf("%u", &x);

    // Display setbits return
    printf("\n%u\n", bitcount(x));

    return 0;
}


