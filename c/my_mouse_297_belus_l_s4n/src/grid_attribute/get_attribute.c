#include <main_header.h>

int get_size(char** tokens)
{
    int size = 0;
    while (tokens[size][0] != '\0')
    {
        size += 1;
    }
    return size;
}

void print_grid(char** grid)
{
    int index = 0;
    while (grid[index][0] != '\0')
    {
        // printf("row N %i: |%s|\n", index, grid[index]);
        // write(1, grid[index], 11);
        printf("|%s|", grid[index]);
        printf("-Row: %i\n", index);
        index +=1;
    }
}

int index_of(char* str, char ch)
{
    int index = 0; 
    while (str[index] != ch && str[index] != '\0')
    {
        // printf("ch:%c|",str[index]);
        index +=1;
    }
    return index;
}

int* get_coord(grid_t* grid_attr, int row, char ch)
{
    printf("str             :%s \n", grid_attr->tokens[row]);
    int col = 0;
    col = index_of(grid_attr->tokens[row], ch);
    printf("col index       :%i\n", col);
    if (row == 1)
    {
        grid_attr->entrance[0] = row;
        grid_attr->entrance[1] = col;
    }
    else
    {
        grid_attr->exit_[0] = row;
        grid_attr->exit_[1] = col;
    }   
}

grid_t* get_grid_attr(char* grid)
{
    grid_t* grid_attr   = malloc(sizeof(grid_t));
    grid_attr->tokens   = dirty_split(grid, '\n');
    grid_attr->cnt_cell = 0;
    printf("\n\nPrinting the grid:\n");
    print_grid(grid_attr->tokens);
    grid_attr->size     = get_size(grid_attr->tokens);
    grid_attr->len      = my_strlen(grid_attr->tokens[0]);
    printf("\n\nPrinting the attr:\n");
    printf("Entrance        :|%c|\n", grid_attr->tokens[0][grid_attr->size -3]);
    get_coord(grid_attr, 1, grid_attr->tokens[0][grid_attr->size -3]);
    get_coord(grid_attr, grid_attr->size - 1, grid_attr->tokens[0][grid_attr->size-2]);
    grid_attr->obstacle = grid_attr->tokens[0][grid_attr->size -6]; 
    printf("Entrance        :|%c|\n", grid_attr->tokens[0][grid_attr->size -3]);
    printf("Exit            :|%c|\n", grid_attr->tokens[0][grid_attr->size -2]);
    printf("Obstacle        :|%c|\n", grid_attr->tokens[0][grid_attr->size -6]);
    return grid_attr; 
}