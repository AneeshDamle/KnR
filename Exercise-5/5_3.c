#include <stdio.h>
#include <string.h>

/* str_cat: copies string t to the end of s; s must be big enough */
void str_cat(char *s, char *t)
{
    while (*s != '\0')
        s++;
    while ((*s++ = *t++) != '\0')
        ;

    return;
}

int main(void)
{
    char str1[20] = "Hello ";
    char str2[] = "world!";

    printf("str1: %s\t\tstr1l: %lu\nstr2: %s\n", str1, strlen(str1), str2);
    str_cat(str1, str2);
    printf("str1: %s\tstr1l: %lu\nstr2: %s\n", str1, strlen(str1), str2);

    return 0;
}


