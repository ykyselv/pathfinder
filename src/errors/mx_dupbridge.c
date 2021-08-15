#include "pathfinder.h"

void mx_dupbridge(t_path *path) {
 char **temp;
 char **lightpart = (char**) malloc(sizeof(char*) * (path->countroute));

for (int i = 0; i < path->countroute; i++) {
    temp = mx_strsplit(path->sepratestr[i], ',');
    lightpart[i] = mx_strdup(temp[0]);
    free(temp[0]);
    free(temp[1]);
    free(temp);
}
for (int j = 0; j < path->countroute; j++) {
    for(int k = j + 1; k < path->countroute;k++) {
        if(mx_strcmp(lightpart[j],lightpart[k]) == 0) {
            mx_printerr("error: duplicate bridges\n");
            exit(1);
        }   
    }
}
for (int i = 0; i < path->countroute; i++)
    free(lightpart[i]);
free(lightpart);
}
