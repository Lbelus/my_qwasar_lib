#include "../../include/main_header.h"

void free_node(node_t* head)
{
    node_t* tmp = head;
    while (head != NULL)
    {
        head = head->next;
        free(tmp);
        tmp = head;
    }
}

// void free_node(node_t *head) {

//     node_t *tmp = head; 

//     while(head != NULL) {
//         head = head->next;
//         free(tmp);
//         tmp = head; 
//     }
// }

node_t* free_single_node(node_t* head)
{
    node_t* tmp = head;
        head = head->next;
        free(tmp);
        tmp = head;

    return tmp;
}