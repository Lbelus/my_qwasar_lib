#include "../../include/main_header.h"

void lexi_sort(node_t *m_node)
{
    node_t *tmp = NULL, *next = NULL;
    while (m_node != NULL)
    {
        tmp = m_node->daughter_head;
        while (tmp != NULL)
        {
            next = tmp;
            while (next != NULL)
            {
                if (my_strcmp(tmp->path_name, next->path_name) > 0)
                {
                    m_node->daughter_head = swap(m_node->daughter_head, tmp->value, next->value);
                    tmp = next;
                }
                next = next->next;
            }
        tmp = tmp->next;
        }
        m_node = m_node->next;
    }
}