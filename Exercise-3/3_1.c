#include <stdio.h>

int binsearch0(int x, int v[], int n);
int binsearch1(int x, int v[], int n);

int main(void)
{
    int arr[] = {1, 3, 5, 6, 9, 11, 20, 99};
    printf("%d\n", binsearch1(9, arr, 9));
    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-2] <= v[n-1] */
int binsearch0(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else    /* found match */
            return mid;
    }
    return -1;  /* no match */
}

int binsearch1(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && x != v[mid]) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
    }

    if (x == v[mid])    /* found match */
        return mid;
    return -1;          /* no match */
}


