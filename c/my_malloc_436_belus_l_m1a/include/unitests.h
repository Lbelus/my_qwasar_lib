#ifndef __UNITESTS_HEADER_
#define __UNITESTS_HEADER_

#include <main_header.h>


#ifndef PTR_LIST_S
#define PTR_LIST_S
struct ptr_list_s
{
    int     size_byte;
    void*   ptr;
    struct  ptr_list_s* next;
};
typedef struct ptr_list_s ptr_l_t;
#endif

int         million_cycle_stress_test();
ptr_l_t*    create_new_test_node(void* address);
void        insert_test_node_at_head(ptr_l_t** head, ptr_l_t* node_to_insert);
void        is_test_string_comform(char* test_str, char* stored_str);
void        free_ptr_list(ptr_l_t* head, char* test_str);
void        check_ptr_list(ptr_l_t* head, char* test_str);
char*       alloc_and_cpy(char* src);
int         my_je_malloc_test_01(ptr_l_t** head, char* src, int cycles);
int         test_monocore_string();
void        loop_large_class();
int         test_monocore_large_class();
int         fill_test();
#endif