#include <stdio.h>
#include <string.h>
typedef struct{
 char ming[100];
 char zhongjian[100];
 char xing[100];
}Name;
typedef struct{
    char baoxian[100];
      Name name;
}Person;
void print(Person p)
{
    printf("%s,%s ",p.name.ming,p.name.xing);
    if(strlen(p.name.zhongjian)>0)
    printf("%c.",p.name.zhongjian[0]);
    printf("----%s",p.baoxian);
}
int main()
{
   Person p[5]={
        {"302039823", {"Flossie", "M", "Dribble"}},
        {"123456789", {"John", "A", "Doe"}},
        {"987654321", {"Jane", "", "Smith"}},
        {"111223333", {"Emily", "B", "Brown"}},
        {"444556666", {"Michael", "C", "Johnson"}}
    };

    for(int i=0;i<5;i++)
    {
        print(p[i]);
        printf("\n");
    }
    return 0;
}