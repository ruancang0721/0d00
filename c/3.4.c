#include <stdio.h>
int main()
{
    float a=0;
    
    printf("Enter a floating-point value: ");
    scanf("%f", &a);
    printf("fixed-point notation: %f\n",a);
    printf("exponent notation: %e\n",a);
    printf("p notation: %p",&a);
    return 0;
}