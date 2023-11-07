#include "../../include/main_header.h"

void init_tar_map(my_tar_struct* tar_s, int archive_blck_size)
{
    int index = 0;
    tar_s->tar_map = malloc(sizeof(int) * archive_blck_size);
    tar_s->index = 0;
    tar_s->nbr_str = 0;
    tar_s->tar_state = 0;

    while (index < archive_blck_size - 1)
    {
        tar_s->tar_map[index] = 0; // 0 is null values, 1 is ph, 2 is file content
        index += 1;
    }
}