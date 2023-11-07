#include <main_header.h>

void new_cmd(node_t* head) // test function to recode
{
    if (head == NULL)
    {
        invite_prmt(0, 0);
        return;
    }
    int diff = diff_block_02(head);
    int count = node_count(head);
    if (count >= 0 && diff == 0)
    {
        invite_prmt(count, 0);
    }
    else
    {
        invite_prmt(count, 1);
    }
}