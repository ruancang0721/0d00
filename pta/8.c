#include<stdio.h>
int main()
{
    int m=0,n=0,a=0,b=0,c=0;
    scanf("%d%d",&m,&n);
    c=(m>n?n:m);
    while(c>1)
    {
        if(m%c==0&&n%c==0)
        {
            a=c;
            break;
        }
        c--;
    }
    if(c==1)
        a=c;
    c=(m>n?m:n);
    while(1)
    {
        if(c%m==0&&c%n==0)
        {b=c;break;}
        c++;
        
    }
    printf("%d %d",a,b);
    return 0;
}