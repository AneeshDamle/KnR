#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES (5000)     /* max #lines to be sorted */
#define MAXLEN 1000     /* max length of any input line */

char *lineptr[MAXLINES];    /* pointers to text lines */

int readlines(char *lineptr[], int maxlines, char **lines);

void writelines(char *lineptr[], int nlines);

void quicksort(char *lineptr[], int left, int right);

/* free_lines: free the array used for storing the lines read */
void free_lines(char **lines) {
    for (int i = 0; i < MAXLINES; i++) {
        free(lines[i]);
        lines[i] = NULL;
    }
    free(lines);
    lines = NULL;
    return;
}

/* sort input lines*/
int main() {
    int nlines;     /* number of input lines read */
    char **lines;     /* array to store lines read */

    lines = (char **)malloc(sizeof(char *) * MAXLINES);
    if (!lines) {
        printf("Could not create array of linepointers.\n");
        return 1;
    }
    for (int i = 0; i < MAXLINES; i++) {
        lines[i] = (char *)malloc(sizeof(char) * MAXLEN);
        if (!lines[i]) {
            printf("Could not create line %d.", i);
            free_lines(lines);
            return 2;
        }
    }
    if ((nlines = readlines(lineptr, MAXLINES, lines)) >= 0) {
        quicksort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        free_lines(lines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        free_lines(lines);
        return 1;
    }
    free(lines);
    return 0;
}

int get_line(char *, int);
char *alloc(int);

/* readlines: read input lines and store them in an array */
int readlines(char *lineptr[], int maxlines, char **lines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0) {
        if (nlines >= maxlines) {
            return -1;
        } else {
            line[len-1] = '\0'; /* delete newline */
            strcpy(lines[nlines], line);
            lineptr[nlines] = lines[nlines];
            nlines++;
        }
    }
    return nlines;
}

/* getline : read a line into s, return length */
int get_line(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */

char *alloc(int n) {    /* return pointer to n characters */
    if (allocbuf + ALLOCSIZE - allocp >= n) {   /* it fits */
        allocp += n;
        return allocp - n;  /* old p */
    } else      /* not enough room */
        return 0;
}

/* quicksort: sort v[left]...v[right] into increasing order */
void quicksort(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)  /* do nothing if array contains */
        return;         /* fewer than two elements */

    swap(v, left, (left + right)/2);
    last = left;

    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);

    swap(v, left, last);
    quicksort(v, left, last-1);
    quicksort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j) {
    char *temp;
    temp = v[i], v[i] = v[j], v[j] = temp;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

