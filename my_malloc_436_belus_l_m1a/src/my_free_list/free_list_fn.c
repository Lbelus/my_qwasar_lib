#include <main_header.h>

intree_t* free_chunk = NULL;


/* #################### init_memory_segment ###################
    create a free list that will hold and keep track of pages
    @return (void)
*/
void init_memory_segment(void* mem_seg, size_t elem_cnt)
{
    intree_t* memory_segment = (intree_t*)mem_seg;
    for (int index = 0; index < elem_cnt - 1; index++)
    {
        memory_segment[index].right = &memory_segment[index + 1];
    }
    memory_segment[elem_cnt - 1].right = NULL;

    free_chunk = &memory_segment[0];
}

/* #################### allocate_node ###################
    fetch node and move free_list head forward
    @return (node)
*/
intree_t* allocate_node()
{
    if (!free_chunk)
    {
        return NULL;
    }

    intree_t* node = free_chunk;
    free_chunk = free_chunk->right;
    return node;
}