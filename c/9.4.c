#include <stdio.h>
double tiaohe(double x,double y)
{
    return 1/((1/x+1/y)/2);
}
int main()
{
    double a,b,c;
    scanf("%lf%lf",&a,&b);
    c = tiaohe(a,b);
    printf("%lf",c);
    return 0;
}