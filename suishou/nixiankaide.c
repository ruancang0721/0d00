#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <wait.h>
int main(int argc, char const *argv[])
{

pid_t wpid,pid ;
int i;
for(i=0;i<5;i++)
{
  pid = fork();
  if(pid==0)
  {
       break;
  }
}
if(5==i)
{
    while((wpid = waitpid(-1,NULL,WNOHANG))!=-1)
    {
      if(wpid >0)
      {
        printf("wait child %d\n",wpid);
      }
      else if(wpid == 0)
      {
        sleep(1);
      }
    }



}
else
{
  sleep(i);
  printf(" woshizijincheng %d\n",getpid());
}

    return 0;
}