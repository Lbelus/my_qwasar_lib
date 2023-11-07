#ifndef __MY_GRID_ATTR_HEADER_
#define __MY_GRID_ATTR_HEADER_

#include <main_header.h>

#ifndef GRID_STRUCT
#define GRID_STRUCT
struct data_struct
{
    int     size;
    int     len;
    char    obstacle;
    int     entrance[2];
    int     exit_[2];
    int     current_cid;
    char**  tokens;
    int     cnt_cell;
};
typedef struct data_struct grid_t;
#endif

grid_t* get_grid_attr(char* grid);
int     get_size(char** tokens);
int     index_of(char* str, char c);
int*    get_coord(grid_t* grid_attr, int row, char ch);
void    print_grid(char** grid);

#endif