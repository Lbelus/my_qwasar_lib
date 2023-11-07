#include "../../include/main_header.h"
// compare time and return 1 if file has been modified

int check_mtime(ph_t* ph, my_tar_struct* tar_s)
{
    int index = 0;
    while (index < tar_s->nbr_str -1)
    {
        if (my_strcmp(ph->name, tar_s->str_arr[index]) == 0)
            {
                int file_mtim = my_ctoi(ph->mtime, my_strlen(ph->mtime));
                int arch_mtim = my_ctoi(tar_s->mtim_arr[index], my_strlen(tar_s->mtim_arr[index]));
                if (file_mtim > arch_mtim)
                {
                    return EXIT_SUCCESS;               
                }
            }
        index += 1;
    }
    return EXIT_FAILURE;
}