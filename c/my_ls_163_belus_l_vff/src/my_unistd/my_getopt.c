#include "../../include/main_header.h"
// there is only so much you can hope making your own getopt....
// simplified version of getopt...yes... double loop would make a simpler and shorter function but getopt is used on ls source code...
int my_getopt(char** argv, char* optstr, my_getopt_t* getopt_ptr)
{
    if (getopt_ptr->optindex == 0)
    {
       getopt_ptr->optindex  = 1;
    }

    if (argv[getopt_ptr->optindex][0] != '-')
    {
        return BADARG;
    }

    char* opt = my_strchr(optstr, argv[getopt_ptr->optindex][getopt_ptr->optpos]);
    if (opt == NULL && argv[getopt_ptr->optindex][getopt_ptr->optpos] == '\0')
    {
        getopt_ptr->optpos = 0;
        getopt_ptr->optindex += 1;
        return -1;
    }

    if (opt != NULL)
    {
        getopt_ptr->optpos += 1;
        return opt[0];
    }
    else if (opt == NULL && argv[getopt_ptr->optindex][getopt_ptr->optpos] != '\0')
    {
        if (argv[getopt_ptr->optindex][getopt_ptr->optpos] != '\0' && argv[getopt_ptr->optindex][getopt_ptr->optpos] == '-')
        {
            getopt_ptr->optpos += 1;
            return 0;
        }
        else
        {
            getopt_ptr->optpos += 1;
            return BADCHAR;
        }
    }
    return 0;
}