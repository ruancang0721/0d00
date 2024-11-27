int removeElement(int* nums, int numsSize, int val) {
    int fast=0,slow=0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[fast]!=val)
        {
            nums[slow]=nums[fast];
            slow++;
        }
        fast++;
    }
    return slow;
}