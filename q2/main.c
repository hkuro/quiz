#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

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
    char str[6]="cfjpv";
    char c,result;
    struct timespec start,end;
    double cpu_time;
    int i=0;

    printf("input a character: ");
    scanf(" %c",&c);

#if defined(RECUR)
    clock_gettime(CLOCK_REALTIME, &start);
    result = smallest_character_recursive(str,c);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_second(start,end);
#endif

#if defined(ITER)
    clock_gettime(CLOCK_REALTIME, &start);
    result = smallest_character_iterative(str,c);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_second(start,end);
#endif

#if defined(RECUR)
    printf("Result = [ %c ]\n",result);
    printf("Execution time of q2_recursive() %.10lf sec\n",cpu_time);
    //printf("Total excution time of q2_recursive :%lf secs for %d times\n", total_time,REPEAT_NUM);
#endif

#if defined(ITER)
    printf("Result = [ %c ]\n",result);
    printf("Execution time of q2_Iterative() %.10lf sec\n",cpu_time);
    //printf("Total excution time of q2_iterative :%lf secs for %d times\n", total_time,REPEAT_NUM);
#endif

    return(0);
}
