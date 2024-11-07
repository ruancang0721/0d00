#include<stdio.h>
#include<ctype.h>
int main()
{
    int ch;
    printf("输入(按ctrl+d退出)");
    while((ch = getchar())!=EOF)
    {
        if(isprint(ch))
        {
            putchar(ch);
        }
        else if(ch=='\n')
        printf("\\n");
        else if(ch == '\t')
        printf("\\t");
        else
        printf("%d",ch);
    }
    

    return 0;
}