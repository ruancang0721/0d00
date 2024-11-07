#include<stdio.h>
int main()
{int num =0;

float h=0;
    while(1)
    {
        
       printf("*******************************\n");
       printf("1) $8.75/hr     2) $9.33/hr\n");
       printf("3) $10.00hr     4) $11.20/hr\n");
       printf("5) quit\n");
       printf("*******************************\n");
       printf("请输入一个数字:");
       scanf("%d",&num);
       switch(num)
       {
        case 1:
        h =8.75;
        break;
        case 2:
        h =9.33;
        break;
        case 3: 
        h =10.00;
        break;
        case 4:
        h =11.20;
        break;
        case 5:
        return 0;
        default:
        printf("请输入正确的数字！\n");
        continue;
       }
       printf("%.2f\n",h);
    }
    return 0;
}