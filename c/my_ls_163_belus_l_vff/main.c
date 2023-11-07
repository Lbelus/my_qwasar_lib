#include "include/main_header.h"

int main(int argc, char** argv)
{
    int index = 0;
    node_t *m_head = 0, *head = 0;
    my_getopt_t* getopt_ptr = malloc(sizeof(my_getopt_t));
    init_getopt(getopt_ptr);
    if (argc > 1)
    {
        flag_parser(argc, argv, VALID_ARG, getopt_ptr);
    }

    if (getopt_ptr->count_str == 0)
    {
        m_head = get_info(m_head, head, index);
    }
    else
    {
        sort_str_arr(getopt_ptr);
        while (index < getopt_ptr->count_str)
        {
            chdir(getopt_ptr->path_arr[index]);
            m_head = get_info(m_head, head, index);
            index += 1;
            chdir(getopt_ptr->home);
        }
    }
    if (getopt_ptr->boll_arr[2] == true)
    {
        sort_asc(m_head);
    }
    else
    {
        lexi_sort(m_head);
    }
    print_and_free_llist(m_head, getopt_ptr);
    free_opt(argc, argv, getopt_ptr);
    return 0;
}