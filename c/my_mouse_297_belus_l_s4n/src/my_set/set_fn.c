#include <main_header.h>

set_t* new_set()
{
    set_t* new = malloc(sizeof(set_t));
    new->hash_v = (hash_t){.data = {false}};
    new->create_hash = create_hash;
    new->clear_hash = clear_hash;
    return new;
}

bool include(set_t* set, void* token)
{
    // int hash = create_hash(str);
    int hash = set->create_hash(token);
    if (set->hash_v.data[hash] == true)
    {
        return true;
    }
    return false;
}

void add(set_t* set, void* token)
{
    // int hash = create_hash(str);
    int hash = set->create_hash(token);

    set->hash_v.data[hash] = true;
}

void remove_data(set_t* set, void* token)
{
    // int hash = create_hash(str);
    int hash = set->create_hash(token);

    set->hash_v.data[hash] = false;
}