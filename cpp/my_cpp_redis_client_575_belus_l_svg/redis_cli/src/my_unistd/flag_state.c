#include <my_unistd.h>

void flag_state(char opt, my_getopt_t *getopt_ptr, char** argv)
{
    switch (opt)
    {
    case 'l':
        getopt_ptr->bool_arr[0] = true;       
    break;
    case ':':
        _my_strcpy(getopt_ptr->str_arr[getopt_ptr->str_pos], argv[getopt_ptr->index]);
        getopt_ptr->str_pos += 1;
        getopt_ptr->index += 1;
    break;
    default /*?*/:
        //getopt_ptr->index += 1;
        break;
    }
    opt = 0;
}
