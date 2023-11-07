#include "../../include/main_header.h"

int inter_size(char* str, size_t len)
{
    int size = 0, index = 0;

    while (index < (int)len)
    {
        size += str[index];
        index += 1;
    }
    return size;
}