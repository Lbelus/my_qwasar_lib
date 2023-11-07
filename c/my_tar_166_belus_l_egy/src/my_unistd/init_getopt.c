#include "../../include/main_header.h"

void init_getopt(my_getopt_t* getopt_ptr, char* valid_args)
{
    getopt_ptr->bool_arr = malloc(sizeof(bool) * my_strlen(valid_args));
    fill_bool_array(getopt_ptr->bool_arr, my_strlen(valid_args));
    getopt_ptr->file_size = malloc(sizeof(int)*100); // dummy
    getopt_ptr->bool_arr[0] = 1;
    getopt_ptr->nbr_str = 0;
    getcwd(getopt_ptr->home, sizeof(getopt_ptr->home));
    //getopt_ptr->oflag = malloc(sizeof(int));
}