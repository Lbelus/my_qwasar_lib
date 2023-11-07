#include "../../include/main_header.h"

node_t *create_new_mother_node(int value, node_t *head)
{
    node_t *m_result = malloc(sizeof(node_t));
    m_result->daughter_head = head;
    m_result->value = value;
    m_result->next = NULL;
    return m_result;
}