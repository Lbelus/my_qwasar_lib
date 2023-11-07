#include "../../include/main_header.h"
#include <stdio.h>

int read_header(int fd, ph_t* ph)
{   
    char burn[12] = {'\0'};
    read(fd, ph, sizeof(ph_t));
    read(fd, burn, 12);
    return BLOCKSIZE;
}