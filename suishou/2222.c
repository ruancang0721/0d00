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
void mysh_loop()
{
    char * line;





    do{


        char path[100];
        getcwd(path,100);
        char now[200] = "[myshell";
        strcat(now,path);
        strcat(now,"]$");
        printf("%s",now);
    }
}
int main(int argc, char *argv[])
{


















    return 0;
    }