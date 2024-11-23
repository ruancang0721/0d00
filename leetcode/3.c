#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char s[]="abcabcbb";
    int len=lengthOfLongestSubstring(s);
    printf("%d",len);
}

int lengthOfLongestSubstring(char* s)
 {
   
           int lenlen=strlen(s);
           int max=0;
           
           for(int i=0;i<lenlen;i++)
           {
            int count=1;
            if(i==lenlen-1)
            {
              max=max>1?max:1;
              continue;
            }
            if(s[i]==s[i+1])
            {
               max=max>1?max:1;
               continue;

            }
            for(int j=i+1;j<lenlen;j++)
            {
              if(s[i]==s[j])
              {
                break;
              }
              count++;
            }
              max=max>count?max:count;
           }
        
    return max;
}