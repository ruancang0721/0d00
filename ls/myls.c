#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<dirent.h>
#include<sys/stat.h>



void read_dir(char*dir)
{
    char path[256];
    DIR* dp;
    struct dirent * dirp;
    dp = opendir(dir);
    while((dirp =readdir(dp))!=NULL)
    {
        sprintf(path,"%s/%s",dir,dirp->d_name);
        isfile(path);
    }
    closedir(dp);

    
}
void isfile(char* name)
{
    struct stat st;
    int ret = stat(name,&st);
    if(ret == -1)
    {
        perror("stat");
        return;
    }
    if(S_ISDIR(st.st_mode))
    {
           read_dir(name);
    }
    printf("%s\t%ld\n",name,st.st_size);
}

int main(int argc,char* argv[])
{

   if(argc==1)
   {
    isfile(".");
   }
   else{
    isfile(argv[1]);
   }
    return 0;
}