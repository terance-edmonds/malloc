#include <stdio.h>
#include "mymalloc.h"

int main()
{
    int *i = (int *)MyMalloc(4);
    *i = 7;

    printf("%d", *i);

    return 0;
}