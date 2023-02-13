#include <stdio.h>
#include "mymalloc.h"

int main()
{
    // allocate memory for an integer
    int *i = (int *)MyMalloc(sizeof(int));
    float *j = (float *)MyMalloc(sizeof(float));
    *i = 7;
    *j = 10.5;

    printf("%d\n", *i);
    printf("%f\n", *j);

    // free the allocated memory
    MyFree(i);
    MyFree(j);

    return 0;
}