#include <stdio.h>

/* Determine whether processor storage follows row-major or column-major */
// TODO: A bit doubtful about this
int main(void)
{
    int a[10][20];
    a[3][4] = 80;
    int *p = a;
    printf("%d\n", *(p + 20 * 3 + 4)); /* returns 80 hurray! */
    return 0;
}

