#include <main_header.h>

node_t* create_cpy_block(node_t* block)
{
    node_t* result = malloc(sizeof(node_t));
    my_strcpy(result->prev_bid, block->prev_bid);
    my_strcpy(result->bid, block->bid);
    result->index = block->index;
    result->next = NULL;
    result->head = NULL;
    return result;
}