#include <main_header.h>

void delete_node_on_nid(node_t **head, int nid)
{
    node_t *tmp = *head;
    node_t *prev;
    if (tmp != NULL && tmp->nid == nid)
    {
        *head = tmp->next;
        free_node(tmp->head);
        free(tmp);
        return;
    }
    while (tmp != NULL && tmp->nid != nid)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
    {
        return;
    }
    prev->next = tmp->next;
    free_node(tmp->head);
    free(tmp);
}