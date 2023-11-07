#include <main_header.h>


size_t set_page_len(void* ptr)
{
    page_t* page = (page_t*)ptr;
    size_t page_len = page->bitnode->nb_page * handler->size_page;
    return page_len - 1; 
}


intree_t* create_node(void* ptr)
{
    intree_t* tmp = fetch_node();
    
    if (!tmp)
    {
      return NULL;
    }
    size_t page_len = set_page_len(ptr);
    tmp->address = ptr;
    tmp->max = (intptr_t)ptr + page_len;
    tmp->left = NULL; 
    tmp->right = NULL;
    return tmp;
}

intree_t* insert(intree_t* root, void* ptr)
{
    if (root == NULL)
    {
      return create_node(ptr);
    }

    uintptr_t low = (uintptr_t)root->address;

    if ((uintptr_t)ptr < low )
    {
        root->left = insert(root->left, ptr);
    } 
    else
    {
        root->right = insert(root->right, ptr);
    }
    size_t page_len = set_page_len(ptr);
    if (root->max < (uintptr_t)ptr + page_len)
    {
        root->max = (uintptr_t)ptr + page_len;
    }
  return root;
}

intree_t* find_page_start(intree_t* root, void* ptr)
{
    if (root == NULL)
    { 
      return NULL;
    }
    size_t page_len = set_page_len(root->address);
    if ((uintptr_t)root->address <= (uintptr_t)ptr 
      && (uintptr_t)ptr <= (uintptr_t)root->address + page_len)
    {
      return root;
    } 
    if (root->left != NULL && root->left->max >= (uintptr_t)ptr)
    {
        return find_page_start(root->left, ptr);
    }
    return find_page_start(root->right, ptr);
}


intree_t* fetch_node()
{
    intree_t* new_node = NULL;
    new_node = allocate_node();
    if (new_node == NULL)
    {
        void * ptr = my_mmap(handler->size_page);
        int size = handler->size_page / sizeof(intree_t) - 1;
        init_memory_segment(ptr, size);
        new_node = allocate_node();
    }
    return new_node;
}


// algo graveyard
//---------------------------------works just fine
// radix_t* create_node(void* ptr)
// {
//     radix_t *node = fetch_node();
//     node->ptr = ptr;
//     node->left = node->right = NULL;
//     return node;
// }

//  void insert(radix_t** head, void *ptr)
// {
//     radix_t* node_to_insert = create_node(ptr);
//     node_to_insert->right = *head;
//     *head = node_to_insert;
// }

// void* find_page_start(radix_t* root, void* ptr)
// {
//     radix_t*   tmp       = root;
//     page_t*    page      = NULL;
//     int        len_page  = 0;
//     uintptr_t  start     = 0;
//     uintptr_t  end       = 0;
//     uintptr_t  value     = (uintptr_t)ptr;
//     while (tmp != NULL)
//     {
//         page = (page_t*)tmp->ptr;
//         len_page = page->bitnode->nb_page * handler->size_page;
//         start = (uintptr_t)tmp->ptr;
//         end = (uintptr_t)tmp->ptr + len_page;
//         if (start < value && value < end)
//         {
//             return (void*)tmp->ptr;
//         }
//         tmp = tmp->right;
//     }
//     return NULL;
// }
//-----------------------------------

// #ifndef _RADIX_NODE_S_
// #define _RADIX_NODE_S_
// struct radix_node_s
// {
//     void*                ptr;
//     struct radix_node_s* left;
//     struct radix_node_s* right; 
// };
// typedef struct radix_node_s radix_t;
// #endif

// void insert(radix_t** root, void *ptr)
// {
//     if (!(*root))
//     {
//         *root = create_node(ptr);
//         return;
//     }
//     uintptr_t   address     = (uintptr_t)ptr;
//     radix_t*    curr        = *root;
//     int         bit_index   = sizeof(void*) * 8 - 1;
//     while (bit_index >= 0)
//     {
//         if ((address >> bit_index) & 1)
//         {
//             if (!curr->right)
//             {
//                 curr->right = create_node(ptr);
//             }
//             curr = curr->right;
//         } 
//         else
//         {
//             if (!curr->left)
//             {
//                 curr->left = create_node(ptr);
//             }
//             curr = curr->left;
//         }
//         curr->ptr = ptr;
//       bit_index -= 1;
//     }
// }

// void* find_page_start(radix_t* root, void* ptr)
// {
//     radix_t* tmp = root;
//     uintptr_t address = (uintptr_t)ptr;
//     uintptr_t highest = 0;
//     uintptr_t valid = 0;
//     int index = 0;
//     while (tmp != NULL)
//     {
//         index += 1;
//         if (highest < (uintptr_t)tmp->ptr)
//         {
//             highest = (uintptr_t)tmp->ptr;
//             printf("highest %p\n", highest);
//         }
//         if (address > highest)
//         {
//             valid = highest;
//         }
//         tmp = tmp->right;
//     }
//     printf("nb of iteration %i", index);
//     printf("returned address %p\n", valid);
//     return (void*)valid;
// }




// void* find_page_start(radix_t* root, void* ptr)
// {
//     uintptr_t address = (uintptr_t)ptr;
//     radix_t* curr = root;
//     int bit_index = sizeof(void*) * 8 - 1;
//     while (bit_index >= 0)
//     {
//         if ((address >> bit_index) & 1)
//         {
//             if (!curr->right)
//             {
//                 return curr->ptr;
//             }
//             curr = curr->right;
//         }
//         else
//         {
//             if (!curr->left)
//             {
//                 return curr->ptr;
//             }
//             curr = curr->left;
//         }
//         bit_index -= 1;
//     }
//     return curr->ptr;
// }
//------------------------------------


// radix_t* create_node(void* ptr)
// {
//     // radix_t *node = allocated_node;
//     radix_t *node = fetch_node();
//     node->ptr = ptr;
//     node->left = node->right = NULL;
//     return node;
// }

// // void insert(radix_t** root, void *ptr)
// // {
// //     if (!(*root))
// //     {
// //         *root = create_node(ptr);
// //         return;
// //     }
// //     uintptr_t address = (uintptr_t)ptr;
// //     radix_t* curr = *root;
// //     int bit_index = sizeof(void*) * 8 - 1;
// //     while (bit_index >= 0)
// //     {
// //         if ((address >> bit_index) & 1)
// //         {
// //             if (!curr->right)
// //             {
// //                 curr->right = create_node(ptr);
// //                 return;
// //             }
// //             curr = curr->right;
// //         }
// //         else
// //         {
// //             if (!curr->left)
// //             {
// //                 curr->left = create_node(ptr);
// //                 return;
// //             }
// //             curr = curr->left;
// //         }
// //         bit_index -= 1;
// //     }
// // }

// void insert(radix_t** root, void *ptr)
// {
//     if (!(*root))
//     {
//         *root = create_node(ptr);
//         return;
//     }
//     uintptr_t address = (uintptr_t)ptr;
//     radix_t* curr = *root;
//     int bit_index = sizeof(void*) * 8 - 1;
//     while (bit_index >= 0)
//     {
//         if ((address >> bit_index) & 1)
//         {
//           if (!curr->right)
//           {
//             curr->right = create_node(ptr);
//           }
//           curr = curr->right;
//         } 
//         else
//         {
//           if (!curr->left)
//           {
//             curr->left = create_node(ptr);
//           }
//           curr = curr->left;
//         }
//         if(curr->ptr == NULL)
//         {
//             curr->ptr = ptr;
//         }
//       bit_index -= 1;
//     }
// }


// radix_t* next_child(radix_t* child_01, radix_t* child_02)
// {
//     if (child_01)
//     {   
//         return child_01;
//     } 
//     else if (child_02)
//     {
//         return child_02;
//     } 
//     else
//     {
//         return NULL;
//     }
// }

// radix_t* next_bit(radix_t* root, bool true_false)
// {
//     radix_t* tmp = NULL;
//     if (true_false)
//     {
//         if ((tmp = next_child(root->right, root->left)))
//         {
//             return tmp;
//         }
//         else 
//         {
//             return NULL;
//         }
//     }
//     else
//     {
//         if ((tmp = next_child(root->left, root->right)))
//         {
//             return tmp;
//         }
//         else 
//         {
//             return NULL;
//         }
//     }
// }

// uintptr_t validate_run(uintptr_t run_address, uintptr_t address, uintptr_t highest_last_address)
// {
//     void* ptr = (void*)run_address;
//     run_t* run = (run_t*)ptr;
//     int size_run = 0;
//     if (run->size_class > 14336)
//     {
//         size_run = run->size_class + sizeof(run_t);
//     }
//     else
//     {
//         size_run = sizeof(run_t) + run->size_class * 8 * BITMAP_SIZE;
//     }
//     uintptr_t run_end = (uintptr_t)ptr + size_run;
//     if (address < run_end)
//     {
//         return run_address;
//     }
//     return highest_last_address;
// }

// // void* find_run_start(radix_t* root, void *ptr)
// // {
// //     uintptr_t address = (uintptr_t)ptr;
// //     uintptr_t highest_last_address = (uintptr_t)NULL;
// //     uintptr_t current_address = (uintptr_t)NULL;
// //     int bit_index = sizeof(void*) * 8 - 1; 
// //     radix_t* tmp = NULL;
// //     while (bit_index >= 0)
// //     {
// //         if (!(tmp = next_bit(root, (address >> bit_index) & 1)))
// //         {
// //             break;
// //         }
// //         root = tmp;
// //         current_address = (uintptr_t)root->ptr;
// //         // if (current_address == NULL)
// //         // {
// //         //     continue;
// //         // }
// //         if (current_address == address)
// //         {
// //             return (void*)current_address;
// //         }
// //         if (current_address > highest_last_address && current_address < address)
// //         {
// //             highest_last_address = validate_run(current_address, address, highest_last_address);
// //         }
// //         bit_index -= 1;
// //     }
// //     return (void*)highest_last_address;
// // }

// void release_run_start(radix_t* root, void *ptr)
// {
//     // uintptr_t address = (uintptr_t)ptr;
//     // uintptr_t highest_last_address = (uintptr_t)NULL;
//     // uintptr_t current_address = (uintptr_t)NULL;
//     // int bit_index = sizeof(void*) * 8 - 1; 
//     // radix_t* tmp = NULL;
//     // while (bit_index >= 0)
//     // {
//     //     if (!(tmp = next_bit(root, (address >> bit_index) & 1)))
//     //     {
//     //         break;
//     //     }
//     //     root = tmp;
//     //     current_address = (uintptr_t)root->ptr;
//     //     if (current_address == address)
//     //     {
//     //         root->ptr = NULL;
//     //         return;
//     //     }
//     //     bit_index -= 1;
//     // }
// }

// void* find_run_start(radix_t* root, void* ptr)
// {
//     uintptr_t highest_last_address = (uintptr_t)NULL;
//     uintptr_t current_address = (uintptr_t)NULL;
//     uintptr_t address = (uintptr_t)ptr;
//     radix_t* curr = root;
//     int bit_index = sizeof(void*) * 8 - 1;
//     while (bit_index >= 0)
//     {
//         if ((address >> bit_index) & 1)
//         {
//           if (!curr->right)
//           {
//             return curr->ptr;
//           }
//           curr = curr->right;
//         }
//         else
//         {
//           if (!curr->left)
//           {
//             return curr->ptr;
//           }
//           curr = curr->left;
//         }
//       bit_index -= 1;
//     }
//     return curr->ptr;
// }

//------------------------------------

// radix_t* create_node(void* ptr)
// {
//     // radix_t *node = allocated_node;
//     radix_t *node = fetch_node();
//     node->ptr = ptr;
//     node->left = node->right = NULL;
//     return node;
// }

// void insert(radix_t** root, void *ptr)
// {
//     if (!(*root))
//     {
//         *root = create_node(ptr);
//         return;
//     }
//     uintptr_t address = (uintptr_t)ptr;
//     radix_t* curr = *root;
//     int bit_index = sizeof(void*) * 8 - 1;
//     while (bit_index >= 0)
//     {
//         if ((address >> bit_index) & 1)
//         {
//             if (!curr->right)
//             {
//                 curr->right = create_node(ptr);
//                 return;
//             }
//             curr = curr->right;
//         }
//         else
//         {
//             if (!curr->left)
//             {
//                 curr->left = create_node(ptr);
//                 return;
//             }
//             curr = curr->left;
//         }
//         bit_index -= 1;
//     }
// }


// radix_t* next_child(radix_t* child_01, radix_t* child_02)
// {
//     if (child_01)
//     {   
//         return child_01;
//     } 
//     else if (child_02)
//     {
//         return child_02;
//     } 
//     else
//     {
//         return NULL;
//     }
// }

// radix_t* next_bit(radix_t* root, bool true_false)
// {
//     radix_t* tmp = NULL;
//     if (true_false)
//     {
//         if ((tmp = next_child(root->right, root->left)))
//         {
//             return tmp;
//         }
//         else 
//         {
//             return NULL;
//         }
//     }
//     else
//     {
//         if ((tmp = next_child(root->left, root->right)))
//         {
//             return tmp;
//         }
//         else 
//         {
//             return NULL;
//         }
//     }
// }


// void* find_run_start(radix_t* root, void *ptr)
// {
//     uintptr_t address = (uintptr_t)ptr;
//     uintptr_t highest_last_address = NULL;
//     uintptr_t current_address = NULL;
//     int bit_index = sizeof(void*) * 8 - 1; 
//     radix_t* tmp = NULL;
//     while (bit_index >= 0)
//     {
//         if (!(tmp = next_bit(root, (address >> bit_index) & 1)))
//         {
//             break;
//         }
//         root = tmp;
//         current_address = (uintptr_t)root->ptr;
//         if (current_address == address)
//         {
//             return (void*)current_address;
//         }
//         if (current_address > highest_last_address && current_address < address)
//         {
//             highest_last_address = current_address;
//         }
//         bit_index += 1;
//     }
//     return (void*)highest_last_address;
// }

//------------------------------interval search
// radix_t* create_node(void* low, void* high)
// {
//     radix_t* tmp = malloc(sizeof(radix_t));

//     if (!tmp) return NULL;
//     tmp->low = low;
//     tmp->high = high;
//     tmp->max = (intptr_t)high;
//     tmp->left = tmp->right = NULL;

//     return tmp;
// }

// radix_t* insert(radix_t* root, void* low, void* high)
// {
//     if (root == NULL) return create_node(low, high);

//     intptr_t l = (intptr_t)root->low;

//     if ((intptr_t)low < l)
//     {
//         root->left = insert(root->left, low, high);
//     }
//     else
//     {
//         root->right = insert(root->right, low, high);
//     }

//     if (root->max < (intptr_t)high)
//     {
//         root->max = (intptr_t)high;
//     }

//     return root ;
// }

// radix_t* find_page_start(radix_t* root, void* ptr)
// {
//     if (root == NULL) return NULL;

//     if ((intptr_t)root->low <= (intptr_t)ptr && (intptr_t)ptr <= (intptr_t)root->high)
//     {
//         return root;
//     }

//     if (root->left != NULL && root->left->max >= (intptr_t)ptr)
//     {
//         return find_page_start(root->left, ptr);
//     }

//     return find_page_start(root->right, ptr);
// }

