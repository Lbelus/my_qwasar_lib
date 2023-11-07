#include "../../include/main_header.h"

int read_archive03(int fd, my_tar_struct* tar_s)
{
    int byte_count = 0, file_size = 0;
    ph_t* ph;
    char *filename = malloc(sizeof(char)*100);
    do
    {
        ph = malloc(sizeof(ph_t));
        read_header(fd, ph);
        file_size = my_ctoi(ph->size, my_strlen(ph->size));
        file_size = oct_to_dec(file_size);
        tar_s->tar_map[tar_s->index] = 1;
        tar_s->index += 1;
        tar_map_file(file_size, tar_s);
        my_strcpy(filename, ph->name);
        tar_s->nbr_str += 1;
        
        byte_count += file_size + file_size % BLOCKSIZE + BLOCKSIZE;
        free(ph);
    }
    while (filename[0] != '\0' && map_archive(fd, file_size, tar_s) > 0);
    
    int index = 0;
    while(index < tar_s->index)
    {
        index++;
    }
    tar_s->tar_state += 1;

    free(filename);

    return byte_count;
}