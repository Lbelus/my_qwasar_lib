#include "../../include/main_header.h"

void n_state(char opt, my_getopt_t *getopt_ptr, char** argv)
{
    switch (opt)
    {
    case '1':
        getopt_ptr->boll_arr[0] = true;
    break;
    case 'a':
        getopt_ptr->boll_arr[1] = true;
    break;
    case 't':
        getopt_ptr->boll_arr[2] = true;
    break;
    case ':':
        my_strcpy(getopt_ptr->path_arr[getopt_ptr->path_pos], argv[getopt_ptr->optindex]); 
        getopt_ptr->path_pos += 1;
        getopt_ptr->optindex += 1;
    break;
    default /*?*/:
        //getopt_ptr->optindex += 1;
        break;
    }
    opt = 0;
}