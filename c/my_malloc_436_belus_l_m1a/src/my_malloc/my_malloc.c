#include <main_header.h>

// void* my_malloc(size_t size)
void* malloc(size_t size)
{
    if (size > PTRDIFF_MAX)
    {
        errno = EINVAL;
        return NULL;
    }
    if (size == 0)
    {
        return handler->memory;
    }
    void* ptr = NULL;
    initialize_handler();
    size_t size_req = size + sizeof(tee_t);
    ptr = get_ptr(size_req);
    if (ptr == NULL)
    {
        req_memory(size_req);
        ptr = get_ptr(size_req);
    } 
    return ptr;
}

// void my_free(void* ptr)
void free(void* ptr)
{
    intree_t* node = find_page_start(handler->search_tree, (void*)ptr);
    if (node == NULL)
    {
        return;
    }
    page_t* page = node->address;
    tee_t*      tee = (tee_t*)ptr - 1;
    bitlist_t*  bitnode = NULL;
    if (tee != NULL && tee->magic_number == 0xDEADFACE)
    {
        if (page != NULL)
        {
            bitnode = page->bitnode;
        }

        uintptr_t offset = (uintptr_t)(tee) - (uintptr_t)bitnode;
        int start = calc_nb_slot(offset, bitnode->nb_page);
        set_bits(bitnode->bmp, start, tee->nb_slot, false);
        release_mem(bitnode);
    }
}