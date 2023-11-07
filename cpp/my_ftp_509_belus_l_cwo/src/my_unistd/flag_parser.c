#include <my_unistd.h>

int flag_parser(int argc, char** argv, const char* valid_args, my_getopt_t* getopt_ptr)
{
    int opt             = 0;
    getopt_ptr->index   = 0;
    getopt_ptr->str_pos = 0;
    getopt_ptr->nbr_str = 0;
    count_str_array(argc, argv, getopt_ptr);
    if (getopt_ptr->nbr_str > 0)
    {
        getopt_ptr->str_arr = (char**)malloc(sizeof(char*) * (getopt_ptr->nbr_str));
        dynamic_malloc(argc, argv, getopt_ptr);
    }
    while (getopt_ptr->index < argc)
    {
        if ((opt = my_getopt(argv, valid_args, getopt_ptr)) != - 1)
        {
            flag_state(opt, getopt_ptr, argv);
        }
        opt = 0;
    }
    return 0;
}