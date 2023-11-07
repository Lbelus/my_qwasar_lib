#include <main_header.h>

void init_getopt(my_getopt_t* getopt_ptr, char* valid_args)
{
    getopt_ptr->exit_status = false;
    getopt_ptr->bool_arr = malloc(sizeof(bool) * my_strlen(valid_args));
    fill_bool_array(getopt_ptr->bool_arr, my_strlen(valid_args));
    getopt_ptr->nbr_str = 0;
}