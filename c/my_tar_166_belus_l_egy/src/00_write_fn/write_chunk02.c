#include "../../include/main_header.h"
#include <stdio.h>

int write_chunk02(int fd, int archive_fd, char* buff, int block_size, int file_size)
{
    int byte_count = 0, initial_size = 0; 
    while (byte_count < file_size 
    && (initial_size = read(archive_fd, buff, block_size)))
    {
        if (fd == -1)
        {
            byte_count += initial_size;
        }
        else
        {
            byte_count += write(fd, buff, initial_size);
        }
        if (file_size > BLOCKSIZE && file_size - byte_count < BLOCKSIZE)
        {
            block_size = file_size - byte_count;
        }
    }
    return byte_count;
}
