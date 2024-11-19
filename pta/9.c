#include<stdio.h>
int main()
{
    int n=0,a=0,count=0,sum=0;
    scanf("%d",&n);
    while(n>=10)
    {
    sum= sum+n%10;
        n=n/10;
     count++;   
    }
    if(n<10)
    {
        sum =sum+n;
        count++;
    }
    printf("%d %d",count,sum);
    return 0;
}