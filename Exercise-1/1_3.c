#include <stdio.h>                                                              
                                                                                
/* print Fahrenheit-Celsius table                                               
 * for fahr = 0, 20, ... , 300; floating-point version */                       
                                                                                
#define START   0                                                               
#define STOP    300                                                             
#define STEP    20                                                              
                                                                                
/* temperature conversion */                                                    
float compute_celsius(float fahr);                                              
                                                                                
int main(void)                                                                  
{                                                                               
    float fahr, celsius;
    int lower, upper, step;                                                     
                                                                                
    lower = START;      /* lower limit of temperature table */                  
    upper = STOP;    /* upper limit */                                          
    step = STEP;      /* step size */                                           
                                                                                
    /* heading above the table */                                               
    printf("Fahrenheit Vs Celsius\n");                                          
                                                                                
    fahr = lower;                                                               
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32);
        printf("%3.0f %6.1f\n", fahr, celsius);                   
        fahr = fahr + step;                                                     
    }
    return 0;                                                                   
}                                                                               
