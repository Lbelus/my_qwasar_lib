#include "../../include/main_header.h"

// check if file is present within archive and map it out;
void check_file_arr(my_getopt_t* getopt_ptr, my_tar_struct* tar_s)
{
    int index = 1, jndex = 0;
    bool state;
    while (index < getopt_ptr->nbr_str)
    {
        state = true;
        while (jndex < tar_s->nbr_str - 1)
        {
            if (my_strcmp(getopt_ptr->path_arr[index], tar_s->str_arr[jndex]) == 0)
            {
                state = false;
            }
            jndex++;
        }
        jndex = 0;
            getopt_ptr->state[index] = state;

        index += 1;
    }
}