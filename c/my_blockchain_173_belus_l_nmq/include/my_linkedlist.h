#ifndef __HEADERFILE_E_
#define __HEADERFILE_E_

#include <main_header.h>

#define SIZE_BID 32
#define SIZE_NID 12

#ifndef STRUCT_NODE
#define STRUCT_NODE
struct node
{
    struct  node* head;
    struct  node* next;
    int     index;
    char    bid[SIZE_BID];
    char    prev_bid[SIZE_BID];
    int     nid;
};
typedef struct node node_t;
#endif


//node/block

node_t* create_block(node_t* head, int nid, char* bid);
node_t* create_cpy_block(node_t* block);
node_t* create_new_block(char* bid, char* prev_bid);
node_t* create_new_node(int nid);
void    delete_block_on_bid(node_t** head, char* bid);
void    delete_node_on_nid(node_t **head, int nid);
void    free_node(node_t* head);
node_t* insert_after_node(node_t* node_to_insert, node_t* new_node);
node_t* insert_at_head(node_t** head, node_t* node_to_insert);
int     node_count(node_t *head);
void    print_and_free_llist(node_t* n_head);
void    reverse_node_order(node_t** head);

// void sort_bid(node_t* node);
// node_t* swap(node_t* head, int node_index1, int node_index2);

#endif