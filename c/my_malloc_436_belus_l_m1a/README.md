# Welcome to My Malloc
***

## Task

The task at hand is to implement a memory management system using my own implementation of the malloc, free, calloc, and realloc functions in C. The challenge lies in managing the memory efficiently and avoiding memory leaks, fragmentation, and other common issues associated with dynamic memory allocation

## Description

This project works as a lib and replace your system malloc.

In this implementation, instead of requesting memory from the system every time the user calls my_malloc, we request a large chunk of memory and divide it into smaller parts. When the user calls my_malloc, we return a suitable portion of this memory. This way, we minimize the number of system calls and manage the memory more efficiently.


Memory structure :
```
                     ┌───────────────┐
                     │  mem_handler  │
               ┌─────┴───────────────┴──┐
               │                        │
       ┌───────┴───────┐            ┌───┴───┐
       │ interval_tree │            │ pages │
       └───────┬───────┘            └───┬───┘
               │                        │ (metadata)
     ┌─────────┴───────┐            ┌───┴─────┐
     │ pages_addresses │            │ bitnode │-->bitnode->...
     └─────────────────┘            └───┬─────┘
                                        │
                                    ┌───┴────┐
                                    │ bitmap │
                                    └───┬────┘
                                        │
                                    ┌───┴────────┐
                                    │ tee<->slot │
                                    └────────────┘


```
The interval tree serve as a search tree and will only store the pages addresses (mmap calls) and not the user allocation;
User allocation are stored in a the tee struct which hold an unsigned char to keep track of the number allocated slots and a magic_number to verify the ptr authenticity;

The get_ptr function is used to find a suitable block of memory for the user. The req_memory function is used to request a chunk of memory from the system using mmap and divide it into smaller blocks. The set_page function is used to initialize the memory and the release_mem function is used to free the memory and return it to the system.

The calculation of the position of a returned pointer  is based on an unsigned char placed just before the allocation; the allocation and return of slots rely on this and on a bitmap arranged on each page. The bitmaps are linked in a linked list manner.

For each page:
StartPage|bitmap|data

No matter the multiple of sizepage that the page does, it is always divided according to the bitmap. That is 32bytes*8 = 256 slots. In terms of overhead, it is very reasonable, knowing that within the tree you only store the address of the pages and not the allocations.

So if you return a pointer, it finds the address of the page by itself and makes the slot available.

This design ensures efficient use of memory with minimal overhead, as only the addresses of the pages are stored in the tree, not the allocations.
Returning a pointer automatically makes the corresponding slot available, optimizing memory managemement.

## Installation

This malloc lib can run as a substitute for stdlib.h on malloc, calloc, realloc, free and malloc_usable_size using LD_PRELOAD trick : 

Insert inside the terminal : 
1.
```bash
make
```
2.
```bash
LD_PRELOAD=./libmymalloc.so ls
```
3.
```bash
unset LD_PRELOAD
```
4.
```bash
make fclean
```

/!\ make debug do not produce a usable binary/!\

## Usage

To use the malloc function, simply call it with the size of the block of memory you want to allocate. For example:

```c
#include <main_header.h>

int main(void)
{
    char *ptr = malloc(10);
    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    strcpy(ptr, "Hello");
    printf("%s\n", ptr);
    free(ptr);
    return 0;
}
```

To use the free function, simply call it with a pointer to the block of memory you want to deallocate. For example:
```c
free(ptr); // deallocates the memory pointed to by ptr
```

### The Core Team
* [Lorris BELUS](//github.com/Lbelus) - Developer


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
