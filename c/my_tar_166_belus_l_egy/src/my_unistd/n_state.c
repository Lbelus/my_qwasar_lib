#include "../../include/main_header.h"

void n_state(char opt, my_getopt_t *getopt_ptr, char** argv)
{
    switch (opt)
    {
    case 'f':
        getopt_ptr->bool_arr[0] = true;       
    break;
    case 'c':
        getopt_ptr->bool_arr[1] = true;
    break;
    case 'r':
        getopt_ptr->bool_arr[2] = true;
    break;
    case 't':
        getopt_ptr->bool_arr[3] = true;
    break;
    case 'u':
        getopt_ptr->bool_arr[4] = true;
    break;
    case 'x':
        getopt_ptr->bool_arr[5] = true;
    break;
    case ':':
        my_strcpy(getopt_ptr->path_arr[getopt_ptr->path_pos], argv[getopt_ptr->index]);
        getopt_ptr->path_pos += 1;
        getopt_ptr->index += 1;
    break;
    default /*?*/:
        //getopt_ptr->index += 1;
        break;
    }
    opt = 0;
}