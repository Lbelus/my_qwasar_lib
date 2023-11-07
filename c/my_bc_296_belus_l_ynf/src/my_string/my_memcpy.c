#include <main_header.h>

void* my_memcpy(void* dest, void* src, int len)
{
    int index = 0;
    char *arr_d = dest;
    char *arr_s = src;
    while (index < len)
    {
        arr_d[index] = arr_s[index];
        index +=1;
    }
    return dest;
}