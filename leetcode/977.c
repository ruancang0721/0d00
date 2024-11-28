int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int i=0,j=numsSize-1;
    *returnSize=numsSize;
    int* arr = (int*)malloc(sizeof(int)*numsSize);
    int k = numsSize-1;
    for(;i<=j;)
    {
         if(nums[i]*nums[i]>nums[j]*nums[j])
         {
            arr[k--]=nums[i]*nums[i];
            i++;
         }
         else
         {
            arr[k--]=nums[j]*nums[j];
            j--;
         }
    }
   
   return arr;
}