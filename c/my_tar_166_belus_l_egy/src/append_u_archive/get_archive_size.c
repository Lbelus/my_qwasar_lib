#include "../../include/main_header.h"
// identify archive size without NULL blocks 

int get_archive_size(node_t* m_head, my_getopt_t* getopt_ptr)
{
    node_t* tmp_m = m_head, * tmp_d = NULL;
    int block_size = 0;

    while (tmp_m != NULL)
    {
        tmp_d = tmp_m->daughter_head;
        while (tmp_d != NULL)
        {
            if (my_strcmp(tmp_d->path_name, getopt_ptr->path_arr[0]) == 0)
            {
                block_size = tmp_d->st.st_size/BLOCKSIZE;
                return block_size;
            }
            tmp_d = tmp_d->next;
        }
        tmp_m = tmp_m->next;
    }
    return 0;
}