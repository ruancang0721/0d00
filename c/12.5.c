#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void line(int arr[100])
{
   
    for(int i=0;i<99;i++)
    {
        int count=0;
        for(int j=0;j<99-i;j++)
        {
            if(arr[j]<arr[j+1])
            {
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                count=1;
            }
        }
        if(count==0)
            break;
    }
    for(int i=0;i<100;i++)
    printf("%d ",arr[i]);
}


int main() 
{
    int arr[100]={0};
    srand(time(NULL));
    for(int i=0;i<100;i++)
    {
        arr[i]=rand()%10 + 1;
    }
    line(arr);
    return 0;
}