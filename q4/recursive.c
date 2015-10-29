#include<stdio.h>
#include<stdlib.h>

int max_2(int a,int b)
{
    return((a>b)?a:b);
}
int max_3(int a,int b,int c)
{
    return(max_2(max_2(a,b),c));
}
int getCrossMax(int A[],int start,int mid,int end)
{
    int leftMax = A[mid], leftSum = 0;
    int rightMax = A[mid+1], rightSum = 0;
    for(int i =mid; i>=start ; --i) {
        leftSum += A[i];
        if(leftSum > leftMax) {
            leftMax = leftSum;
        }
    }
    for(int i =mid+1; i<=end; ++i) {
        rightSum += A[i];
        if(rightSum > rightMax) {
            rightMax = rightSum;
        }
    }
    int getCrossMaxRsult = max_2(max_2(leftMax,rightMax), leftMax+rightMax);
    return(getCrossMaxRsult);
}


int getMax(int A[],int start,int end)
{
    if(start==end) {
        return(A[start]);
    }
    int mid =(start+end)/2;
    int leftMax = getMax(A,start,mid);
    int rightMax = getMax(A,mid+1,end);
    
    int crossMax = getCrossMax(A,start,mid,end);

    int getMaxRsult = max_3(leftMax,rightMax,crossMax);
    return(getMaxRsult);
}

int maxSubArray_recursive(int A[],int n)
{
    int result = getMax(A,0,n-1);
    return(result);
}