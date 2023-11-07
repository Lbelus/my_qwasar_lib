#include "../../include/main_header.h"

int define_block_size(int size_fd)
{
    if (size_fd < BLOCKSIZE)
    {
        return size_fd; 
    }
    else
    {
        return BLOCKSIZE;
    }
}