#include "../../include/main_header.h"

int write_chunk(int fd, int archive_fd, char* buff, int block_size)
{
    int initial_size = 0, byte_count = 0;
    while ((initial_size = read(fd, buff, block_size)))
    {
        byte_count += write(archive_fd, buff, initial_size);
    }

    return byte_count;
}