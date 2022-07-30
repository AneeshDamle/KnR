#include <stdio.h>

#define swap(t, x, y)   (x = x + y, y = x - y, x = x - y)

int main(void)
{
    int x = 1, y = 2;
    swap(int, x, y);
    printf("x: %d\ny: %d\n", x, y);
    return 0;
}

