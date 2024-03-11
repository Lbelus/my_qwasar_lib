#include <main_CLI_header.h>


int set_offset(bool is_cli)
{
    if (is_cli)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}


int count_cmd(char* str, bool is_cli)
{
    int index = 0;
    int counter = set_offset(is_cli);
    while (str[index] != '\0')
    {
        if (str[index] == __SPACE_CHAR__)
        {
            counter += 1;
        }
        index += 1;
    }
    return counter;
}