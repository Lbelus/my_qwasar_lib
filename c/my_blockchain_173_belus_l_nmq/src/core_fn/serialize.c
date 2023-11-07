#include <main_header.h>

void serialize(node_t* head)
{
    int fd = 0;
    fd  = open("list.txt", O_CREAT | O_RDWR, 0644);
    char* str = malloc(sizeof(char) * SIZE_NID);
    my_bzero(str, SIZE_NID);
    char buff[SIZE_NID] = {'\0'};
    int pos = 0;
    node_t *tmp = head;
    while (tmp != NULL)
    {
        itoa(tmp->nid, buff, 10);
        my_strcat(str, buff);
        my_strcat(str, ":");
        if (tmp->head != NULL )
        {
            str = print_block(tmp->head, str);
        }
        pos = my_strlen(str);
        str[pos] = '\n';
        my_bzero(buff, my_strlen(buff));
        tmp = tmp->next;
        if (tmp != NULL)
        {
            str = my_realloc(str, SIZE_NID);
        }
    }
    write(fd, str, my_strlen(str));
    free(str);
    close(fd);
}