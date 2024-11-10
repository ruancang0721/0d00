#include <stdio.h>
int bit(int num, int pos)
{
    if(num & (1<<pos))
    return 1;
    else
    return 0;
}
int main() 
{printf("输入整数");
   int num;
   scanf("%d", &num);
   printf("第几位");
   int pos;
   scanf("%d", &pos);
   int result = bit(num,pos);
   printf("%d",result);

    return 0;
}