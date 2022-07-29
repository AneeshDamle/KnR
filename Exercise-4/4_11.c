int getch(void);
void ungetch(int);
/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    /* Static variables are guaranteed to be initialised to 0,
     * if not explicitly mentioned
     */ 
    static int extra;   /* for storing extra character read from input */

    if (extra == ' ' || extra == '\t')
        while ((s[0] = c = getch()) == ' ' || c == '\t')
            ;
    else
        s[0] = extra;

    s[1] = '\0';

    /* not a number */
    if (!isdigit(c) && c != '.')
        return c;

    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            extra = c;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            extra = c;

    s[i] = '\0';

    return NUMBER;
}
