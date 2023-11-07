#include <main_header.h>

void delete_block_on_bid(node_t** head, char* bid)
{
    node_t *tmp = *head;
    node_t *prev;
    if (tmp != NULL && my_strcmp(tmp->bid, bid) == 0)
    {
        *head = tmp->next;
        free(tmp);
        return;
    }
    while (tmp != NULL && my_strcmp(tmp->bid, bid) != 0)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
    {
        return;
    }
    prev->next = tmp->next;
    free(tmp);
}

void delete_block_on_node(node_t* head, char* bid, int nid)
{
    node_t* tmp = head;
    while (tmp != NULL)
    {
        if (tmp->nid == nid)
        {
            return delete_block_on_bid(&head, bid);
        }
        tmp = tmp->next;
    }
}