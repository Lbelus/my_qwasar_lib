#include <main_header.h>

node_t* add_node(node_t* head, my_getopt_t* getopt_ptr)
{
    node_t* tmp = NULL;
    int nid = my_ctoi(getopt_ptr->path_arr[2], my_strlen(getopt_ptr->path_arr[2]));
        write(STDOUT_FILENO, OK, OK_SIZE);
        tmp = create_new_node(nid);
        head = insert_at_head(&head, tmp);
        char buff[SIZE_BID] = {'\0'};
        consensus_check(head, buff);
        my_strcpy(head->prev_bid, buff);
    return head;
}