#include "../../include/main_header.h"

int read_archive02(int fd)
{
    int byte_count = 0, size_file = 0, result = 0;
    ph_t* ph;
    do
    {
        ph = malloc(sizeof(ph_t));
        byte_count += read_header(fd, ph);
        size_file = my_ctoi(ph->size, my_strlen(ph->size));
        size_file = oct_to_dec(size_file);
        free(ph);
        result = read_to_pos(fd, size_file);
        byte_count += result ;
    }
    while (result > 0);
    
    return byte_count;
}