#include "pathfinder.h"

void mx_matrix_initialization(t_path *path, t_matrix *matrix) {
    int rows = 0;
    int columns = 0;

    matrix->prim_table = (long **) malloc(sizeof(long *) * path->num_of_islands);
    for (int i = 0; i < path->num_of_islands; i++)
        matrix->prim_table[i] = (long*) malloc(sizeof(long *) * path->num_of_islands);
    
    for (; columns < path->num_of_islands; columns++) {
        for (rows = 0; rows < path->num_of_islands; rows++) {
            if (columns == rows)
                matrix->prim_table [columns][rows] = 0;
            else 
                matrix->prim_table[columns][rows] = INT_MAX;
        }
    }
}

void mx_fillmatrix(t_path *path, t_matrix *matrix) {
    for (int i = 0; i < path->num_of_islands; i++ ) {
        for (int j = 0; j < path->num_of_islands; j++) {
            if (matrix->prim_table[i][j] == INT_MAX) {
                for (int k = 0; path->words[k]; k++) {
                    if (mx_strcmp (path->islands_uniq[i], path->words[k]) == 0 &&
                         mx_strcmp (path->islands_uniq[j], path->words[k+1]) == 0) {
                            matrix->prim_table[i][j] = mx_atoi(path->words[k+2]);
                            matrix->prim_table[j][i] = mx_atoi(path->words[k+2]);
                    }
                }
             }
         }
    }
}
