#include<stdio.h>
int main()
{
    int arr[1000000]={0};
    int sum=0;
    for(int i=0;i<1000000;i++)
    {
        scanf("%d",&arr[i]);
     if(arr[i]<=0)
         break;
        if(arr[i]%2!=0)
            sum+=arr[i];
    }
    printf("%d",sum);
    return 0;
}