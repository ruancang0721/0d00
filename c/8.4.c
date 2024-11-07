#include <stdio.h>

int main()
{
  int ch;
int count=0;
int in_word =0;

int total_word=0;

  while((ch = getchar())!=EOF)
  {
    if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'))
       {
        count++;
        in_word=1;
       }
       else if(in_word)
       {
         total_word++;
         in_word=0;
       }
  }
  if(in_word)
  {
    total_word++;
  }
  printf("Total words: %.2f\n",count/(float)total_word);

return 0;
}