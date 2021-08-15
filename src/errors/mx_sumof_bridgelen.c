#include "pathfinder.h"

void mx_sumof_bridgelen(t_path *path) {
    long counter = 0;
    
    for (int i = 0; i < path->countroute; i++) {
        if(path->routes[i] < 0) {
            mx_printerr("error: sum of bridges lengths is too big\n");
            exit(1);
        }
        counter = counter + path->routes[i];
    }
    if (counter > INT_MAX || counter < 0) {
        mx_printerr("error: sum of bridges lengths is too big\n");
        exit(1);
    }
}
