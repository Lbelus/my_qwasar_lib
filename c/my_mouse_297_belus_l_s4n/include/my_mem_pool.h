#ifndef __MY_MEM_POOL_HEADER_
#define __MY_MEM_POOL_HEADER_

#include <main_header.h>

void    init_memory_pool(int pool_size);
cell_t* allocate_cell();
void    destroy_memory_pool();

#endif