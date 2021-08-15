#include "pathfinder.h"

static void print_shortest_path(t_path *path, t_matrix *matrix);
static bool check_shortest_path(t_path *path, t_matrix *matrix, int k);
static void print_path_and_route(t_path *path, t_matrix *matrix);
static void print_distance(t_path *path, t_matrix *matrix);

void mx_output_results(t_path *path, t_matrix *matrix) {
    for (int i = 0; i < path->num_of_islands; i++) {
        for (int j = i + 1; j < path->num_of_islands; j++) {
            matrix->route = (int *)malloc(sizeof(int) * (path->num_of_islands));
            matrix->len = 1;
            matrix->route[0] = j;
            matrix->route[matrix->len] = i;
            print_shortest_path(path, matrix);
            free(matrix->route);
        }
    }
}

static void print_shortest_path(t_path *path, t_matrix *matrix) {
    for (int k = 0; k < path->num_of_islands; k++) {
        if (k != matrix->route[matrix->len]
            && check_shortest_path(path, matrix, k)) {
            matrix->route[++matrix->len] = k;
            print_shortest_path(path, matrix);
            matrix->len--;
        }
    }
    if (matrix->route[matrix->len] != matrix->route[0])
        return;
    print_path_and_route(path, matrix);
    print_distance(path, matrix);
}

static bool check_shortest_path(t_path *path, t_matrix *matrix, int k) {
    int i = matrix->route[matrix->len];
    int j = matrix->route[0];

    if ((matrix->tableprim_cmp[i][k] == matrix->prim_table[i][j] - matrix->prim_table[k][j])
        && matrix->tableprim_cmp[i][k] != INT_MAX)
        return true;
    return false;
}

static void print_path_and_route(t_path *path, t_matrix *matrix) {
    mx_boundary();
    mx_printstr("Path: ");
    mx_printstr(path->islands_uniq[matrix->route[1]]);
    mx_printstr(" -> ");
    mx_printstr(path->islands_uniq[matrix->route[matrix->len]]);
    mx_printstr("\n");
    mx_printstr("Route: ");
    for (int i = 1; i < matrix->len + 1; ) {
        mx_printstr(path->islands_uniq[matrix->route[i]]);
        ++i < matrix->len + 1 ? mx_printstr(" -> ") : mx_printstr("");
    }
    mx_printstr("\n");
}

static void print_distance(t_path *path, t_matrix *matrix) {
    int sum = 0;

    mx_printstr("Distance: ");
    for (int i = 1; i < matrix->len; i++){
        mx_printint(matrix->tableprim_cmp[matrix->route[i]][matrix->route[i + 1]]);
        sum += matrix->tableprim_cmp[matrix->route[i]][matrix->route[i + 1]];
        if (i < matrix->len - 1)
            mx_printstr(" + ");
        else if (i > 1) {
            mx_printstr(" = ");
            mx_printint(sum);
        }
    }
    mx_printstr("\n");
    mx_boundary();
}
