
int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{

   for(int i=0;i<numsSize;i++)
   {
    for(int j=i+1;j<numsSize;j++)
    {
        if(target == nums[i]+nums[j])
        {
              int *result =(int*) malloc(sizeof(int)*2);
              result[0]=i;
              result[1]=j;
              *returnSize=2;
             return result;
        }
    }
   }
     return NULL;
}