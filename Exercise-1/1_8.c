#include <stdio.h>

/* Count blanks, tabs and newlines */
main()
{
    int blanks, tabs, newlines, c;

    blanks = tabs = newlines = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blanks;
        } else if (c == '\t') {
            ++tabs;
        } else if (c == '\n') {
            ++newlines;
        }
    }
    printf("\nBlanks:\t%d\nTabs:\t%d\nNewlines:\t%d\n", blanks, tabs, newlines);
}


