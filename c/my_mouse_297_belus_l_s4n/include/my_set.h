#ifndef __MY_SET_HEADER_
#define __MY_SET_HEADER_

#include <main_header.h>

#ifndef __MY_SET__
#define __MY_SET__
struct set
{
    hash_t  hash_v;
    void    (*clear_hash)(hash_t*);
    int     (*create_hash)(void*);
};
typedef struct set set_t;
#endif

bool    include(set_t* set, void* token);
void    add(set_t* set, void* token);
void    remove_data(set_t* set, void* token);
set_t*  new_set();
#endif