#include "pathfinder.h"

void mx_tableprim_cmp(t_path *path, t_matrix *matrix) {
    int rows = 0;
    int columns = 0;

    matrix->tableprim_cmp = (long **) malloc(sizeof(long *) * path->num_of_islands);
    for (int i = 0; i < path->num_of_islands; i++)
        matrix->tableprim_cmp[i] = (long*) malloc(sizeof(long *) * path->num_of_islands);
    
    for (;columns < path->num_of_islands; columns++) {
        for (rows = 0; rows < path->num_of_islands; rows++) {
            matrix->tableprim_cmp[columns][rows] = matrix->prim_table[columns][rows];
        }
    }
}
