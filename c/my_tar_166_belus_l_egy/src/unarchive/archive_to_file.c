#include "../../include/main_header.h"

// open archive, read and write files to dir

void archive_to_file(my_getopt_t *getopt_ptr)
{
    int archive_fd = 0;

    archive_fd = open(getopt_ptr->path_arr[0], O_RDONLY);

    read_archive(archive_fd, getopt_ptr);
    
    close(archive_fd);
}