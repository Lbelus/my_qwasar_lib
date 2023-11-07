#include <main_header.h>

void print_llist_n_n1(node_t* n_head, bool state)
{
    reverse_node_order(&n_head);
    char* str = malloc(sizeof(char) * SIZE_NID);
    my_bzero(str, SIZE_NID);
    char buff[SIZE_NID] = {'\0'};
    int pos = 0;
    node_t *tmp = n_head;
    while (tmp != NULL)
    {
        itoa(tmp->nid, buff, 10);
        my_strcat(str, buff);
        if (state == true)
        {
            pos = my_strlen(str);
            my_strcat(str, ":");
        }
        if (tmp->head != NULL && state == true)
        {
            str = print_block(tmp->head, str);
        }
        pos = my_strlen(str);
        str[pos] = '\n';
        str[pos + 1] = '\0';
        my_bzero(buff, SIZE_NID);
        tmp = tmp->next;
        if (tmp != NULL)
        {
            str = my_realloc(str, SIZE_NID);
        }
    }
    write(STDOUT_FILENO, str, my_strlen(str));
    free(str);
    reverse_node_order(&n_head);
}