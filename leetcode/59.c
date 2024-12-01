int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
        *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    int m =n*n;
    int** arr = (int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++)
    {
        arr[i]=(int*)malloc(sizeof(int)*n);
        (*returnColumnSizes)[i] = n;
    }
    int count=1;
    int i=0,j=0;
   for(int o=0;o<n/2;o++)
   {
      for(;j<n-1-o;j++)
      {
        arr[i][j]=count++;
      }
      for(;i<n-1-o;i++)
      {
        arr[i][j]=count++;
      }
      for(;j>0+o;j--)
      {
        arr[i][j]=count++;
      }
      for(;i>0+o;i--)
      {
        arr[i][j]=count++;
      }
      i++,j++;
   }
   if(n%2==1)
   {
    arr[n/2][n/2]=count;
   }
   return arr;
    
}