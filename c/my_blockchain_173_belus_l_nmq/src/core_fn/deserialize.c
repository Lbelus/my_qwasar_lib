#include <main_header.h>

node_t* deserialize(node_t* head)
{
    node_t* tmp = NULL;
    int fd = open("list.txt", O_RDONLY, 0644);
    if (fd == -1)
    {
        new_cmd(head);
        return head;
    }
    init_my_readline();
    char* str = NULL;
    char** tokens = NULL;
    int nid = 0;
    while ((str = my_readline(fd)) != NULL)
    {
   	    tokens = dirty_split(str, 1, ':');
	    nid = my_ctoi(tokens[1], my_strlen(tokens[1]));
	    tmp = create_new_node(nid);
        head = insert_after_node(head, tmp);	
	    head = deserialize_block(head, &tokens[2][1], nid);
	    free(tokens);
	    free(str);
    }
    close(fd);
    new_cmd(head);
    return head;
}