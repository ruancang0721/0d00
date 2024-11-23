bool isPalindrome(int x) {
    if(x<0)
    return false;
    int n=x;
    long int sum=0;
    while(n!=0)
    {
    sum= sum*10+n%10;
        n/=10;
    }
    if(x==sum)
    return true;
    else
    return false;
     
    
}