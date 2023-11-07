#include "../../include/main_header.h"

// store files names to be appended

void store_filenames(my_tar_struct* tar_s, char* filename, char* mtim, int index)
{
    tar_s->str_arr[index] = malloc(sizeof(char)* my_strlen(filename) + 1);
    my_strcpy(tar_s->str_arr[index], filename);

    tar_s->mtim_arr[index] = malloc(sizeof(char)* my_strlen(filename) + 1);
    my_strcpy(tar_s->mtim_arr[index], mtim);
}


void free_store_filenames(my_tar_struct* tar_s)
{
    int index = 0;
    while ( index < tar_s->nbr_str - 1)
    {
            free(tar_s->str_arr[index]);
            free(tar_s->mtim_arr[index]);
        index += 1;
    }
    free(tar_s->str_arr);
    free(tar_s->mtim_arr);
}