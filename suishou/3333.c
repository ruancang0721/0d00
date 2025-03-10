#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <errno.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/wait.h>
int hash[1000000] = {0};
int sh_cd(char ** args)
{
   if(args[1]==NULL)
   {
    chdir(getenv("HOME"));
   }
   else{
        if(chdir(args[1])!=0)
        {
           printf("cd: no such file or directory: %s\n",args[1]);
        }

   }
   return 1;
}
int sh_exit(char ** args)
{
  return 0;
}
int shuru(char **args)
{
    char filename[200000];
    int i=0;
         while(args[i]!=NULL)
         {
            if(strcmp(args[i],"<")==0)
            {
                
            }
         }
 

}
int cmd_num(char** args)
{
    int i=0;
    int num = 0;
    while(args[i]!=NULL)
    {
        if(strcmp(args[i],"|")==0)
        {
            num++;
        }
    }
    num++;

    return num;
}
char * mysh_read()
{
   char * line = NULL;
  ssize_t bufsize;
  getline(&line,&bufsize,stdin);
  return line;
}
char ** mysh_split_line(char * line)
{
 int bufsize = 100;
  int pos =0;
  char ** args = (char **)malloc(bufsize*sizeof(char*));
  char * token;
      token = strtok(line," \t\n\r");
   while(token != NULL)
   {
    args[pos++] = token;
    token = strtok(NULL," \t\n\r");
   }
   args[pos] = NULL;
   return args;
}

int mysh_execute(char ** args)
{
   if(args[0]==NULL)
   {
      return 1;
   }
   if(strcmp(args[0],"cd")==0)
   {
      return sh_cd(args);
   }
   if(strcmp(args[0],"exit")==0)
   {
      return sh_exit(args);
   }





   



}
void mysh_loop()
{
    char * line;
     char** args;

  int status;
    do{
        char path[100];
        getcwd(path,100);
        char now[200] = "[ruancang-";
        strcat(now,path);
        strcat(now,"]$");
        printf("%s",now);

        line = mysh_read();
        int * cmdnum = NULL;
        args = mysh_split_line(line);

           status = mysh_execute(args);
           free(args);
           free(line);
    }while(status);
}
int main(int argc, char *argv[])
{
mysh_loop();
return 0;
}