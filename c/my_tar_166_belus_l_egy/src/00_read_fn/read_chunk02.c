#include "../../include/main_header.h"

//get byte_count for fd

int read_chunk02(int fd, char* buff, int block_size, int file_size)
{
    int byte_count = 0;
    while (byte_count < file_size)
    {
        byte_count += read(fd, buff, block_size);

        if (file_size > BLOCKSIZE && file_size - byte_count < BLOCKSIZE)
        {
            block_size = file_size - byte_count;
        }
    }
    return byte_count;
}