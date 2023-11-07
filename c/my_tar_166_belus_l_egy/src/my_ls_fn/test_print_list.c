#include "../../include/main_header.h"
//#include "../../include/my_stdio.h"
#include <stdio.h>

void test_print_list(node_t* head, bool* flags)
{
    (void)flags;
    node_t* tmp = head;
    // int state = false;

    while (tmp != NULL)
    {
        // if (flags[1] == false && tmp->path_name[0] == '.')
        // {
        //     state = false;
        // }
        // else
        // {
        //     state = true;
        // }
        // if (state && (head->st.st_mode & S_IFMT) == S_IFDIR)
        // {
        //     printf("%s\n", tmp->path_name);
        // }

        // if (state && (head->st.st_mode & S_IFMT) == S_IFREG)
        // {
        //     printf("%s\n", tmp->path_name);
        // }
        free(tmp->path_name);
        tmp = tmp->next;
    }
}