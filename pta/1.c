#include <stdio.h>
int main()
{
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int e =a+b+c+d;
    printf("Sum = %d; Average = %.1f",e,(float)e/4);
    return 0;
}