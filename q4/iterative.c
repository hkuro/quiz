#include<stdio.h>

int maxSubArray_iterative(int A[],int n)
{
    int i, max_so_far = 0,max_ending_here = 0;
    for(i=0 ; i<n ; i++) {
        max_ending_here += A[i];
        if(max_ending_here < 0) {
            max_ending_here = 0;
        } 
        if(max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
        }
    }
    return(max_so_far);
}