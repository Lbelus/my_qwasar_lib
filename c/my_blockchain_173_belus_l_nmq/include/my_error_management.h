#ifndef __HEADERFILE_D_
#define __HEADERFILE_D_

#include <main_header.h>

#define NODE_EXIST_ERROR        "NOK\n2: this node already exists\n"
#define NODE_EXIST_ERROR_LEN    32
#define BLOCK_EXIST_ERROR       "NOK\n3: this block already exists\n"
#define BLOCK_EXIST_ERROR_LEN   33
#define NODE_DNT_EXIST          "NOK\n4: node doesn't exists\n"
#define NODE_DNT_EXIST_LEN      27
#define BLOCK_DNT_EXIST         "NOK\n5: block doesn't exists\n"
#define BLOCK_DNT_EXIST_LEN     28
#define CMD_ERROR               "NOK\n6: command not found\n"
#define CMD_ERROR_SIZE          25
#define OK                      "OK\n"
#define OK_SIZE                 3

//error management 
int     error_handler(node_t* head, my_getopt_t* getopt_ptr);
int     error_add_block(node_t* head, my_getopt_t* getopt_ptr);
int     error_add_node(node_t* head, my_getopt_t* getopt_ptr);
int     error_rm_block(node_t* head, my_getopt_t* getopt_ptr);
int     error_rm_node(node_t** head, my_getopt_t* getopt_ptr);

#endif