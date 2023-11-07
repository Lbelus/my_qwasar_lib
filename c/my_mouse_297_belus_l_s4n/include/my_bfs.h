#ifndef __MY_BFS_HEADER_
#define __MY_BFS_HEADER_

#include <main_header.h>

#define MAX_DIRECTION 4

#ifndef __CELL_
#define __CELL_
struct cell
{
    int     x;
    int     y;
    int     cid;
    struct cell* next;
};
typedef struct cell cell_t;
#endif

extern set_t*  visited;
extern queue_t q;

cell_t* set_cell(int x, int y, cell_t* next);
bool    is_valid(int x, int y, grid_t* grid_attr);
void    add_valid_cell(int new_x, int new_y, grid_t* grid_attr, cell_t* next);
void    explore_grid(int x, int y, grid_t* grid_attr, cell_t* next);
int     bfs(grid_t* grid_attr, int* entrance, int* exit_);
void    golden_path(grid_t* grid_attr, cell_t* exit_cell);
int     free_cell(cell_t** cell);
void    delete_node(cell_t** head);
#endif