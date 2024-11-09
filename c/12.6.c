#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define count 1000
#define shili 10
void Q()
{
    int arr[shili+1]={0};
   for(int i=0;i<count;i++)
   {
     int num = rand()%10+1;
     arr[num]++;
   }
   for(int i=1;i<=shili;i++)
   printf("%d ",arr[i]);
}

int main() 
{
   srand(time(NULL));
   Q();
    return 0;
}