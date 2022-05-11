#include <stdio.h>

#define MAX_LEN 10          /* Stores maximum word length allowed */

/* histogram of word lengths , i.e. one column counts words of same length */
int main(void)
{
    int i, j, count = 0, ch, k;
    int histogram[MAX_LEN];         /* Create a histogram array */

    /* Initialize histogram array to zero */
    for (i = 0; i < MAX_LEN; i++) {
        histogram[i] = 0;
    }

    /* Compute word lengths and update histogram */
    while ((ch = getchar()) != EOF) {
        if (ch == ' ') {
            ++histogram[count];
            count = 0;
        } else {
            ++count;
        }
    }
    ++histogram[count];

    /* Display the horizontal histogram */
    printf("Horizontal histogram\n");
    for (i = 0; i < MAX_LEN; i++) {
        putchar(i + '0');
        putchar(' ');
        for (j = 0; j < histogram[i]; j++) {
            putchar('*');
        }
        putchar('\n');
    }

    /* Display vertical histogram */
    printf("Vertical histogram\n");
    
    // 1    Calculate max frequency of words
    k = histogram[0];
    for (i = 1; i < MAX_LEN; i++) {
        if (k < histogram[i]) {
            k = histogram[i];
        }
    }

    while (k > 0)
    {
        printf("%d|", k);

        for (i = 0; i < MAX_LEN; i++) {
            if (histogram[i] >= k) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
        --k;
    }

    printf("  ");
    for (i = 0; i < MAX_LEN; i++) {
        printf("%d", i);
    }

    return 0;
}


