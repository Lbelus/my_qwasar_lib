#ifndef __LINKEDLIST_
#define __LINKEDLIST_

#include <main_header.h>

#define BITMAP_SIZE 32

#ifndef _BITMAP_S_
#define _BITMAP_S_
struct bitmap_s
{
    unsigned char   data;
};
typedef struct bitmap_s bmp_t;
#endif


#ifndef _BITLIST_S_
#define _BITLIST_S_
struct bitlist_s
{
    int                 nb_page;
    struct bitlist_s*   next;
    bmp_t               bmp[BITMAP_SIZE];
};
typedef struct bitlist_s bitlist_t;
#endif

void    insert_bmp(bitlist_t** head, bitlist_t* node_to_insert);
void    set_bitmap(bmp_t* bmp);
void    set_bit(bmp_t* bmp, int index, int value);
bool    is_bitmap_full(bitlist_t* node);
void    set_in_bmp(bmp_t* bmp, int index, int value);
void    set_bits(bmp_t* bmp, int start, int len, int value);
void    initialize_bit_list(void* ptr, int nb_page);
int     get_bit(bmp_t bmp, int index);
int     count_free_bits(bmp_t* bmp, int from, int len);
int     find_free_slot(bmp_t* bmp, int len);

#endif