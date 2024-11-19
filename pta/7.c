#include<stdio.h>
#include<math.h>
int main()
{
    double eps=0,sum=0,a=0;
    int n=1;
    scanf("%lf",&eps);
while(1)
{
    a=(((n%2==1)?(1.0):(-1))/(3.0*n-2));
    
    sum=sum+a;
    if(eps>=fabs(a))
        break;
    n++;
}
    printf("sum = %f",sum);
    return 0;
}