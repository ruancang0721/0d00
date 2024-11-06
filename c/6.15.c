#include <stdio.h>
#include <string.h>
int main() 
{
    char a[255]={0};
    scanf("%s",a);
    int b=strlen(a);
    for(int i=0;i<b;i++)
    {
        printf("%c",a[b-i-1]);
    }
    return 0;
}