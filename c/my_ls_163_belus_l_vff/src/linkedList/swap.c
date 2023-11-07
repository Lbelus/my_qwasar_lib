#include "../../include/main_header.h"

node_t* swap(node_t* head, int node_index1, int node_index2)
{
    node_t* curr1 = head, * prev1 = NULL, * curr2 = head, * prev2 = NULL, * tmp = NULL;

    if (node_index1 == node_index2 || node_index2 == head->value)
    {
        return head;
    }

    while (curr2 != NULL &&  curr2->value != node_index2)
    {
        prev2 = curr2;
        curr2 = curr2->next;
    }

    if (head->value != node_index1 && head->value != node_index2)
    {
        while(curr1 != NULL &&  curr1->value != node_index1)
        {
            prev1 = curr1;
            curr1 = curr1->next;
        }
        prev1->next = curr2;
    }
    prev2->next = curr1;
    tmp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = tmp;
    if (head->value == node_index1 || head->value == node_index2)
    {
        head = curr2;
    }
    return head;
}