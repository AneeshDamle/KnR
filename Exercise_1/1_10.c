#include <stdio.h>

/* Copy input to output, replace each tab by \t, each backspace by \b, each
 * backslash by \\
 */
main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            printf("\\t");
        else if (c == '\b')         /* Backspace detection issue */
            printf("\\b");
        else if (c == '\\')
            printf("\\");
        else
            putchar(c);
    }
}
