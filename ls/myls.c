#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>























int main(int argc,char * argv[])
{
    DIR* dp;
    struct dirent* dirp;
    char path[256]={0};
     if(argc==1)
    {
        strcpy(path,".");

    }
    dp = opendir(path);
    if(dp==NULL)
    {
        perror("opendir");
        exit(1);
    }

   
   while((dirp=readdir(dp))!=NULL)
   {
      printf("%s\n",dirp->d_name);
   }
   closedir(dp);


















    return 0;
}