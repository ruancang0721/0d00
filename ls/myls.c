#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char * argv[])
{
    struct stat sbuf;
    int ret = stat(argv[1],&sbuf);
    if(ret  == -1)
    {
        perror("stat");
        exit(1);
    }
    printf("%ld",sbuf.st_size);
    return 0;
}
