#include <main_header.h>

void dynamic_malloc(int argc, char** argv, my_getopt_t *getopt_ptr)
{    
    int index = 1, count = 0;
    while (index < argc)
    {
        if (argv[index][0] != __DASH_CHAR__)
        {
            getopt_ptr->path_arr[count] = malloc(sizeof(char)*(my_strlen(argv[index])+1));
            count++;
        }
        index++;
    }
}

void dynamic_free(int argc, char** argv, my_getopt_t *getopt_ptr)
{    
    int index = 1, count = 0;
    while (index < argc)
    {
        if (argv[index][0] != __DASH_CHAR__)
        {
            free(getopt_ptr->path_arr[count]);
            count++;
        }
        index++;
    }
}