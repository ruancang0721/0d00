#include <stdio.h>
void jia(int arr1[],int arr2[],int arr[],int n)
{
     for(int i=0;i<n;i++)
     {
        arr[i]=arr1[i]+arr2[i];
        printf("%d ",arr[i]);
     }
}

int main() 
{
    int arr1[5]={1,2,3,4,5};
    int arr2[5]={6,7,8,9,10};
    int arr[5];
    int n=5;
    jia(arr1,arr2,arr,n);
    return 0;
}