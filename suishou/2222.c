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



char * cmd[] = 
{
  
  "cd",
  "exit"

};
int cmd_num()
{
  return sizeof(cmd)/sizeof(char*);
}


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
int sh_launch(char ** args)
{
  pid_t pid,wpid;
  int status;
  pid = fork();
  if(pid ==0)
  {
    if(execvp(args[0],args)==-1)
    {
      perror("execvp");

    }
    exit(0);
  }
  else{
     do
     {
        wpid = waitpid(pid,&status,WUNTRACED);
     } while (!WIFEXITED(status) &&!WIFSIGNALED(status));
     
  }
  return 1;
}
char * mysh_read()
{
   char * line = NULL;
  ssize_t bufsize;
  getline(&line,&bufsize,stdin);
  return line;






}
int (* cmd_func[]) (char **) =
{
     
     &sh_cd,
     &sh_exit

};
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
   for(int i=0;i<cmd_num();i++)
   {
    if(strcmp(args[0],cmd[i])==0)
    {
      return (*cmd_func[i])(args);
    }

   }

return sh_launch(args);




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