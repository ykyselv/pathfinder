#pragma once

#include "../libmx/inc/libmx.h"


#define INT_MAX  2147483647
#define INT_MIN  -2147483648


// typedef struct p_list {
// char **exit_isl;
// struct p_list *next;
// }           k_list;



typedef struct s_path {
    char **words;
    // done
    int *routes;
    // done
    char *file_to_str;
    // done
    int num_of_islands;
    // done
    char **islands;   
    // done
    int countroute;
    char **islands2;
    char **islands_uniq;
    char **sepratestr;
    // k_list *list;
}             t_path;

typedef struct s_matrix {
    int len;
    int *route;
    long int **prim_table;
    long int **tableprim_cmp;
}              t_matrix;


void mx_command_line_arg_err(int argc, char **argv);
void mx_fileerr(char *file);
void mx_emptyfile(char *file);
void mx_1stline_invalid(char *argv[], t_path *path);
void mx_parsing1(char *argv[], t_path *path);
void mx_error_output(int line);
void parse_mode(char *argv[], t_path *path);
void mx_dupbridge(t_path *path);
void mx_sumof_bridgelen(t_path *path);
void mx_invalidline(char **str, t_path *path);
void mx_isldup(char **str, t_path *path);
// void mx_invalidline(t_path *path);
void mx_matrix_initialization(t_path *path, t_matrix *matrix);
void mx_tableprim_cmp (t_path *path, t_matrix *matrix);
void mx_fillmatrix(t_path *path, t_matrix *matrix);
void mx_algorithm (t_path *path, t_matrix *matrix);
void mx_boundary();
void mx_output_results(t_path *path, t_matrix *matrix);
