#include "../../include/main_header.h"

void tar_map_file(int byte_count, my_tar_struct* tar_s)
{
    while (byte_count > 0)
    {
        tar_s->tar_map[tar_s->index] = 2;
        tar_s->index += 1;
        byte_count -= BLOCKSIZE;
    }
}