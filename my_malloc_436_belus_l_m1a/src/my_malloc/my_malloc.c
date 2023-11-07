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

        // if (!is_page_valid(page, ptr))
        // {
        //     // printf("page not valid \n");
        //     if (!(bitnode = retrieve_bitlist(ptr)))
        //     {
        //         return;
        //     }
        // }

    // printf("tee ok \n");
    // char buff[15];
    // itoa(size, buff, 10);
    // write(1, buff, my_strlen(buff));
    // write(1,"\n", 1);
    // printf("pointer addresse is at %i\n", (uintptr_t)ptr);
    // write(1,"free\n", 5);
    // printf("retreiving page from ptr : %p\n", ptr);
    // printf("NB slot is : %i\n", tee->nb_slot);
    // printf("found page on tree : %p\n", page);
    // printf("offset value : %i\n", offset);
    // printf("nb_page : %i\n", bitnode->nb_page);
    // printf("free :Offset: %i | slot: %i | len: %i\n", offset, start, tee->nb_slot);
    // printf("pos is %i\n", start);