#include <stdio.h>
int main() 
{
    int count=0;
    char ch;
    while((ch=getchar())!='#')
    {
        count++;
        putchar(ch);
        printf("-%d ",ch);
        if(count%8==0)
        printf("\n");
    }
    return 0;
}