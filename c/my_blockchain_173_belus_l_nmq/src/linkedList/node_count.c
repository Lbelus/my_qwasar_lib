#include <main_header.h>

int node_count(node_t *head)
{
    int count = 0;
    if (head == NULL)
    {
        return count;
    }
    node_t *tmp = head;
    while (tmp != NULL)
    {
        tmp = tmp->next;
        count += 1;
    }
    return count;
}