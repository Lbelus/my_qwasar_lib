#ifndef __HEADERFILE_C_
#define __HEADERFILE_C_

#include <main_header.h>

char*   consensus_check(node_t* head, char* buff);
void    set_last_bid(node_t* head, char* bid);
bool    check_bid(node_t* block_head, char* bid);
bool    is_block_on_chain(node_t* block_head, node_t* block);
bool    is_block_on_chain_02(node_t* block_head,int nid, char* bid);
bool    is_node_on_network(node_t* node_head, int nid);
bool    is_block_on_network(node_t* node_head, char* bid);
bool    is_block_on_node(node_t* node_head, int nid, char* bid);

#endif