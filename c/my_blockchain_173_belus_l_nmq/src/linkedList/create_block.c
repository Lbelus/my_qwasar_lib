#include <main_header.h>

node_t* create_block(node_t* head, int nid, char* bid)
{
    node_t* tmp = head;
    node_t* tmp_block = NULL;
    while (tmp != NULL)
    {
        if (tmp->index == nid)
        {
            tmp_block = create_new_block(bid, head->prev_bid);
            tmp->head = insert_at_head(&tmp->head, tmp_block);
        }
        tmp = tmp->next;
    }
    return head;
}