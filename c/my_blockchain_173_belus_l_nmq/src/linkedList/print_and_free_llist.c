#include <main_header.h>

void print_and_free_llist(node_t* n_head) //, my_getopt_t *getopt_ptr
{
    int index = 0;
    node_t *tmp = n_head; 
    while (tmp != NULL)
    {
        free_node(tmp->head);
        tmp = tmp->next;
    }
    free_node(n_head);
}