#include <stdio.h>
#include <string.h>
int main()
{
    printf("输入名和姓");
    char name[20];
    int c =strlen(name);
 
    for(int i=0;i<=c;i++)
    {
        scanf("%s",name);
    }
    printf("\"%s\"\n",name);

    for(int i=0;i<20-c-2;i++)
    {
        printf(" ");
    }
    printf("\"%s\"\n",name);
    printf("\"%s\"",name);
    for(int i=0;i<20-c-2;i++)
    {
        printf(" ");
    }
    return 0;
}