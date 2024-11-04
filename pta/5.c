#include <stdio.h>
int main()
{
    float s;
    int m;
    scanf("%d",&m);
    if(m<=1600)
     s=0;
    else if(m>1600&&m<=2500)
        s=0.05;
    else if(m>2500&&m<=3500)
        s=0.1;
    else if(m>3500&&m<=4500)
        s=0.15;
    else
        s=0.2;

    printf("%.2f",s*(m-1600));
    return 0;
}