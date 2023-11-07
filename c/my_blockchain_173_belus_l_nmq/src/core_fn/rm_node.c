#include <main_header.h>

void rm_node(node_t** head, my_getopt_t* getopt_ptr)
{
        int nid = my_ctoi(getopt_ptr->path_arr[2], my_strlen(getopt_ptr->path_arr[2]));
        write(STDOUT_FILENO, OK, OK_SIZE);
        delete_node_on_nid(head, nid);
}