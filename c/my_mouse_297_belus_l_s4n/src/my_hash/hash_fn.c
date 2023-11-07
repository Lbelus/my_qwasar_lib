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

int create_hash(void* ptr)
{
    int* token  = ptr; 
    int key     = 31;
    int index   = 0;
    int exp     = 0;
    int hash    = 0;

    while (token[index] != '\0')
    {
        hash    = key * hash + my_pow(token[index], exp);
        exp     += 1;
        index   += 1;
    }
    index   += 1;
    hash    = hash & 0x7fffffff;
    hash    %= TABLE_SIZE;
    return hash;
}

void clear_hash(hash_t* hash_table)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table->data[i] = false;
    }
}