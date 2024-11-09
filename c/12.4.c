#include <stdio.h>
int QAQ()
{
    static int count = 0;
    count++;
    printf("QAQ\n");
    return count;
    }

int main() 
{
     
     int c = 0;
     for(int i=0;i<10;i++)
     {
        c =QAQ();
        printf("%d\n",c);
     }
    return 0;
}