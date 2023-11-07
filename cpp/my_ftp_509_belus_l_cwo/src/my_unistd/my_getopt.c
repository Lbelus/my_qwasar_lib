#include <my_unistd.h>

int my_getopt(char** argv, const char* valid_args, my_getopt_t* getopt_ptr)
{   
    //initialize
    if (getopt_ptr->index == 0)
    {
       getopt_ptr->index  = 1;
       getopt_ptr->pos = 0; 
    }

    if (argv[getopt_ptr->index][0] != __DASH_CHAR__)
    {
        return BADARG;
    }

    const char* opt = _my_strchr(valid_args, argv[getopt_ptr->index][getopt_ptr->pos]);
    if (opt == NULL && argv[getopt_ptr->index][getopt_ptr->pos] == '\0')
    {
        getopt_ptr->pos = 0;
        getopt_ptr->index += 1;
        return -1;
    }

    if (opt != NULL)
    {
        getopt_ptr->pos += 1;
        return opt[0];
    }
    else if (opt == NULL && argv[getopt_ptr->index][getopt_ptr->pos] != '\0')
    {
        if (argv[getopt_ptr->index][getopt_ptr->pos] != '\0' && argv[getopt_ptr->index][getopt_ptr->pos] == __DASH_CHAR__)
        {
            getopt_ptr->pos += 1;
            return 0;
        }
        else
        {
            getopt_ptr->pos += 1;
            return BADCHAR;
        }
    }
    return 0;
}