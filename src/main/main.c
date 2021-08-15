#include "pathfinder.h"

void mx_set_unique(char **unique, char **src, int size_src);

int main(int argc, char **argv) {
    mx_command_line_arg_err(argc,argv);
    // system("leaks -q pathfinder");
    mx_fileerr(argv[1]);
    // system("leaks -q pathfinder");
    mx_emptyfile(argv[1]);
    // system("leaks -q pathfinder");
    //  system("leaks -q pathfinder");
    t_path *path = (t_path *)malloc(sizeof(t_path));
    t_matrix *matrix = (t_matrix *)malloc(sizeof(t_matrix));
    mx_parsing1(argv,path);
    // system("leaks -q pathfinder");
    mx_1stline_invalid(argv, path); 
    // system("leaks -q pathfinder");
    mx_invalidline(path->sepratestr, path);
    // system("leaks -q pathfinder");
    parse_mode(argv, path);
    // system("leaks -q pathfinder");
    mx_isldup(path->words, path);
    // system("leaks -q pathfinder");
    mx_dupbridge(path);
    // system("leaks -q pathfinder");
    mx_sumof_bridgelen(path);
    // system("leaks -q pathfinder");

    mx_matrix_initialization(path, matrix);
    // system("leaks -q pathfinder");
    mx_fillmatrix(path, matrix);
    mx_tableprim_cmp (path, matrix);
    // system("leaks -q pathfinder");
    mx_algorithm (path, matrix);
    mx_output_results(path, matrix);
    // system("leaks -q pathfinder");
}
