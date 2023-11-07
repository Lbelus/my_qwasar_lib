#include "../../include/main_header.h"

// set archive fd, get archive size without blocks, perfom mapping of content

int set_fd_pos_u(int archive_fd, node_t* m_head, my_getopt_t *getopt_ptr, my_tar_struct* tar_s)
{
    int size_fd = 0, block_count = 0, byte_count = 0;

    int tmp_fd = open(getopt_ptr->path_arr[0], getopt_ptr->oflag , 0644);
//------------------------
    int archive_blck_size = 0;

    archive_blck_size = get_archive_size(m_head, getopt_ptr);
    init_tar_map(tar_s, archive_blck_size);
//------------------------
    byte_count = read_archive03(tmp_fd, tar_s);

    tar_s->str_arr = malloc(sizeof(char*)*tar_s->nbr_str);
    tar_s->mtim_arr = malloc(sizeof(char*)*tar_s->nbr_str); 
    tar_s->index = 0;

    map_archive(archive_fd, byte_count - BLOCKSIZE, tar_s);
    check_file_arr(getopt_ptr, tar_s);

    if (size_fd % BLOCKSIZE == 0)
    {
        byte_count += BLOCKSIZE;
    }

    block_count = byte_count / BLOCKSIZE;
    close(tmp_fd);
    return block_count;
}