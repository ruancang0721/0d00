#include <stdio.h>
void copy_arr(double target[], double source[], int n)
{
    for(int i=0;i<n;i++)
    {
        target[i]=source[i];
    }
}
void copy_ptr(double *target, double *source, int n)
{
    for(int i=0;i<n;i++)
    *(target+i)=*(source+i);
}
void copy_ptrs(double *target, double *source1, double *source2)
{
   int n = source2-source1;
    for(int i=0;i<n;i++)
    *(target+i)=*(source1+i);
}

int main() 
{
    double source[5]={1.1,2.2,3.3,4.4,5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    copy_arr(target1,source,5);
    copy_ptr(target2,source,5);
    copy_ptrs(target3,source,source+5);
    for(int i=0;i<5;i++)
    {
        printf("source[%d]=%lf\n",i,source[i]);
        printf("target1[%d]=%lf\n",i,target1[i]);
        printf("target2[%d]=%lf\n",i,target2[i]);
        printf("target3[%d]=%lf\n",i,target3[i]);
    }
    return 0;
}