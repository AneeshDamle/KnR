#include <stdio.h>              /* Compiler gives warning implicit declaration else */
                                                                                
main()                              /* expected identifier or ‘(’ before ‘{’ token */
{                                   /* ELSE Compiler gives error expected declaration specifiers */
    printf("hello, world\&\n");     /* Unknown escape sequence '\&' */
    /* Since \c is an escape sequence for an allowed char c, if c is not
     * allowed, compiler can't identify the '\', thus it ignores the /, gives a
     * warning, and prints the next character as if it is part of the character
     * string of printf
     */
}                                                                               
