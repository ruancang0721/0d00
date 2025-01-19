#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
void ls(char * path)
{
    DIR * dir = opendir(path);
    if(dir == NULL)
    {
        perror("open error");
        return;
    }
      struct dirent * ptr;
      while((ptr = readdir(dir))!=NULL)
      {
        if(ptr->d_name[0]!='.')
      {
       
        printf("%s\n",ptr->d_name);
      }
      
      }
  


    closedir(dir);
}

int main(int argc,char* argv[])
{
    char *path = ".";



    if(argc == 2)
    {
        path = argv[1];
    }
    ls(path);
    return 0;
}