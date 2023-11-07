#include "../../include/main_header.h"
#include <stdio.h>

int padding_null(int fd, int size) 
{
    char padding[BLOCKSIZE] = {'\0'};
    write(fd, padding, BLOCKSIZE - size);
    return (BLOCKSIZE - size);
}