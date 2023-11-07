
void* my_memset(void* ptr, char ch, int len)
{
    int index = 0;
    char* ptr_a = ptr;
    while (index < len)
    {
        ptr_a[index] = ch;
        index += 1;
    }
    return ptr_a;
}