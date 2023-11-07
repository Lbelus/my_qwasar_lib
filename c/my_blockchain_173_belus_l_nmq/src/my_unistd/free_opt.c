#include <main_header.h>

void free_opt(int argc, char** argv, my_getopt_t* getopt_ptr)
{
    dynamic_free(argc, argv, getopt_ptr);
    if (getopt_ptr->nbr_str > 0)
    {
        free(getopt_ptr->path_arr);
    }
    free(getopt_ptr->bool_arr);;
    free(getopt_ptr);
}