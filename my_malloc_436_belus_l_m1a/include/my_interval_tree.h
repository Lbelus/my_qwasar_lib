#ifndef __INTERVAL_TREE_HEADER_
#define __INTERVAL_TREE_HEADER_

#include <main_header.h>

#ifndef IT_NODE_S
#define IT_NODE_S
struct it_node
{
    void* address;
    uintptr_t max;
    struct it_node* left;
    struct it_node* right;
};
typedef struct it_node intree_t;
#endif


intree_t*    fetch_node();
intree_t*    create_node(void* ptr);
intree_t*    insert(intree_t* root, void *ptr);
intree_t*    find_page_start(intree_t* root, void* ptr);

extern intree_t* free_chunk;

#endif