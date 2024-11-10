#include <stdio.h>
void a()
{
    printf("选择菜单a\n");
}
void b()
{
    printf("选择菜单b\n");
}
void c()
{
    printf("选择菜单c\n");
}
int main() 
{
    void (*caidan[])()={a,b,c};
     printf("请选择\n");
     printf("1.菜单a\n");
     printf("2.菜单b\n");
     printf("3.菜单c\n");
     char choice;
     scanf("%c",&choice);
     switch(choice)
     {
        case 'a':
            caidan[0]();
            break;
        case 'b':
            caidan[1]();
            break;
        case 'c':
            caidan[2]();
            break;
        default:
            printf("输入错误\n");
            break;
     }
    return 0;
}