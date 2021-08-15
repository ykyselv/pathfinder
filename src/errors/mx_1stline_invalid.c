#include "pathfinder.h"

void mx_1stline_invalid(char *argv[], t_path *path) {
    
    for(int i = 0; path->file_to_str[i]!= '\n'; i++) {
        if(!mx_isdigit(path->file_to_str[i])) {
            mx_printerr("error: line 1 is not valid\n"); 
            exit(1);
        }
    }
}
