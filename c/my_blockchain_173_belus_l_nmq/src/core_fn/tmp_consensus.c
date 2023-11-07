#include <main_header.h>

// placeholder consensus
char* consensus_check(node_t* head, char* buff) 
{
    int max_count = 0;
    // char max_element[SIZE_BID] = {'\0'};
    int current_count = 0;
    char current_element[SIZE_BID] = {'\0'};
    // Iterate through linked list and find the element with the highest frequency
    node_t *tmp = head;
    while (tmp != NULL)
    {
        if (my_strcmp(tmp->prev_bid, current_element) == 0)
        {
            current_count++;
        }
        else
        {
            if (current_count > max_count)
            {
                max_count = current_count;
                my_strcpy(buff, current_element);
                // max_element = current_element;
            }
            my_strcpy(current_element, tmp->prev_bid);
            // current_element = tmp->prev_bid;
            current_count = 1;
        }
        tmp = tmp->next;
    }
    // Check the count for the last element
    if (current_count > max_count)
    {
        max_count = current_count;
        my_strcpy(buff, current_element);
    }
    return buff;
}