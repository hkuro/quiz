#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<string.h>

static double diff_in_second(struct timespec t1, struct timespec t2)
{
	struct timespec diff;
	if (t2.tv_nsec-t1.tv_nsec < 0) {
		diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
		diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
	} else {
		diff.tv_sec  = t2.tv_sec - t1.tv_sec;
		diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
	}
	return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}

int main()
{
	char line[64],*str;
	int A[]= {-2,1,-3,4,-1,2,1,-5,4}, n, result;
	struct timespec start,end;
	double cpu_time;

	n = (sizeof(A)/sizeof(A[0]));

#if defined(RECUR)
	clock_gettime(CLOCK_REALTIME, &start);
	result = maxSubArray_recursive(A,n);
	clock_gettime(CLOCK_REALTIME, &end);
	cpu_time = diff_in_second(start,end);

	printf("Result = [ %d ]\n",result);
	printf("Execution time of recursive() %.10lf sec\n",cpu_time);
#endif

#if defined(ITER)
	clock_gettime(CLOCK_REALTIME, &start);
	result = maxSubArray_iterative(A,n);
	clock_gettime(CLOCK_REALTIME, &end);
	cpu_time = diff_in_second(start,end);

	printf("Result = [ %d ]\n",result);
	printf("Execution time of iterative() %.10lf sec\n",cpu_time);
#endif

	return 0;
}
