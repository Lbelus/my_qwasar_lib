#include <main_header.h>

int error_rm_block(node_t* head, my_getopt_t* getopt_ptr)
{
    if (is_block_on_network(head, getopt_ptr->path_arr[2]) == false)
    {
        write(STDERR_FILENO, BLOCK_DNT_EXIST, BLOCK_DNT_EXIST_LEN);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
