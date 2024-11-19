#include <stdio.h>
#define LIUSHI 60;
int main() 
{
    int a =0;
    int h =0;
    int m=0;
    while(1)
    {
     if(a<=0)
        {
            break;
        }
        scanf("%d",&a);
        h=a/LIUSHI;
        m=a%LIUSHI;
        printf("%02d:%02d\n",h,m);

    }
    return 0;
}