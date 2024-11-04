#include <stdio.h>

int main()
 {
    int a,b;
    scanf("%d%d",&a,&b);
    float c=0;
    if(a>=5)
    {
        if(b>40)
        {
              c=40*50+50*1.5*(b-40);
        }
        else
        {
             c=50*b;
        }
    }
    else
    {
                if(b>40)
        {
              c=40*30+30*1.5*(b-40);
        }
        else
        {
             c=30*b;
        }
        
    }
    printf("%.2f",c);
return 0;
}