#include "../../include/main_header.h"

node_t* insert_after_node(node_t* node_to_insert, node_t* new_node)
{
    if (node_to_insert == NULL)
    {
        node_to_insert = new_node;
        return node_to_insert;
    }
    
    node_t* tmp = node_to_insert;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = new_node;
    return node_to_insert;
}