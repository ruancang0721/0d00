#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<getopt.h>
typedef struct{
  int a;
  int l;
  int R;
  int t;
  int r;
  int i;
  int s;
}Options;
typedef struct{
  char* name;
  struct stat st;
}filei;
void ls(char* path,Options* opts,int ll)
{
    DIR * dir = opendir(path);
       if(dir == NULL)
       {
        perror("opendir error");
        return;
       }
       struct dirent *ent;
               filei* files = NULL;
        size_t count =0;
        size_t n=0;
        long long totalblock=0;
       while((ent = readdir(dir))!=NULL)
       {
        if((opts->a!=1)&&ent->d_name[0]=='.')
        {
          continue;
        }
        char fullpath[1024];
        snprintf(fullpath,1024,"%s/%s",path,ent->d_name);

        filei file;
        if(lstat(fullpath,&file.st)<0)
        {
          perror("lstat error");
          continue;
        }
        file.name = ent->d_name;
        if(count>=n)
        {
          n+=10;
          files = realloc(files,n*sizeof(filei));
        }
        files[count++]=file;
        totalblock +=file.st.st_blocks;
        
        


       }
       closedir(dir);
       if(opt->t)
       {
        qsort(files,count,)
       }




    closedir(dir);
}

int main(int argc,char* argv[])
{
     Options options;
     int opt;
     while((opt=getopt(argc,argv,"alRrtsi"))!=-1)
     {
      switch(opt)
      {
        case 'a':
        options.a=1;
        break;
        case 'l':
        options.l=1;
        break;
        case 'R':
        options.R=1;
        break;
        case 't':
        options.t=1;
        break;
        case 'r':
        options.r=1;
        break;
        case 'i':
        options.i=1;
        break;
        case 's':
        options.s=1;
        break;
        default:
        perror("weizhi error");
        return 1;

      }
     }
     int dirnum = 0;
     char **dir =NULL;
     if(optind<argc)
     {
          dirnum = argc -optind;
          dir = argv + optind;
     }
     if(dirnum == 0)
     {
        ls(".",&options,0);
     }
     else{
      for(int i=0;i<dirnum;i++)
      {
        if(dirnum>1)
        {
          printf("%s:\n",dir[i]);

        }
        ls(dir[i],&options,0);
        if(dirnum>1&&i!=dirnum-1)
        {
          printf("\n");
        }
      }
     }


    return 0;
}