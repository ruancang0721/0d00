#include <stdio.h>
#include<string.h>
int zhuanhuan(char QAQ[100])
{
 int sum=0;
 int xiang;
   int len =strlen(QAQ);
   int count=0;
   int qwq=1;
   for(int i=len-1;i>=0;i--)
   {
    if (QAQ[i]!='0' && QAQ[i]!='1')
    {
        printf("不是二进制\n");
        return -1;
    }
    
     xiang = (QAQ[i]-'0')*qwq;
     count++;
     qwq*=2;
     sum+=xiang;
   }
return sum;
}
int main() 
{
    printf("请输入二进制字符串\n");
    char QAQ[100];
    scanf("%s",QAQ);
    int num = zhuanhuan(QAQ);
    if(num!=-1)
    {
    printf("转换后为%d",num);
    }
    return 0;
}