#ifndef __HEADERFILE_B_
#define __HEADERFILE_B_

#include <main_header.h>
//backup

void    serialize(node_t* head);
node_t* deserialize(node_t* head);
node_t* deserialize_block(node_t* head, char* str, int nid);

#endif