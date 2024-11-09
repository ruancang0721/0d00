#include <stdio.h>
void get(char *str,int n)
{
    printf("请输入\n");
    for(int i=0;i<n;i++)
    {
        str[i]=getchar();
    }
    str[n]='\0';
    printf("输入的是%s",str);
}

int main() 
{
    int n;
    printf("获取多少字符？\n");
    scanf("%d",&n);
    while(getchar()!='\n');
    char str[n+1];
    get(str,n);
    return 0;
}