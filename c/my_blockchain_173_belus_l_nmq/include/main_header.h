#ifndef __HEADERFILE_A_
#define __HEADERFILE_A_

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>
#include <my_unistd.h>
#include <my_string.h>
#include <my_readline.h>
#include <my_linkedlist.h>
#include <my_error_management.h>
#include <my_backup.h>
#include <sys_check.h>
#include <my_blockchain_check.h>

// #ifndef TRANSACTION_STRUCT
// #define TRANSACTION_STRUCT
// struct transac_s
// {
//      nonce;
//     char gas_price[32];
//     char gaslimit[32];
//     char to[50];
//     int value;
//     char data[50];
//     char v[50];
//     char r[50];
//     char s[50];
// };
// typedef struct transac_s transac_t;
// #endif


#define BADCHAR                 (int)'?'
#define BADARG                  (int)':'
#define VALID_ARG               "-l"
#define BLOCK_ADD               2060171284
#define BLOCK_RM                1112149039
#define NODE_ADD                233620095
#define NODE_RM                 381772396
#define SYNC                    1491471
#define LS                      146
#define QUIT                    2044899
#define PING                    1598523
#define TOKEN_MAX               7
#define MAX_INPUT_TOKENS        20
#define INVITE_OBRACKET         '['
#define INVITE_DIFF             '-'
#define INVITE_SYNC             's'
#define INVITE_CLOSE            "]>"
#define __STAR_CHAR__           '*'
#define __SPACE_CHAR__          ' '
#define __DASH_CHAR__           '-'


//my_split.h

char**  dirty_split(char* str, int start_pos, char ch);

//stdlib.h

int     my_ctoi(char *string, size_t n);
char*   itoa(int value, char* result, int base);
void    my_revswap(char *ptr, char*ptr1, char tmp_char);
void*   my_realloc(void* buff, size_t size);

//my_blockchain

int     count_cmd(char*str);
node_t* add_block(node_t* head, my_getopt_t* getopt_ptr);
node_t* add_node(node_t* head, my_getopt_t* getopt_ptr);
void    rm_block(node_t* head, my_getopt_t* getopt_ptr);
void    rm_node(node_t** head, my_getopt_t* getopt_ptr);
void    print_llist_n_n1(node_t* n_head, bool state);
char*   print_block(node_t *head, char* str);
node_t* execute_cmd(my_getopt_t* getopt_ptr, node_t* head);
node_t* sync_nodes(node_t* head);
int     diff_block_02(node_t* head);
void    invite_prmt(int val, int type);
void    new_cmd(node_t* head);

#endif