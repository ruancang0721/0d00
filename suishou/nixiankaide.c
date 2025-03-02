#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <wait.h>
int main(int argc, char const *argv[])
{

pid_t pid;
int fd[2];
char * str = "hello pipe\n";
char buf[1024];
int ret = pipe(fd);
if(ret<0)
{
  perror("pipe error");
  exit(1);
}
 pid = fork();
 if(pid>0)
 {
  close(fd[0]);
  write(fd[1],str,strlen(str));
  close(fd[1]);
  sleep(1);
 }
 else{
  close(fd[1]);
  ret = read(fd[0],buf,sizeof(buf));
  write(STDOUT_FILENO,buf,ret);
  close(fd[0]);
 }

    return 0;
}