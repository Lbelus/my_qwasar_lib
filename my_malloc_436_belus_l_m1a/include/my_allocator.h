#ifndef __MY_ALLOCATOR_HEADER_
#define __MY_ALLOCATOR_HEADER_

#include <main_header.h>

#define MAGIC_NUMBER 0xDEADFACE

#ifndef _TEE_S_
#define _TEE_S_
struct tee_s
{
    unsigned char 	nb_slot;
	int 			magic_number;
};
typedef struct tee_s tee_t;
#endif

#ifndef MEM_HANDLER_S
#define MEM_HANDLER_S
struct mem_handler_s
{
	size_t    	cursor;
	size_t    	size_page;
	void*     	memory;
	intree_t*  	search_tree;
	bitlist_t*  head;
};

typedef struct mem_handler_s handler_t; 
#endif

#ifndef _PAGE_S_
#define _PAGE_S_
struct _page_s_
{
    bitlist_t*  bitnode;
    char*   	byte;
};
typedef struct _page_s_ page_t;
#endif

extern handler_t*   handler;
extern void*        my_mmap(int size);

int     	to_page_size(size_t size);
int     	calc_nb_slot(size_t size, int nb_page);
int     	calc_offset(int slot, int nb_page);
void*   	get_ptr(size_t size);
void    	set_handler(size_t size_page);
void    	initialize_handler();
page_t* 	set_page(void* ptr, int nb_page);
void*   	req_memory(size_t size);
void 		release_mem(bitlist_t* node);
bitlist_t* 	retrieve_bitlist(void* ptr);
bool 		is_page_valid(page_t* page, void* ptr);
// void    	my_free(void* ptr);
// void*   	my_malloc(size_t size);
void    	free(void* ptr);
void*   	malloc(size_t size);
void* 		realloc(void* ptr, int size);
void* 		calloc(size_t num, size_t size);
size_t 		malloc_usable_size(void* ptr);
#endif