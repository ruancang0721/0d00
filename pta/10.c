#include<stdio.h>

int main()
{
    int count=0,c=0;
    char arr[10000]={0};
    for(int i=0;i<10000;i++)
    {
    scanf("%c",&arr[i]);
        if(arr[count]=='.')
            break;
        count++;
        }

    for(int i=0;i<count;i++)
    {
        if(arr[i]!=' ')
        {
            c++;
        }
        if(arr[i]==' ')
        {
            if(c!=0)
                printf("%d ",c);
            c=0;
        }
        
    }
    printf("%d",c);

    return 0;
}