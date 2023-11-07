#include <main_header.h>

node_t* insert_at_head(node_t** head, node_t* node_to_insert)
{
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}