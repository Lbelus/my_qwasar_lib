#include <main_header.h>

node_t* execute_cmd(my_getopt_t* getopt_ptr, node_t* head)
{

    if (!error_handler(head, getopt_ptr) || getopt_ptr->hash == QUIT)
    {

        switch (getopt_ptr->hash)
        {
        case BLOCK_ADD:
            head = add_block(head, getopt_ptr);
            break;
        case NODE_ADD:
            head = add_node(head, getopt_ptr);
            break;
        case BLOCK_RM:
            rm_block(head, getopt_ptr);
            break;
        case NODE_RM:
            if (getopt_ptr->path_arr[2][0] == __STAR_CHAR__)
            {
                print_and_free_llist(head);
                head = NULL;
            }
            else
            {
                rm_node(&head, getopt_ptr);
            }
            break;
        case LS:
            print_llist_n_n1(head, getopt_ptr->bool_arr[0]);
            break;
        case SYNC:
            sync_nodes(head);
            break;
        case QUIT:
            serialize(head);
            print_and_free_llist(head);
            getopt_ptr->exit_status = true;
            break;
        }    
    }
    return head;
}