/* Malloc and Free function implementation */

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
static char mem[MEMORY_SIZE];

/* starting block pointer */
struct block *init = NULL;

/* functions */
static int is_free(struct block *, size_t);

void *MyMalloc(size_t size)
{
    /* check if starting block is empty */
    /* if empty allocate memory to start */
    if (init == NULL)
    {
        /* assign the start memory address and allocate the initiate memory block */
        init = mem;
        init->size = MEMORY_SIZE - BLOCK_SIZE;
        init->free = 1;
        init->next = NULL;
    }

    struct block *ptr = init;
    size_t _size = size + BLOCK_SIZE; // total required memory size

    /* find the last block pointer */
    while (ptr != NULL)
    {
        /* check if the block is free and has the required memory space  */
        if (is_free(ptr, size))
        {
            size_t available_size = ptr->size;

            /* allocate the required memory + block size and set the memory to free */
            ptr->size = _size;
            ptr->free = 0;

            /* create a free block for the remaining memory space */
            struct block *next = NULL;

            if (available_size - _size > 0)
            {
                next = ptr + _size;
                next->size = available_size - _size;
                next->free = 1;
                next->next = NULL;
            }

            /* link the current block pointer with the next free memory block */
            ptr->next = next;
        }

        ptr = ptr->next;
    }

    /* if there are no memory block with enough memory spaced it will return NULL */
    return NULL;
}

void MyFree(struct block *ptr)
{
    /* if the block pointer is null do nothing */
    if (ptr == NULL)
        return;

    /* set the block pointer as free */
    ptr->free = 1;

    /* check if the block next to it is free and merge them if so */
    struct block *next = ptr->next;

    /* merge the current block and next block */
    if (next != NULL && next->size > 0)
    {
        ptr->size += BLOCK_SIZE + next->size; // (size of the current block + size of the free block)
        ptr->next = next->next;               // link the two blocks
    }
}

/* check if free and has enough space functions */
int is_free(struct block *ptr, size_t size)
{
    return ptr->free && ptr->size >= size;
}