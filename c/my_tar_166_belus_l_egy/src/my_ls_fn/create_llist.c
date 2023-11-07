#include "../../include/main_header.h"

node_t* create_llist(struct dirent * pDirent, DIR *pDir, node_t *head, node_t *tmp_node)
{ 
    int index = 0;
    while ((pDirent = readdir(pDir)) != NULL)
    {
        char *tmp_str = malloc(sizeof(char)* my_strlen(pDirent->d_name)+1);
        my_strcpy(tmp_str,pDirent->d_name);
        tmp_node = create_new_node(index, tmp_str);
        head = insert_at_head(&head, tmp_node);
        index++;
    }
    return head;
} 