#include<stdio.h>
#include<ctype.h>
void readword(char word[])
{
    int index=0;
    int ch;
    while((ch=getchar())!=EOF&&isspace(ch));
     if(ch==EOF)
     {
        word [0]='\0';
        return;
     }
     word[index++]=ch;
     while((ch=getchar())!=EOF&&!isspace(ch))
     {
        word[index++]=ch;
       
     }
     word[index]='\0';
     printf("输入的单词是\n");
     printf("%s\n",word);
}
int main()
{
    char word[100];
    printf("请输入\n");
    readword(word);
    return 0;
}