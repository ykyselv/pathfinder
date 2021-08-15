#include "pathfinder.h"

void mx_parsing1(char *argv[], t_path *path) {

path->file_to_str = mx_file_to_str(argv[1]);
int counter = 0;

    for (; path->file_to_str[counter] != ('\n'); counter++) {}

    char *tmp = path->file_to_str + counter;
        path->sepratestr = mx_strsplit(tmp, '\n');
        path->countroute = 0;
    while (path->sepratestr[path->countroute] != NULL) {
        path->countroute++;   
    }
}
