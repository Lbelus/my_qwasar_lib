#include <main_header.h>

bool is_block_on_chain(node_t* block_head, node_t* block)
{
    node_t* tmp = block_head;

    while (tmp != NULL)
    {
        if (my_strcmp(block->bid, tmp->bid) == 0)
        {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

bool is_block_on_chain_02(node_t* head, int nid, char* bid)
{
    node_t* tmp_node = head;
    while (tmp_node->nid != nid && tmp_node != NULL)
    {
        tmp_node = tmp_node->next;
    }
    node_t* tmp = tmp_node->head;
    while (tmp != NULL)
    {
        if (my_strcmp(bid, tmp->bid) == 0)
        {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

bool check_bid(node_t* block_head, char* bid)
{
    node_t* tmp = block_head;
    while (tmp != NULL)
    {
        if (my_strcmp(bid, tmp->bid) == 0)
        {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

bool is_node_on_network(node_t* node_head, int nid)
{
    node_t* tmp = node_head;

    while (tmp != NULL)
    {
        if (nid == tmp->nid)
        {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

bool is_block_on_network(node_t* node_head, char* bid)
{
    node_t* tmp = node_head;
    bool result = false;

    while (tmp != NULL)
    {
        result = check_bid(tmp->head, bid);
        if (result == true)
        {
            return result;
        }
        tmp = tmp->next;
    }
    return result;
}

bool is_block_on_node(node_t* node_head, int nid, char* bid)
{
    node_t* tmp = node_head;

    while (tmp != NULL)
    {
        if (nid == tmp->nid)
        {
            return check_bid(tmp->head, bid);
        }
        tmp = tmp->next;
    }
    return false;
}