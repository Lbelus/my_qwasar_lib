#include <main_header.h>

int min(int val_01, int val_02)
{
    if (val_01 < val_02)
    {
        return val_01;
    }
    else
    {
        return val_02;
    }
}

int top(int** dp, int index, int jndex)
{
    if (index > 0)
    {
        return dp[index - 1][jndex];
    }
    else
    {
        return EXIT_SUCCESS;
    }
}

int left(int** dp, int index, int jndex)
{
    if (jndex > 0)
    {
        return dp[index][jndex - 1];
    }
    else
    {
        return EXIT_SUCCESS;
    }
}

int topleft(int** dp, int index, int jndex)
{
    if (index > 0 && jndex > 0)
    {
        return  dp[index - 1][jndex - 1];
    }
    else
    {
        return EXIT_SUCCESS;
    }
}

void print_row(char** map, int size)
{
    int index = 1;
    while (index <= size)
    {
        printf("%s\n",map[index]);
        index += 1;
    }
}

void print_dp(int** dp, int rows, int cols)
{
    int index = 1;
    int jndex = 0; 
    while (index <= rows)
    {
        while (jndex < cols)
        {
            printf("%i",dp[index][jndex]);
            jndex += 1;
        }
        printf("\n");
        jndex = 0;
        index += 1;
    }
}

void init_dp(int** dp, int row_s, int col_s)
{
    int index = 0;
    int jndex = 0;
    while (index < row_s)
    {
        dp[index] = malloc(sizeof(int)*col_s);
        while (jndex < col_s)
        {
            dp[index][jndex] = 0;
            jndex +=1;
        }
        jndex = 0;
        index += 1;
    }
}

void free_dp(int** dp, int size)
{
    int index = 0;
    while (index < size)
    {
        free(dp[index]);
        index += 1;
    }
    free(dp);
}

void insert_result(char** tokens, int coord_y, int coord_x, int size)
{
    int index = 0;
    int jndex = 0;
    // printf("result is :\n");
    index = coord_y - size + 1;
    while (index <= coord_y)
    {
        jndex = coord_x - size + 1;
        while (jndex <= coord_x)
        {
            tokens[index][jndex] = 'x';
            jndex += 1;
        }
        jndex = 0;
        index += 1;
    }
}

int my_bsq(char** tokens, int row_s)
{
    int col_s = my_strlen(tokens[1]);
    int** dp = malloc(sizeof(int*)*row_s);
    init_dp(dp, row_s, col_s);
    int index = 1;
    int jndex = 0; 
    int size = 0;
    int coord_y = 0;
    int coord_x = 0;
    int top_r = 0;
    int left_r = 0;
    int topLeft_r = 0;
    while (index < row_s)
    {
        jndex = 0;
        while (jndex < col_s)
        {
            if (tokens[index][jndex] == '.')
            {
                top_r = top(dp, index, jndex);
                left_r = left(dp, index, jndex);
                topLeft_r = topleft(dp, index, jndex);
                dp[index][jndex] = 1 + min(top_r, min(left_r, topLeft_r));
                if (dp[index][jndex] > size)
                {
                    size = dp[index][jndex];
                    coord_y = index;
                    coord_x = jndex;
                }
            }
            jndex += 1;
        }
        index += 1;
    }
    // print_dp(dp, row_s, col_s);
    insert_result(tokens, coord_y, coord_x, size);
    print_row(tokens, row_s);
    free_dp(dp, row_s);
    return 0;
}