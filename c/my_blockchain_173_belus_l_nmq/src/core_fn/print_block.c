#include <main_header.h>

char* print_block(node_t *head, char* str)
{
    int size = 0;
    node_t *tmp = head;
    int size_blocks = node_count(head)*(SIZE_BID + 1);
    str = my_realloc(str, size_blocks);
    int pos = my_strlen(str);
    my_bzero(&str[pos], SIZE_BID);
    while (tmp != NULL)
    {
        if (tmp->next != NULL)
        {
            size = my_strlen(str);
            str[size] = __SPACE_CHAR__;
            my_strcat(str, tmp->bid);
            size = my_strlen(str);
            str[size] = ',';
        }
        else
        {
            size = my_strlen(str);
            str[size] = __SPACE_CHAR__;
            my_strcat(str, tmp->bid);
        }
        tmp = tmp->next;
    }
    return str;
}