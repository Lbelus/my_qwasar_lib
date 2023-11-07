#include "../../include/main_header.h"

node_t* create_new_node(int value, char* path)
{
    node_t* result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    result->daughter_head = NULL;
    result->path_name = path;
    lstat(path, &result->st);
    return result;
}