#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void escape(char *s, char *t);
void real(char *s, char *t);

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    // Read input line
    nread = getdelim(&line, &len, EOF, stdin);
    if (nread == -1) {
        printf("Unable to read a line from stdin.\n");
        free(line);
        return 1;
    }

    /* Mallocate twice the size of original line
     * Each newline character may be converted to two chars '\' and 'n'
     */
    char *escline = malloc(strlen(line) * sizeof(char) * 2);
    escape(escline, line);
    printf("1\n");
    puts(escline);
    free(escline);

    /* Mallocate same size of original line
     * Max length will be same as original
     */
    char *realline = malloc(strlen(line) * sizeof(char));
    real(realline, line);
    printf("2\n");
    puts(realline);
    free(realline);

    free(line);
    return 0;
}

/* escape: converts newline, tab in t to visible escape sequences \n, \t in s */
void escape(char *s, char *t)
{
    int i, j;

    i = j = 0;
    while (t[i] != '\0')
    {
        switch(t[i]) {
            case '\n':
                s[j] = '\\';
                s[++j] = 'n';
                break;
            case '\t':
                s[j] = '\\';
                s[++j] = 't';
                break;
            default:
                s[j] = t[i];
                break;
        }
        i++;
        j++;
    }
    s[j] = '\0';
}

/* real: converts escape sequences into the real characters */
void real(char *s, char *t)
{
    int i, j;
    i = j = 0;

    while (t[i] != '\0')
    {
        if (t[i] == '\\')
        {
            if (t[i+1] == 'n') {
                s[j] = '\n';
                i++;
            } else if (t[i+1] == 't') {
                s[j] = '\t';
                i++;
            } else {
                s[j] = t[i];
            }
        }
        else
        {
            s[j] = t[i];
        }
        j++;
        i++;
    }

    return;
}

