#include <main_header.h>

size_t malloc_usable_size(void* ptr)
{
    intree_t* node = find_page_start(handler->search_tree, (void*)ptr);
    if (node == NULL)
    {
        return 0;
    }
    page_t* page = node->address;
    if (page == NULL)
    {
        return 0;
    } 
    tee_t* tee = (tee_t*)ptr - 1;
    bitlist_t* bitnode = NULL;
    if (tee != NULL && tee->magic_number == 0xDEADFACE)
    {
        if(page != NULL)
        {
            bitnode = page->bitnode;
        }
        size_t len_page = bitnode->nb_page * handler->size_page;
        size_t size_ptr = len_page/(BITMAP_SIZE*8)*tee->nb_slot;
        size_ptr -= sizeof(tee_t);
        return size_ptr;
    }
    return 0;
}