#ifndef __MY_ENV_HEADER_
#define __MY_ENV_HEADER_

#include <main_header.h>


    #ifndef __ENV_DUP_
    #define __ENV_DUP_
    struct node {
        char*        name;
        char*        value;
        int          total_len;
        struct node* next;
    };
    typedef struct node node_t;
    #endif

#define EQUAL_STR "="

extern char**   environ;
extern node_t*  env_head;
extern int      env_size;

node_t* create_new_node(char* name, char* value);
node_t* insert_at_head(node_t **head, node_t *node_to_insert);
void    copy_env();
void    add_name(char* name, char* value);
char**  recreate_env();
void    my_env();
void    my_unsetenv(char* name);
int     name_exist(char* name);
void    overwrite_fn(char* name, char* value);
char*   my_getenv(char* name);
int     my_setenv(char* name, char* value, int overwrite);

#endif