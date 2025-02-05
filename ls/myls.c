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
int comparetime1(const void*a,const void*b)
{
  return ((filei*)a)->st.st_mtime-((filei*)b)->st.st_mtime;
}
int comparetime2(const void*a,const void*b)
{
  return ((filei*)b)->st.st_mtime-((filei*)a)->st.st_mtime;
}
int compareshunxu(const void *a,const void *b)
{
  return strcmp(((filei*)a)->name,((filei*)b)->name);
}
int comparenixu(const void *a,const void *b)
{
  return -compareshunxu(a,b);
}
void  modescore(char* str,mode_t mode)
{
  if(S_ISDIR(mode))
  {
   strcat(str,"d");
  }
  else if(S_ISLNK(mode))
  {
    strcat(str,"l");
  }
  else if(S_ISBLK(mode))
  {
    strcat(str,"b");
  }
  else if(S_ISCHR(mode))
  {
    strcat(str,"c");
  }
  else if(S_ISFIFO(mode))
  {
    strcat(str,"p");
  }
  else if(S_ISSOCK(mode))
  {
    strcat(str,"s");
  }
  else
  {
    strcat(str,"-");
  }
  if(mode&S_IRUSR)
  {
    strcat(str,"r");
  }
  else
  {
    strcat(str,"-");
  }
  if(mode&S_IWUSR)
  {
    strcat(str,"w");
  }
  else{
    strcat(str,"-");
  }
  if(mode&S_IXUSR)
  {
    strcat(str,"x");
  }
  else{
    strcat(str,"-");
  }
  if(mode&S_IRGRP)
  {
    strcat(str,"r");
  }
  else{
    strcat(str,"-");
  }
  if(mode&S_IWGRP)
  {
    strcat(str,"w");
  }
  else{
    strcat(str,"-");
  }
  if(mode&S_IXGRP)
  {
    strcat(str,"x");
  }
  else{
    strcat(str,"-");
  }
  if(mode&S_IROTH)
  {
    strcat(str,"r");
  }
  else{
    strcat(str,"-");
  }
  if(mode&S_IWOTH)
  {
    strcat(str,"w");
  }
  else{
    strcat(str,"-");
  }
  if(mode&S_IXOTH)
  {
    strcat(str,"x");
  }
  else{
    strcat(str,"-");
  }

  
}
void lsprint(filei *file,Options* opts)
{
  if(opts->i)
  {
    printf("%ld\n",file->st.st_ino);
  }
  if(opts->s)
  {
    printf("%3ld",file->st.st_blocks);
  }
  if(opts->l)
  {
    char mode[11];
    mode[0]='\0';
    modescore(mode,file->st.st_mode);
    printf("%s",mode);


  }
}
void ls(char* path,Options* opts)
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
       if(opts->t)
       {
        if(opts->r)
        {qsort(files,count,sizeof(filei),comparetime1);
        }
        else{
          qsort(files,count,sizeof(filei),comparetime2);
        }
       }
       else
       {
        if(opts->r)
        {
          qsort(files,count,sizeof(filei),comparenixu);
        }
        else{
          qsort(files,count,sizeof(filei),compareshunxu);
        }
       }
       lsprint(files,opts);
       free(files);

       }


int main(int argc,char* argv[])
{
     Options options = {0};
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
        ls(".",&options);
     }
     else{
      for(int i=0;i<dirnum;i++)
      {
        if(dirnum>1)
        {
          printf("%s:\n",dir[i]);

        }
        ls(dir[i],&options);
        if(dirnum>1&&i!=dirnum-1)
        {
          printf("\n");
        }
      }
     }



    return 0;
}