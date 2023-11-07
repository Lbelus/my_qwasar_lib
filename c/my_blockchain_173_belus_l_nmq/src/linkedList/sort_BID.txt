#include <main_header.h>

void sort_bid(node_t* node)
{
    node_t *tmp = NULL, *next = NULL;
    while (node != NULL)
    {
        tmp = node->head;
        while (tmp != NULL)
        {
            next = tmp;
            while (next != NULL)
            {
                if (tmp->bid == next->prev_bid)
                {
                    //printf("swapping block %i with block %i \n", tmp->bid, next->bid);
                    node->head = swap(node->head, tmp->bid, next->bid);
                    tmp = next;
                }
                next = next->next;
            }
        tmp = tmp->next;
        }
        node = node->next;
    }
}