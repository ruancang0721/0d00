#include <stdio.h>
int main() 
{
    printf("输入整数\n");
    int n=0;
    scanf("%d",&n);
    for(int i=n;i<n+11;i++)
{
    printf("%d\n",i);
}
    return 0;
}