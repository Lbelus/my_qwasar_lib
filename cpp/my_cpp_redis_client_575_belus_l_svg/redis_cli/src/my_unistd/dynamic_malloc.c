#include <my_unistd.h>

void dynamic_malloc(int argc, char** argv, my_getopt_t *getopt_ptr)
{    
    int index = 1;
    int count = 0;
    while (index < argc)
    {
        if (argv[index][0] != __DASH_CHAR__)
        {
            getopt_ptr->str_arr[count] = (char*)malloc(sizeof(char)*(_my_strlen(argv[index])+1));
            count += 1;
        }
        index += 1;
    }
}

// void dynamic_free(int argc, char** argv, my_getopt_t *getopt_ptr)
// {
//     int index = 1; 
//     int count = 0;
//     while (index < argc)
//     {
//         if (argv[index][0] != __DASH_CHAR__)
//         {
//             free(getopt_ptr->str_arr[count]);
//             count += 1;
//         }
//         index += 1;
//     }
// }


void free_str_array( my_getopt_t *getopt_ptr)
{
    int index = 0; 
    while (index < getopt_ptr->nbr_str)
    {
        free(getopt_ptr->str_arr[index]);
        index += 1;
    }
}