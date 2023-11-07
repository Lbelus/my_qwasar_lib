#include <main_header.h>

void* calloc(size_t num, size_t size)
{
    void* ptr = malloc(num * size);
    
    if (ptr == NULL)
    {
        return NULL;
    }
    
    _my_memset(ptr, 0, num * size);

    return ptr;
}