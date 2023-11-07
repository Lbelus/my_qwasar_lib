#include <main_header.h>

node_t* create_new_block(char* bid, char* prev_bid)
{
    node_t* result = malloc(sizeof(node_t));
    my_strcpy(result->prev_bid, prev_bid);
    my_strcpy(result->bid, bid);
    result->next = NULL;
    result->head = NULL;
    return result;
}