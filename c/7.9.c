#include <stdio.h>
int main() 
{

 int n=0;
 scanf("%d",&n);
 printf("1 2");
 for(int i=3;i<=n;i++)
 {
    for(int j=2;j<i;j++)
    {if(i%j==0)
        break;
        if(j==i-1)
        printf(" %d",i);
    }
 }
    return 0;
}