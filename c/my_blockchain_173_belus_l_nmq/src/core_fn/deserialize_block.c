#include <main_header.h>

node_t* deserialize_block(node_t* head, char* str, int nid)
{
	char** tokens = NULL;
	int count = count_cmd(str);
    tokens = dirty_split(str, 0, ',');
	int bid = 0;
	while (count >= 0)
	{
        if (tokens[count][0] == __SPACE_CHAR__)
        {
            head = create_block(head, nid, &tokens[count][1]);
        }
        else
        {
            head = create_block(head, nid, tokens[count]);
        }
		count -= 1;
	}
	free(tokens);
	return head;
}