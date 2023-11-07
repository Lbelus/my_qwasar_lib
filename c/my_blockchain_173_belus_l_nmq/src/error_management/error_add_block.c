#include <main_header.h>

int error_add_block(node_t* head, my_getopt_t* getopt_ptr)
{
    if (getopt_ptr->path_arr[3][0] == __STAR_CHAR__)
    {
        return EXIT_SUCCESS;
    }
    int nid = my_ctoi(getopt_ptr->path_arr[3], my_strlen(getopt_ptr->path_arr[3]));
    if (is_node_on_network(head, nid) == false)
    {
        write(STDERR_FILENO, NODE_DNT_EXIST, NODE_DNT_EXIST_LEN);
        return EXIT_FAILURE;
    }
    if (is_block_on_chain_02(head, nid, getopt_ptr->path_arr[2]))
    {
        write(STDERR_FILENO,BLOCK_EXIST_ERROR, BLOCK_EXIST_ERROR_LEN);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}