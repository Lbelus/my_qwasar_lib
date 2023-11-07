#include <main_header.h>

node_t* create_node(char* str)
{
    node_t* new_node = malloc(sizeof(node_t));
    int len = my_strlen(str);

    new_node->str = malloc(sizeof(char) * len + 1);
    my_strcpy(new_node->str, str);
    new_node->next = NULL;
    new_node->head = NULL;
    return new_node;
}

node_t* insert_at_head(node_t** head, node_t* node_to_insert)
{
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}

void print_llist(node_t* head)
{
    node_t* iterator = head; 
    printf("printing the llist:\n");
    while (iterator != NULL)
    {
        printf("%s\n",iterator->str);
        iterator = iterator->next;
    }
    printf("NULL\n");
}

void free_llist(node_t* head)
{
    node_t* tmp = NULL;
    while ( head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp->str);
        free(tmp);
    }
}