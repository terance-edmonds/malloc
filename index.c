#include <stdio.h>
#include "mymalloc.h"

int main()
{
    // allocate memory for an integer
    int *i = (int *)MyMalloc(4);
    int *j = (int *)MyMalloc(4);
    *i = 7;
    *j = 10;

    printf("%d\n", *i);
    printf("%d", *j);

    // free the allocated memory
    MyFree(i);

    return 0;
}