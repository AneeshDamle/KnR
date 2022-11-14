#include <stdio.h>
#include <string.h>

/* reverse: reverses string in-place */
void reverse(char *s) {
    for (int i = 0, j = strlen(s) - 1, temp; i < j; i++, j--)
        temp = s[i], s[i] = s[j], s[j] = temp;
}

/* strend: returns 1 if string t occurs at the end of s, and zero otherwise */
int strend(char *s, char *t) {
    reverse(s), reverse(t);
    while (*s == *t)
        s++, t++;
    if (*t == '\0')
        return 1;
    return 0;
}

int main(void) {
    char str1[] = "Mindflayer", str2[] = "flayer";
    printf("%d\n", strend(str1, str2));
    return 0;
}
