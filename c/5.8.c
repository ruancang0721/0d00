#include<stdio.h>
int main()
{
    int a=0,b=0;
    printf("This program computes modduli.\n");
    printf("Enter an integer to serve as the second operand: ");
    scanf("%d",&b);
    printf("Now enter the first openrand: ");
    scanf("%d",&a);
    printf("%d %% %d is %d\n",a,b,a%b);
    while(1)
    {
        printf("Enter next number for first operand (<= 0 to quit): ");
        scanf("%d",&a);
        if(a<=0) 
        {
            printf("Done\n");
            break;
        }
        printf("%d %% %d is %d\n",a,b,a%b);
    }
    return 0;
}