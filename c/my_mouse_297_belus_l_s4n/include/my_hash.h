#ifndef __MY_H_HEADER_
#define __MY_H_HEADER_

#include <main_header.h>

#define TABLE_SIZE 10000

#ifndef __MY_HASH__
#define __MY_HASH__
struct hash
{
    bool data[TABLE_SIZE];
};
typedef struct hash hash_t;
#endif

extern int  create_hash (void* token);
extern int  my_pow(int val, int exp);
extern void clear_hash(hash_t* hash_table);

#endif