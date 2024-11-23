double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int Left, Right, i = 0, j = 0, i1 = nums1Size - 1, j1 = nums2Size - 1;
    double median;

    do 
    {
        if (i < nums1Size && (j >= nums2Size || nums1[i] <= nums2[j])) {  
            Left = nums1[i++];
        } else {
            Left = nums2[j++];
        }

        if (i1 >= 0 && (j1 < 0 || nums1[i1] >= nums2[j1])) 
        {    
              Right = nums1[i1--];
        } else {
            Right = nums2[j1--];
        }
    } while ((i <= i1 || j <= j1) && Left < Right);

    median = (double)(Left + Right) / 2.0;
    return median;
}