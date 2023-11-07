#include <main_header.h>

void* realloc(void* ptr, int size)
{
    if (ptr == NULL)
    {
        ptr = malloc(size);
        return ptr;
    }
    if (size == 0)
    {
        free(ptr);
        return NULL;
    }
    void* new_ptr = malloc(size);
    int cpy_size  = malloc_usable_size(ptr);
    my_memcpy(new_ptr, ptr, cpy_size);
    free(ptr);
    return new_ptr;
}