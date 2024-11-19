#include <stdio.h>

int main() 
{
    FILE *fp;
    char ch =0;
    int count =0;
    fp = fopen("test.txt", "r");
    if(fp == NULL)
      {
        printf("不能打开");
        return 0;
        }
        
    while((ch = fgetc(fp))!=EOF)
    {
        count++;
    }
    printf("有%d个字符",count);
    return 0;
    }
