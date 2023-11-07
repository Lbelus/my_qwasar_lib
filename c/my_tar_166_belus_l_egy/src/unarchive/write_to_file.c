#include "../../include/main_header.h"

//write files from archive to dir

int write_to_file(int archive_fd, int fd, int file_size)
{
    int byte_count = 0, block_size = 0;
    char burn02[BLOCKSIZE - (file_size % BLOCKSIZE)];
    char buff[file_size];

    block_size = define_block_size(file_size);
    byte_count = write_chunk02(fd, archive_fd, buff, block_size, file_size);

    read(archive_fd, burn02, BLOCKSIZE - (file_size % BLOCKSIZE));
    close(fd);

    return byte_count;
}