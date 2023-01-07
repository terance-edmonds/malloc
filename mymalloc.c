/* Malloc and Free function implementation */
#include <assert.h>

/* import mymalloc.h header file */
#include "mymalloc.h"

/* block that stores malloc data */
struct block
{
    size_t size;        // block size
    int free;           // if block is free or not
    struct block *next; // point to next connected block
};

/* pre defined values */
#define MEMORY_SIZE 25000
#define BLOCK_SIZE sizeof(struct block)

/* global memory pool */
char mem[MEMORY_SIZE];

/* starting block pointer */
struct block *init = NULL;

/* functions */
int is_valid(struct block *ptr, size_t size)
{
    return ptr->free && ptr->size >= size;
}

void *MyMalloc(size_t size)
{
    /* check if starting block is empty */
    /* if empty allocate memory to start */
    if (init == NULL)
    {
        /* check if memory is available */
        assert(MEMORY_SIZE - BLOCK_SIZE > 0);

        init = mem;
        init->size = MEMORY_SIZE;
        init->free = 1;
        init->next = NULL;
    }

    struct block *ptr = init;
    int _size = size + BLOCK_SIZE; // total required memory size

    /* find the last block pointer */
    while (ptr != NULL)
    {
        /* check if the block is free and has the required memory space  */
        if (is_valid(ptr, size))
        {
        }

        ptr = ptr->next;
    }

    return NULL;
}
