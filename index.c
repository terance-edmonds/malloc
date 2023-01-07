#include <stdio.h>
#include "mymalloc.h"

int main()
{
    // allocate memory for an integer
    int *i = (int *)MyMalloc(4);
    *i = 7;

    printf("%d", *i);

    // free the allocated memory
    MyFree(i);

    return 0;
}