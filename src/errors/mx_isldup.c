#include "pathfinder.h"

void mx_isldup(char **str, t_path *path) {
    int counter = 1;
    
    for (int i = 1; i <= path->countroute * 3; i = i + 3) {
        counter++;
        if (mx_strcmp(str[i], str[i + 1]) == 0) 
            mx_error_output(counter);
    }
}
