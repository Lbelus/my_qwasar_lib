#include "../../include/main_header.h"

int read_chunk03(int fd, char* buff, int block_size, int size_file, my_tar_struct* tar_s)
{
    int byte_count = 0, index = 0;
    ph_t* ph;
    while (byte_count < size_file)
    {
        if (tar_s->tar_map[tar_s->index] == 1)
        {
            ph = malloc(sizeof(ph_t));
            read_header(fd, ph);
            byte_count += BLOCKSIZE;
            store_filenames(tar_s, ph->name, ph->mtime, index);
            index +=  1;
            free(ph);
        }
        else
        {
            byte_count += read(fd, buff, block_size);
        }

        if (size_file > BLOCKSIZE && size_file - byte_count < BLOCKSIZE)
        {
            block_size = size_file - byte_count;
        }
        tar_s->index += 1;
    }
    return byte_count;
}