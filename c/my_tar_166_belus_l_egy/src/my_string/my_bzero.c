#include <stddef.h>
// void* p ; generic pointer type. can be converted to any type without "explicit" cast,  // size_t is for array indexing and loop counting
// generic pointers cannot be dereferenced, must convert to a pointer before using it.

void my_bzero(void *generic_ptr, size_t n) 
{   
    char *arr = generic_ptr;  
    size_t i;
    
    for (i = 0; i < n; ++i)
    {
        arr[i] = '\0';
    }
}