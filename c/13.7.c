#include <stdio.h>
#include <stdlib.h>
void openfile(char *name)
{
    FILE *fp=fopen(name,"r");
    if(fp == NULL)
    {
        perror("error");
        return;
    }
    printf("yes");
    fclose(fp);
}

int main(int argc, char *argv[]) 
{
   char name1[100],name2[100];
     if(argc>=3)
     {
        openfile(argv[1]);
        openfile(argv[2]);
     }
     else
     {
        printf("1\n");
        scanf("%s",name1);
        printf("2\n");
        scanf("%s",name2);
        openfile(name1);
        openfile(name2);
     }
    return 0;
}