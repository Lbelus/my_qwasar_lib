#include <my_unistd.h>

void count_str_array(int argc, char** argv, my_getopt_t* getopt_ptr)
{
    int index = 1;
    while (index < argc)
    {
        if (argv[index][0] != __DASH_CHAR__)
        {
            getopt_ptr->nbr_str += 1;
        }
        index += 1;
    }
}