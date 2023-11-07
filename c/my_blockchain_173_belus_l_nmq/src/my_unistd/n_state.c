#include <main_header.h>

void n_state(char opt, my_getopt_t *getopt_ptr, char** argv)
{
    switch (opt)
    {
    case 'l':
        getopt_ptr->bool_arr[0] = true;       
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

        // printf("n_state.c - path_pos : %i\n", getopt_ptr->path_pos);
        // printf("n_state.c - index    : %i\n", getopt_ptr->index);
        // printf("n_state.c - argv     : %s\n", argv[getopt_ptr->index]);