#include <main_header.h>

int error_add_node(node_t* head, my_getopt_t* getopt_ptr)
{
    int nid = my_ctoi(getopt_ptr->path_arr[2], my_strlen(getopt_ptr->path_arr[2]));
    if (is_node_on_network(head, nid))
    {
        write(STDERR_FILENO, NODE_EXIST_ERROR, NODE_EXIST_ERROR_LEN);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}