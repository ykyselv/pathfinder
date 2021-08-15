#include "pathfinder.h"

void mx_algorithm (t_path *path, t_matrix *matrix) {
    int iter = 0; 

    for (int k = 0; k < path->num_of_islands; k++) {
        for (int i = 0; i < path->num_of_islands; i++) {
            for (int j = 0; j < path->num_of_islands; j++) {
                if (matrix->prim_table[i][k] != INT_MAX &&
                    matrix->prim_table[k][j] != INT_MAX &&
                    matrix->prim_table[i][j] > matrix->prim_table[i][k] + 
                    matrix->prim_table[k][j]) {
                    matrix->prim_table[i][j] = matrix->prim_table[i][k] + 
                    matrix->prim_table[k][j];
                    iter++;
                    }
            }
        }
        iter = 0;
    }
}
