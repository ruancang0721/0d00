#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
int main(int argc, char const *argv[])
{

pid_t wpid,pid ;
int status;


int i=0;


pid = fork();
if(pid ==0)
{
  printf("child,my pid is %d,sleep 10s",getpid());
  sleep(10);
}
else if(pid>0)
{
  wpid = wait(&status);
  if(wpid == -1)
  {
    perror("wait error");
    exit(1);
  }
  printf("parent,my pid is %d,child pid is %d,child status is %d",getpid(),wpid,status);
}
else{
  perror("fork error");
  return 1;
}
    return 0;
}