#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void expand(char s1[], char s2[]);

int main(void)
{
    char *line = NULL, *expanded_line = NULL;
    size_t len = 0;

    // Read file from input
    while (getline(&line, &len, stdin) != -1);

    expanded_line = (char *)malloc(sizeof(char) * strlen(line) + 1);
    if (!expanded_line) {
        printf("Could not malloc line for expansion.\n");
        free(line);
        return 0;
    }

    expand(line, expanded_line);
    printf("%s", expanded_line);
    return 0;
}

/* expand: expands shorthand notations like 'a-z' in s1 into 'abc...xyz' in s2 */
void expand(char s1[], char s2[]) {

    int i, j, k;
    int s2len = strlen(s1) + 1;

    for (i = 0, k = 0 ; s1[i] != '\0'; i++)
    {
        if (s1[i+1] == '-')
        {
            // Alphabet expansion, numeric expansion
            if (isalnum(s1[i]) && isalnum(s1[i+2]))
            {
                // Allocate space for expansion
                if (s1[i+2] - s1[i] - 2) {
                    s2len += s1[i+2] - s1[i] - 2;
                    s2 = realloc(s2, s2len);
                }

                for (j = s1[i]; j < s1[i+2]; j++) {
                    s2[k] = j;
                    k++;
                }
                i++;
            }
        }
        else {
            s2[k] = s1[i];
            k++;
        }

    }
    s2[k] = '\0';
}


