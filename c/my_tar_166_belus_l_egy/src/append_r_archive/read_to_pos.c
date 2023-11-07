#include "../../include/main_header.h"
// read chunk of archive

int read_to_pos(int archive_fd, int size_read) //potential unused arguments need to make a new function; 
{
    int byte_count = 0, block_size = BLOCKSIZE;
    char buff[size_read];
    char burn[BLOCKSIZE - (size_read % BLOCKSIZE)];
    block_size = define_block_size(size_read);
    byte_count = read_chunk02(archive_fd, buff, block_size, size_read);
    if (size_read % BLOCKSIZE != 0)
    {
        byte_count += read(archive_fd, burn, BLOCKSIZE - (size_read % BLOCKSIZE));
    }

    return byte_count;
}
