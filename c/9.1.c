#include <stdio.h>
double min(double a,double b)
{
    if(a<b)
    return a;
    else
    return b;
}

int main() 
{
    double a,b,c;

    scanf("%lf %lf",&a,&b);
     c= min(a,b);
     printf("%lf",c);
    return 0;
}