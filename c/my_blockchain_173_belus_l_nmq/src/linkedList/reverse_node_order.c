#include <main_header.h>

void reverse_node_order(node_t** head)
{
    node_t* prev = NULL;
    node_t* current = *head;
    node_t* next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}