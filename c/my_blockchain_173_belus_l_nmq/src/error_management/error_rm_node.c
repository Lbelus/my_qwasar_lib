#include <main_header.h>

int error_rm_node(node_t** head, my_getopt_t* getopt_ptr)
{
    if (getopt_ptr->path_arr[2][0] == __STAR_CHAR__)
    {
        return EXIT_SUCCESS;
    }
    int nid = my_ctoi(getopt_ptr->path_arr[2], my_strlen(getopt_ptr->path_arr[2]));
    if (is_node_on_network(*head, nid) == false)
    {
        write(STDERR_FILENO, NODE_DNT_EXIST, NODE_DNT_EXIST_LEN);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
