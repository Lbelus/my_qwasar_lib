#include <main_header.h>

void rm_block(node_t* head, my_getopt_t* getopt_ptr)
{
    node_t* tmp = head;
    int nid = my_ctoi(getopt_ptr->path_arr[3], my_strlen(getopt_ptr->path_arr[3]));
    while (tmp != NULL && tmp->nid != nid)
    {
        tmp = tmp->next;
    }
    write(STDOUT_FILENO, OK, OK_SIZE);
    delete_block_on_bid(&tmp->head, getopt_ptr->path_arr[2]);
}