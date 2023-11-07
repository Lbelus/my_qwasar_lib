#include "../../include/main_header.h"

node_t* get_info(node_t* m_head, node_t* head, int index)
{
        struct dirent* pDirent = 0;
        node_t* tmp_m_head = NULL,* tmp_node = NULL;
        DIR* pDir = NULL;
        char cwd[PATH_MAX];
        getcwd(cwd, sizeof(cwd));
        pDir = opendir(cwd);
        tmp_m_head = create_new_mother_node(index, create_llist(pDirent, pDir, head, tmp_node));
        closedir(pDir);
        return insert_at_head(&m_head, tmp_m_head);
}