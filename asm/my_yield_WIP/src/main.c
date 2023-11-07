#include "my_yield.h"

SavedState state;

int my_primitive_yield(int index)
{
    if (state.state != 0) 
    {
        restore_state(&state);
    }
    index += 1;
    state.state = 1;
    save_state(&state);
    return index;
}

int my_primitive_each_int(int* array)
{
    int index = 0;
    if (state.state != 0) 
    {
        restore_state(&state);
        index = state.rax;
    }

    index += 1;
    state.state = 1;
    save_state(&state);
    return array[index];
}

char* my_primitive_each_str(char** array)
{
    int index = 0;
    if (state.state != 0) 
    {
        restore_state(&state);
        index = state.rax;
    }

    index += 1;
    state.state = 1;
    save_state(&state);
    return array[index];
}


int my_primitive_map(int* array, int val)
{
    int index = -1;
    if (state.state != 0) 
    {
        restore_state(&state);
        index = state.rcx;
    }

    index += 1;
    array[index] *= val;
    state.state = 1;
    save_state(&state);
    return array[index];
}

void fill_test_var(int* arr)
{
    int val = 0;
    while (val < 10)
    {
        arr[val] = val;
        val += 1;
    }
}

void test_01()
{
    int result = -1;
    printf("primitive_yield_test:\n");
    while ((result = my_primitive_yield(result)) < 10)
    {
        printf("%d\n", result);
    }
    state.state = 0;
    printf("end...\n");
}
void test_02()
{
    printf("primitive_each_test:\n");
    int result = -1;
    int* arr = malloc(sizeof(int) * 10);
    
    fill_test_var(arr);
    while ((result = my_primitive_each_int(arr)) != 9)
    {
        printf("%d\n", result);
    }
    free(arr);
    state.state = 0;
}

int main()
{
    test_01();
    test_02();
    printf("primitive_map_test:\n");
    int index = 0;
    int result = -1;
    int* arr = malloc(sizeof(int) * 10);
    fill_test_var(arr);
    while ((result = my_primitive_map(arr , 2)) || index < 9)
    {
        printf("%d\n", result);
        index += 1;
    }

    // index = 0; 
    // while(index < 9)
    // {
    //     printf("%d\n", arr[index]);
    //     index += 1;
    // }

    free(arr);

    return 0;
}