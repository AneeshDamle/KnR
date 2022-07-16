#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>

void print_char_range(void);
void print_int_range(void);
void print_long_range(void);
void print_short_range(void);
void print_floatpoint_range(void);

/* Program to determine range of char,short,int,long, various floating point
 * types; signed and unsigned */
int main(void) {

    /* char */
    //print_char_range();

    /* int */
    //print_int_range();

    /* long */
    //print_long_range();

    /* short */
    //print_short_range();

    /* floating-point */
    print_floatpoint_range();

    return 0;
}
 

void print_char_range(void) {

    char a, b;

    printf("char\n");
    printf("bits in a char: %d\n", CHAR_BIT);

    a = b = 1;
    for (int i = 1; i < CHAR_BIT; ++i) {
        b *= 2;
        a += b;
    }

    printf("maximum value of char:\t\t%d\n", CHAR_MAX);
    printf("maximum value of char(computed):%d\n", a);
    printf("minimum value of char: \t\t%d\n", CHAR_MIN);
    printf("minimum value of char(computed):%d\n", a + 1);

    printf("maximum value of signed char:\t%d\n", SCHAR_MAX);    /* signed char */
    printf("minimum value of signed char:\t%d\n", SCHAR_MIN);

    printf("maximum value of unsigned char: %d\n", UCHAR_MAX);  /* unsigned char */

    putchar('\n');
}


void print_int_range(void) {

    int a, b;

    printf("int\n");
 
    a = b = 1;
    for (int i = 1; i < 31; ++i) {
        b *= 2;
        a += b;
    }

    printf("maximum value of int:\t\t%d\n", INT_MAX);
    printf("maximum value of int(computed):\t%d\n", a);
    printf("minimum value of int:\t\t%d\n", INT_MIN);
    printf("minimum value of int(computed):\t%d\n", a + 1);

    printf("maximum value of unsigned int:  %d\n", UINT_MAX);    /* unsigned int */

    putchar('\n');
}


void print_long_range(void) {

    printf("long\n");
 
    long a, b;

    printf("int\n");
 
    a = b = 1L;
    for (int i = 1; i < 63; ++i) {
        b *= 2;
        a += b;
    }
    printf("maximum value of long:\t\t%ld\n", LONG_MAX);
    printf("maximum value of long(computed):%ld\n", a);
    printf("minimum value of long:\t\t%ld\n", LONG_MIN);
    printf("minimum value of long(computed):%ld\n", a + 1);

    printf("maximum value of unsigned long: %lu\n", ULONG_MAX);    /* unsigned long */

    putchar('\n');
}

void print_short_range(void) {

    printf("short\n");
    printf("maximum value of short:\t\t%d\n", SHRT_MAX);
    printf("minimum value of short:\t\t%d\n", SHRT_MIN);

    printf("maximum value of unsigned short:%d\n", USHRT_MAX);    /* unsigned short */
}


void print_floatpoint_range(void) {

    printf("\nfloat\n");
    float a, b;

    a = 9.999999;
    b = 9.9999999;

    printf("decimal digits of precision(float): %d\n", FLT_DIG);
    printf("a:%f\nb:%f\n", a, b);
    printf("decimal digits of precision(long double): %d\n", LDBL_DIG);

    printf("smallest positive number s.t. x + 1.0 != 1.0: %e\n", FLT_EPSILON);
    printf("maximum value of floating-point number: %e\n", FLT_MAX);
    printf("maximum n s.t. FLT_RADIX^n -1 is representable: %d\n", FLT_MAX_EXP);
    printf("minimum normalised floating-point number: %e\n", FLT_MIN);

    printf("\ndouble\n");

    double a1, b1;
    // TODO: Figure out how to check double and long-double precision
    a1 = 9.999999;
    b1 = 9.9999999;
    printf("decimal digits of precision(double): %d\n", DBL_DIG);
    printf("a:%lf\nb:%lf\n", a1, b1);
    printf("decimal digits of precision(long double): %d\n", LDBL_DIG);

    printf("smallest positive number s.t. x + 1.0 != 1.0: %e\n", DBL_EPSILON);
    printf("maximum double floating-point number: %e\n", FLT_MAX);
    printf("maximum n s.t. FLT_RADIX^n -1 is representable: %d\n", DBL_MAX_EXP);
    printf("minimum normalised double floating-point number: %e\n", DBL_MIN);


}

