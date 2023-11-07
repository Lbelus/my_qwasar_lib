#include <main_header.h>

void my_bzero(void *generic_ptr, size_t n)
{ // void* p ; generic pointer type. can be converted to any type without "explicit" cast,  // size_t is for array indexing and loop counting
    char *arr = generic_ptr; // generic pointers cannot be dereferenced, must convert to a pointer before using it. 
    size_t i;
    for (i = 0; i < n; ++i)
    {
        arr[i] = '\0';
    }
}