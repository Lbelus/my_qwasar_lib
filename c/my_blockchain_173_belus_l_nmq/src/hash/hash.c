#include <main_header.h>

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

int hash_string(char** arr, int arr_size, int arr_max_range)
{
    int key = 31;
    int index = 0;
    int jndex = 0;
    int exp = 0;
    int hash = 0;
    while (index < arr_size && index < arr_max_range)
    {
        jndex = 0;
        while(arr[index][jndex] != '\0')
        {
            hash = key * hash + my_pow(arr[index][jndex], exp);
            exp += 1;
            jndex += 1;
        }
        index += 1;
    }
    hash = hash & 0x7fffffff;
    return hash;
}

// bool check_hash(int hash)
// {
//     int index = 0;
//     int TOKEN_LIST[TOKEN_MAX] = {BLOCK_ADD, BLOCK_RM, NODE_ADD, NODE_RM, SYNC, QUIT};
//     while (index < TOKEN_MAX)
//     {
//         if (hash == TOKEN_LIST[index])
//         {
//             return true;
//         } 
//         index += 1;
//     }
//     return false;
// }