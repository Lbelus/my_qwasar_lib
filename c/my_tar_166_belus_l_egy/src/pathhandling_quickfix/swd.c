#include "../../include/main_header.h"
#include <stdio.h>

void swd(char* str, int pos) // set_working_directory
{
    char tmp_str[pos +1];
    my_strncpy(tmp_str, str, pos);
    chdir(tmp_str);
}