#include <stdio.h>

main()
{
    int c;
    if ((c = getchar()) == EOF) {
        printf("%d\n", c);          /* Value of EOF = -1 */
    }
}
