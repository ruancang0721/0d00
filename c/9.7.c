#include <stdio.h>
int f(char ch)
{
            if((ch>='a'&&ch<='z'))
            return ch-'a'+1;
     
        else if(ch>='A'&&ch<='Z')
            return ch-'A'+1;
            else
            return -1;
   
}

int main() 
{
    int ccc;
    int ch;
    while((ch = getchar())!=EOF)
    {
          ccc=f(ch);
          if(ccc!=-1)
          printf("%d ",ccc);
          else
          printf("-1");
    }
    return 0;
}