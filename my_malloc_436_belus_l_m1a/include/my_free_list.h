#ifndef __MY_FREE_LIST_HEADER_
#define __MY_FREE_LIST_HEADER_

#include <main_header.h>

void init_memory_segment(void* mem_seg, size_t elem_cnt);
intree_t* allocate_node();

#endif