#include<stdio.h>
#include<string.h>
int main()
{
    char a[100]={0};
    char b[100]={0};
    scanf("%s",a);
    scanf("%s",b);
    int m=strlen(a);
    int n=strlen(b);
    printf("%s",a);
    printf(" ");
    printf("%s\n",b);
    for(int i=0;i<m-1;i++)
    printf(" ");
    printf("%d",m);
    printf(" ");
    for(int i=0;i<n-1;i++)
    printf(" ");
    printf("%d",n);
    return 0;
}