#include <stdio.h>
int is_within(char a,char *b)
{
   while(*b)
   {
    if(*b==a)
    return 1;
    b++;
   }
   return 0;
}

int main() 
{
    char a='a';
    char  *b ="ruancang";
    is_within(a,b);
    printf("%d",is_within(a,b));
    return 0;
}