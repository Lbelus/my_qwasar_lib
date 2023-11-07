#include "../../include/main_header.h"
#include <stdio.h>
void command_center(my_getopt_t* getopt_ptr, node_t* m_head)
{
    //clean_llist(m_head, getopt_ptr); // temporarily disabled need to relocated inside ls functions


    if (getopt_ptr->bool_arr[0] == 0)
    {
            //if(false) then error message + exit program. 
    }

    if (getopt_ptr->bool_arr[1] == 1) //-cf
    {
        getopt_ptr->oflag = O_RDWR | O_CREAT;
        files_to_archive(getopt_ptr, m_head);
    }

    if (getopt_ptr->bool_arr[2] == 1)  //-rf
    {
        getopt_ptr->oflag = O_RDWR | O_CREAT ; // | O_APPEND | O_TRUNC
        files_to_archive(getopt_ptr, m_head);
    }

    if (getopt_ptr->bool_arr[3] == 1) //-xf
    {
        archive_to_file(getopt_ptr);
    }

    if (getopt_ptr->bool_arr[4] == 1) //-uf
    {
        getopt_ptr->state = malloc(sizeof(bool) * getopt_ptr->nbr_str);
        fill_bool_array(getopt_ptr->state, getopt_ptr->nbr_str);
        getopt_ptr->oflag = O_RDWR | O_CREAT ; // | O_APPEND | O_TRUNC
        files_to_archive_u(getopt_ptr, m_head);
        free(getopt_ptr->state);
    }

    if (getopt_ptr->bool_arr[5] == 1) //-tf
    {
        getopt_ptr->oflag = O_RDWR | O_CREAT;
        archive_to_file(getopt_ptr);
    }
}