#include <main_header.h>

node_t* sync_nodes(node_t* head)
{
    node_t* tmp_n_a = head;
    node_t* tmp_n_b = head;
    node_t* tmp_b = NULL;
    node_t* tmp_cpy = NULL;
    write(STDOUT_FILENO, OK, OK_SIZE);
    while (tmp_n_a != NULL)
    {
        tmp_n_b = head;
        while (tmp_n_b != NULL)
        {
            tmp_b = tmp_n_a->head;
            // printf("working on node: %i with info from node %i \n", tmp_n_b->nid, tmp_n_a->nid); insert next condition if tmp_n_a == tmp_n_b
            while (tmp_b != NULL)
            {
                if (is_block_on_chain(tmp_n_b->head, tmp_b) == false)
                {
                // printf("block on chain check : %i against node %i\n", tmp_b->bid, tmp_n_b->nid);
                    tmp_cpy = create_cpy_block(tmp_b);
                   tmp_n_b->head = insert_after_node(tmp_n_b->head, tmp_cpy);
                    // tmp_n_b->head = insert_at_head(&tmp_n_b->head, tmp_cpy);
                }
                tmp_b = tmp_b->next;
            }
            tmp_n_b = tmp_n_b->next;
        }
        tmp_n_a = tmp_n_a->next;
    }
    // sort_bid(head); // commmented because fn goes against gandalf test. 
    return head;
}

int diff_block_02(node_t* head)
{
    node_t* tmp_n_a = head;
    node_t* tmp_n_b = head;
    node_t* tmp_b = NULL;
    int count = 0;
    while (tmp_n_a != NULL)
    {
        tmp_n_b = head;
        while (tmp_n_b != NULL)
        {
            tmp_b = tmp_n_a->head;
            // printf("working on node: %i with info from node %i \n", tmp_n_b->nid, tmp_n_a->nid); insert next condition if tmp_n_a == tmp_n_b
            while (tmp_b != NULL)
            {
                if (!is_block_on_chain(tmp_n_b->head, tmp_b))
                {
                    count = node_count(head);
                    return count;
                // printf("block on chain check : %i against node %i\n", tmp_b->bid, tmp_n_b->nid);
                }
                tmp_b = tmp_b->next;
            }
            tmp_n_b = tmp_n_b->next;
        }
        tmp_n_a = tmp_n_a->next;
    }
    return count;
}