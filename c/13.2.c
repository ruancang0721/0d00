#include <stdio.h>
#include <stdlib.h>
void copy(char *a,char *b)
{
    FILE *a_fp,*b_fp;
    char buffer[1024];
    size_t len;
    a_fp = fopen(a,"rb");
    if(a_fp == NULL)
    {
        printf("无法打开源文件捏");
        exit(EXIT_FAILURE);
    }
    b_fp = fopen(b,"wb");
    if(b_fp == NULL)
    {
        printf("无法打开目标文件捏");
        exit(EXIT_FAILURE);
    }
    while((len = fread(buffer,1,sizeof(buffer),a_fp))>0)
    {
        fwrite(buffer,1,len,b_fp);
    }
    fclose(a_fp);
    fclose(b_fp);


}
int main(int argc,char *argv[]) 
{
   if(argc!=3)
   {
    exit(EXIT_FAILURE);
   }
    copy(argv[1],argv[2]);
    return 0;
}