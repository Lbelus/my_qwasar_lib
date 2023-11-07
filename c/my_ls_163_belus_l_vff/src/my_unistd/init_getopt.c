#include "../../include/main_header.h"

void init_getopt(my_getopt_t* getopt_ptr)
{
    getopt_ptr->boll_arr = malloc(sizeof(bool) * my_strlen(VALID_ARG));
    fill_bool_array(getopt_ptr->boll_arr, my_strlen(VALID_ARG));
    getopt_ptr->boll_arr[0] = 1;
    getopt_ptr->count_str = 0;
    getcwd(getopt_ptr->home, sizeof(getopt_ptr->home));
}