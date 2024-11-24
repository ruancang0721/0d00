int reverse(int x) {
int sum=0;
while(x!=0)
{
    if((sum>214748364)||(sum<-214748364)) 
    return 0;
    sum= sum*10+x%10;
    x/=10;
}
return sum;
}