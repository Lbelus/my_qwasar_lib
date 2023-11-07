#ifndef __HEADERFILE_K_
#define __HEADERFILE_K_

#include <dirent.h> // not a sycall
#include "/usr/include/x86_64-linux-gnu/sys/stat.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef STRUCT_NODE
#define STRUCT_NODE
struct node 
{
    //hierarchy: n+1
    int value;
    struct node* daughter_head;
    //hierarchy: n
    char* path_name;
    struct stat st;
    struct node* next;
};
typedef struct node node_t;
#endif


#ifndef STRUCT_MY_GETOPT
#define STRUCT_MY_GETOPT

typedef struct s_my_getopt
{
    int optindex;
    int optpos;
    bool* boll_arr; // activate each option
    int count_str;
    int path_pos;
    char** path_arr;
    char home[PATH_MAX]; 
} my_getopt_t;
#endif

#define BADCHAR (int)'?'
#define BADARG (int)':'
#define VALID_ARG "-1at"


// myls core components
int flag_parser(int argc, char **argv, char *valid_args, my_getopt_t *getopt_ptr);
    void count_path_array(int argc, char** argv, my_getopt_t *getopt_ptr);
    void dynamic_malloc(int argc, char** argv, my_getopt_t *getopt_ptr);
    int my_getopt(char **argv, char *optstr, my_getopt_t *getopt_ptr);
    void n_state(char opt, my_getopt_t *getopt_ptr, char** argv);

void sort_str_arr(my_getopt_t *getopt_ptr);

node_t* create_llist(struct dirent * pDirent, DIR *pDir, node_t *head, node_t *tmp_node); 

void sort_asc(node_t* m_node);
void lexi_sort(node_t* m_node);
void print_and_free_llist(node_t* m_head, my_getopt_t *getopt_ptr);
void dynamic_free(int argc, char** argv, my_getopt_t *getopt_ptr);
void free_opt(int argc, char** argv, my_getopt_t *getopt_ptr);
void fill_bool_array(bool* bool_arr, int len);
void init_getopt(my_getopt_t* getopt_ptr);

node_t* get_info(node_t* m_head, node_t* head, int index);

//my string

char* my_strchr(char* str1, char ch);
int my_strcmp(char* str1, char* str2);
char* my_strcpy(char* str_dest, char* str_src);
int my_strlen(char *str);

// my node library

node_t *create_new_mother_node(int value, node_t *head);
node_t *create_new_node(int value, char *path);
node_t *insert_at_head(node_t **head, node_t *node_to_insert);
void reverse_node_order(node_t **head);
void free_node(node_t *head);
void recur_free_node(node_t *head);
void test_print_list(node_t *head, bool* flags);
int node_count(node_t *head);
int recur_node_count(node_t *head, int count);
node_t* swap(node_t* head, int node_index1, int node_index2);

#endif