#include "../../include/main_header.h"

void sort_asc(node_t* m_node)
{
    node_t* tmp = NULL, * next = NULL;
    while (m_node != NULL)
    {
        tmp = m_node->daughter_head;
        while (tmp != NULL)
        {
            next = tmp;
            while (next != NULL)
            {
                if (tmp->st.st_mtim.tv_sec == next->st.st_mtim.tv_sec)
                {
                    if (tmp->st.st_mtim.tv_nsec == next->st.st_mtim.tv_nsec)
                    {
                        if (my_strcmp(tmp->path_name, next->path_name) > 0)
                        {
                            m_node->daughter_head = swap(m_node->daughter_head, tmp->value, next->value);
                            tmp = next;
                        }
                    } else if (tmp->st.st_mtim.tv_nsec < next->st.st_mtim.tv_nsec)
                    {
                        m_node->daughter_head = swap(m_node->daughter_head, tmp->value, next->value);
                        tmp = next;
                    }
                }
                else if (tmp->st.st_mtim.tv_sec < next->st.st_mtim.tv_sec)
                {
                    m_node->daughter_head = swap(m_node->daughter_head , tmp->value, next->value);
                    tmp = next;
                }
                next = next->next;
            }
        tmp = tmp->next;
        }
        m_node = m_node->next;
    }
}