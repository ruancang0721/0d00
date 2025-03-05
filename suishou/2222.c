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
char * myshe_read()
{
 char * line = NULL;
  ssize_t bufsize;
  getline(&line,&bufsize,stdin);
  return line;






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
           free(line);
    }while(status);
}
int main(int argc, char *argv[])
{

mysh_loop();
















    return 0;
    }