#include "../../include/main_header.h"
//set fd to desired position

int set_fd_pos(int archive_fd, my_getopt_t *getopt_ptr)
{
    int block_count = 0, byte_count = 0;
    int tmp_fd = open(getopt_ptr->path_arr[0], getopt_ptr->oflag , 0644);
    byte_count += read_archive02(tmp_fd);
    close(tmp_fd);
    read_to_pos(archive_fd, byte_count - BLOCKSIZE);
    byte_count -= BLOCKSIZE;
    block_count = byte_count / BLOCKSIZE;
    return block_count;
}