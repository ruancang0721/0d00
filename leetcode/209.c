int minSubArrayLen(int target, int* nums, int numsSize) {
    int i=0,j=0,sum=0,len=j-i+1,minlen=INT_MAX;
    for(;j<numsSize;j++)
    {
       sum+=nums[j];
       while(sum>=target)
       {
        len=j-i+1;
       minlen=minlen<=len?minlen:len;
        sum-=nums[i++];
       }

    }
return minlen==INT_MAX?0:minlen;
}