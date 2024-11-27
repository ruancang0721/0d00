int search(int* nums, int numsSize, int target) {
    int left=0,right=numsSize-1;
    int middle;
    while(left<=right)
    {
        middle=(left+right)/2; 
           if(nums[middle]>target)
        {
            right = middle-1;
        }
        else if(nums[middle]<target)
        {
            left = middle+1;
        }
        else
        return middle;
    }
    return -1;
}