#include "../../include/main_header.h"

void sort_str_arr(my_getopt_t *getopt_ptr)
{
    int index = 0, jndex = 0;
    char* tmp = NULL;
    while (index  < getopt_ptr->nbr_str -1)
    {
        while (getopt_ptr->path_arr[index][jndex] != '\0' )
        {
            if (my_strcmp(getopt_ptr->path_arr[index], getopt_ptr->path_arr[index + 1]) > 0)
            {
                tmp = getopt_ptr->path_arr[index + 1];
                getopt_ptr->path_arr[index + 1] = getopt_ptr->path_arr[index]; 
                getopt_ptr->path_arr[index] = tmp;
            }
            jndex += 1;    
        }
        index += 1;
    }
}