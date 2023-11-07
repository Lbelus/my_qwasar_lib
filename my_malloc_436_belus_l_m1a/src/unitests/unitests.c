// #include <main_header.h>


// // stress test malloc and free on segfault
// // stess test tree on quantity and  on capacity to receover data;
// int million_cycle_stress_test()
// {
//     void* ptr  = NULL;
//     ptr = my_malloc(1); // to initialize radix teest tree;
//     int size_test = 100;
//     radix_t* root = NULL;
//     uintptr_t arr[size_test];
//     int index = 0;
//     insert(&root, NULL);
//     while (index < size_test)
//     {
//         ptr = my_malloc(24);
//         // printf("Inserting address :%p\n", ptr);
//         arr[index] = (uintptr_t)ptr;
//         insert(&root, ptr);
//         index += 1;
//     }
//     index = 0;
//     while (index < size_test)
//     {
//         ptr = find_page_start(root, (void*)arr[index]);
//         if (index % 10 == 0)
//         {
//             printf("Sampling %p against witness arr%p \n",(void*)ptr, (void*)arr[index]);
//             void* page = find_page_start(handler->search_tree, (void*)arr[index]);
//             printf("found page on tree : %p\n", page);
//             my_free((void*)arr[index]);
//         }
//         else
//         {
//             my_free((void*)arr[index]);
//         }
//         if ((uintptr_t*)ptr != (uintptr_t*)arr[index])
//         {
//             printf("could not retrieved address at :%p\n", (void*)arr[index]);
//         }
//         index +=1;
//     }
//     return EXIT_SUCCESS;  
// }

// char* create_str(int size_alloc)
// {
//     char *str = my_malloc(size_alloc);
//     my_memset(str, 'a', size_alloc -1);
//     str[size_alloc] = '\0';
//     return str;
// }

// int fill_test()
// {
//     int size_test = 100;
//     int size_alloc = 6;
    
//     radix_t* root = NULL;
//     char** arr = malloc(sizeof(char*)*size_test);
//     int index = 0;
//     while (index < size_test)
//     {
//       arr[index] = create_str(size_alloc);
//       index += 1;
//       size_alloc = 6 * index;
//     }
//     index = 0;
//     while (index < size_test)
//     {
//       if (index % 1 == 0)
//       {
//         printf("%s\n",(char*)arr[index]);
//         my_free(arr[index]);
//       }
//       else
//       {
//         my_free((void*)arr[index]);
//       }
//       index +=1;
//     }
//   return 0;  
// }

// ptr_l_t* create_new_test_node(void* address)
// {
//     ptr_l_t* new_node = my_malloc(sizeof(ptr_l_t));
//     new_node->ptr = address;
//     new_node->next = NULL;
//     return new_node;
// }

// void insert_test_node_at_head(ptr_l_t** head, ptr_l_t* node_to_insert)
// {
//     node_to_insert->next = *head;
//     *head = node_to_insert;
// }


// void is_test_string_comform(char* test_str, char* stored_str)
// {
//     if (my_strcmp(test_str, stored_str) != 0)
//     {
//         printf("CANNOT RETRIEVE STRING\n");
//         exit(0);
//     }
// }

// void free_ptr_list(ptr_l_t* head, char* test_str)
// {
//     ptr_l_t* tmp = NULL;
//     while (head != NULL)
//     {
//         tmp = head;
//         head = head->next;
//         is_test_string_comform(test_str, (char*)tmp->ptr);
//         printf("string: %s\n", (char*)tmp->ptr);
//         my_free(tmp->ptr);
//         my_free(tmp);
//     }
// }


// void check_ptr_list(ptr_l_t* head, char* test_str)
// {
//     ptr_l_t* tmp = head;
//     while (tmp != NULL)
//     {
//         is_test_string_comform(test_str, (char*)tmp->ptr);
//         // printf("string: %s\n", (char*)tmp->ptr);
//         tmp = tmp->next;
//     }
// }

// char* alloc_and_cpy(char* src)
// {
//     int     len  = my_strlen(src);
//     char*   dest = my_malloc(len + 1);
//     my_strcpy(dest, src);
//     return dest;
// }

// int my_je_malloc_test_01(ptr_l_t** head, char* src, int cycles)
// {
//     ptr_l_t* tmp    = NULL;
//     void*    ptr    = NULL;
//     int      index  = 0;
//     // char*    src    = "this is a test_string!";

//     while (index < cycles)
//     {
//         ptr = (void*)alloc_and_cpy(src);
//         tmp = create_new_test_node((void*) ptr);
//         insert_test_node_at_head(head, tmp);
//         index += 1;
//     }
//     return EXIT_SUCCESS;
// }


// int test_monocore_string()
// {
//     ptr_l_t* head   = NULL;
//     my_je_malloc_test_01(&head, "hello world", 100);
//     free_ptr_list(head, "hello world");
//     // check_ptr_list(head, src1);
//     head = NULL;
//     return EXIT_SUCCESS;
// }

// void loop_large_class()
// {
//     void* ptr = my_malloc(35540);
//     char* src1 = "other hello world";
//     my_strcpy((char*)ptr, src1);
//     printf("string:%s\n",(char*)ptr);
//     // printf("Finding adress at :%p\n", find_run_start(handler->root, (void*)ptr));
//     my_free(ptr);
// }

// int test_monocore_large_class()
// {   
//     int index = 0;
//     while (index < 10)
//     {
//         loop_large_class();
//         index += 1;
//     }   
//     return EXIT_SUCCESS;
// }