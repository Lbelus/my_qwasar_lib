#include "../../include/main_header.h"

void end_block(int fd, int block_count)
{
    int count = 0, index = 0;

    while (count * 20 - block_count < 1)
    {
        count += 1;
    }

    count = count * 20 - block_count;
    while (index < count)
    {
        padding_null(fd, 0);
        index += 1;
    }
}