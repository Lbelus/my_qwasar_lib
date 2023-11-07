#include <main_header.h>

cell_t* memory_pool;
cell_t* free_list;

void init_memory_pool(int pool_size)
{
    memory_pool = (cell_t*)malloc(pool_size * sizeof(cell_t));
    if (!memory_pool) {
        write(STDERR_FILENO, MEM_POOL_ALLOC, SIZE_MSG_ALLOC);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < pool_size - 1; i++) {
        memory_pool[i].next = &memory_pool[i + 1];
    }
    memory_pool[pool_size - 1].next = NULL;

    free_list = &memory_pool[0];
}

cell_t* allocate_cell()
{
    if (!free_list) {
        write(STDERR_FILENO, MEM_POOL_SPACE, SIZE_MSG_SPACE);
        return NULL;
    }

    cell_t* cell = free_list;
    free_list = free_list->next;
    return cell;
}

void destroy_memory_pool()
{
    free(memory_pool);
}
