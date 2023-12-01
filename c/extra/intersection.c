/*
Description
Given two singly linked lists, determine if the two lists intersect.
Return 1.

The intersection is defined based on reference, not value.
That is, if the kth node of the first linked list is the exact same node
(by reference) as the jth node of the second linked list, then they are
intersecting.

If the two linked lists are not intersecting, the function returns 0.
The function does not modify the two linked list.

In Python you have linked list object:

class ListNode(object):
def init(self, x):
self.val = x
self.next = None

And your intersection function must check if one linked list object is found in the other linked list by values. If you find it, return 1, otherwise return 0.
Function prototype (c)
*/


/*
**
** QWASAR.IO -- intersection
**
** @param {listnode*} param_1
** @param {listnode*} param_2
**
** @return {int}
**
*/


#include <stdio.h>
#include <stdint.h>

#ifndef __MY_HASH_HEADER_
#define __MY_HASH_HEADER_

#include <stdbool.h>

#define TABLE_SIZE 1000

#ifndef __MY_HASH__
#define __MY_HASH__
struct hash
{
    bool data[TABLE_SIZE];
};
typedef struct hash hash_t;
#endif

int create_hash(void* ptr);
int  my_pow(int val, int exp);
void clear_hash(hash_t* hash_table);

#endif

#ifndef __MY_SET_HEADER_
#define __MY_SET_HEADER_

#ifndef __MY_SET__
#define __MY_SET__
#include <stdlib.h>

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


int my_pow(int val, int exp)
{
    int result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result *= val;
        }
        exp /= 2;
        val *= val;
    }
    return result;
}

int create_hash(void* ptr)
{
    uintptr_t address = (uintptr_t)ptr;
    int key = 31;
    int hash = 0;
    int index = 0;
    int size = sizeof(uintptr_t);
    while (index < size)
    {
      hash = key * hash + ((address >> (index * 8)) & 0xFF);
      index += 1;
    }

    hash = hash & 0x7fffffff;
    hash %= TABLE_SIZE;
    return hash;
}


void clear_hash(hash_t* hash_table)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table->data[i] = false;
    }
}


set_t* new_set()
{
    set_t* new = malloc(sizeof(set_t));
    new->hash_v = (hash_t){.data = {false}};
    new->create_hash = create_hash;
    new->clear_hash = clear_hash;
    return new;
}

bool include(set_t* set, void* token)
{
    int hash = set->create_hash(token);
    if (set->hash_v.data[hash] == true)
    {
        return true;
    }
    return false;
}

void add(set_t* set, void* token)
{

    int hash = set->create_hash(token);
    set->hash_v.data[hash] = true;
}

void remove_data(set_t* set, void* token)
{
    int hash = set->create_hash(token);
    set->hash_v.data[hash] = false;
}

//---------------------------------------------------------



#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE
typedef struct s_listnode
{
    int val;
    struct s_listnode* next;
} listnode;
#endif


int intersection(listnode* list_a, listnode* list_b)
{
  listnode* iterator_a = list_a;
  set_t* set = new_set();
  while (list_a != NULL)
  {
    add(set, list_a);
    list_a = list_a->next;
  }
  listnode* iterator_b = list_b;
  while (list_b != NULL)
  {
    if (include(set, list_b))
    {
      return true;
    }
    list_b = list_b->next;
  }
    return false;
}