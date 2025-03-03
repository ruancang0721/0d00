#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <wait.h>
int main(int argc, char const *argv[])
{

   int fd[2];
   pid_t pid;
   int ret;
   ret = pipe(fd);
   if(ret == -1)
   {
    perror("pipe error");
    exit(1);
   }
   pid = fork();
   if(pid == -1)
   {
    perror("fork error");
    exit(1);
   }
   else if(pid==0)
   {
      close(fd[0]);
      dup2(fd[1],STDOUT_FILENO);
      execlp("ls","ls",NULL);

   }
   else if(pid>0)
   {
       close(fd[1]);
       dup2(fd[0],STDIN_FILENO);
       execlp("wc","wc","-l",NULL);
   }


    return 0;
}