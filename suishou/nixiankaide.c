#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    printf("fork1\n");
    pid_t pid = fork();
    if(pid == -1)
    {
        perror("fork");
        exit(1);
    
    }
    else if(pid == 0)
    {
        printf("child1\n");
    }
    else if(pid > 0)
    {
        printf("parent1\n");
        printf("child1 = %d\n",pid);

    }
    printf("end\n");
    return 0;
}