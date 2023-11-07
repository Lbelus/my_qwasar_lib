#include "include/main_header.h"
#include <stdio.h>

int main(int argc, char** argv)
{
    int len = my_strlen(argv[2]) - 4;

    if (my_strcmp(&argv[2][len], ".tar") != 0)
    {
        return 0;
    }

    my_getopt_t* getopt_ptr = malloc(sizeof(my_getopt_t));

    int index = 0;
    node_t *m_head = 0, *head = 0;

    init_getopt(getopt_ptr, VALID_ARG_TAR);
    if (argc > 1)
    {
        flag_parser(argc, argv, VALID_ARG_TAR, getopt_ptr);   
    }

    if (getopt_ptr->bool_arr[1] == 1 || getopt_ptr->bool_arr[2] == 1 || getopt_ptr->bool_arr[4] == 1)
    {

        while(index < getopt_ptr->nbr_str)
        {
            int pos = path_to_name(getopt_ptr->path_arr[index]);
            if(pos > 1)
            {
                swd(getopt_ptr->path_arr[index], pos);
            }
            m_head = get_info(m_head, head, index);
            chdir(getopt_ptr->home);
            index += 1;
        }
    }

    command_center(getopt_ptr, m_head);

    if (getopt_ptr->bool_arr[1] == 1 || getopt_ptr->bool_arr[2] == 1 || getopt_ptr->bool_arr[4] == 1)
    {
        print_and_free_llist(m_head, getopt_ptr);
    }

    free_opt(argc, argv, getopt_ptr);
    return EXIT_SUCCESS;
}