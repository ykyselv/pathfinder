#include "pathfinder.h"

int mx_set_unique(char **unique, char **src, int size_src);

void parse_mode(char *argv[], t_path *path) {

    //int num_of_islands
    path->num_of_islands = mx_atoi(path->file_to_str);
    // массив путей
    char *tmpor = mx_strnew(mx_strlen(path->file_to_str));
    tmpor = mx_strcpy(tmpor, path->file_to_str);

    for (int i = 0; i < mx_strlen(path->file_to_str); i++) {
        if (tmpor[i] == '-' || tmpor[i] == ',' || tmpor[i] == '\n')
            tmpor[i] = 127;
    }
    int j = 0;
        
    path->words = mx_strsplit(tmpor, 127);
    char **routstemp = (char**) malloc(sizeof(char*) * path->countroute);
    free(tmpor);

    for (int i = 1; path->words[i]; i = i + 3) {
        routstemp[j] = path->words[i + 2];
        j++;
    }

    path->routes = (int *)malloc(sizeof(int) * path->countroute);

    for (int k = 0; k < path->countroute; k++) {
        path->routes[k] = mx_atoi(routstemp[k]);
    }
    free (routstemp);
    for (int k = 0; k < path->countroute; k++) {
        if(path->routes[k] == 0)
            mx_error_output(k + 2);
    }
    // вывести острова
    path->islands = (char**) malloc(sizeof(char*) * (path->countroute * 2));
    path->islands2 = (char**) malloc(sizeof(char*) * (path->countroute));
        int i = 1;
        int p = 0;

    while (path->words[i]) {
        path->islands[p] = path->words[i];
        i++;
        path->islands2[p] = path->words[i];
        i = i + 2;
        p++;
    }

    // выводим уникальные острова


    // int t = 0;

    path->islands_uniq = (char**)malloc(sizeof(char *) * (path->num_of_islands + 1));
    for (int i = 0; i < path -> num_of_islands + 1; i++)
        path->islands_uniq[i] = NULL;

    for (int i = 0; i < path -> countroute; i++)
    {
        int j = 0;
        for (; path->islands_uniq[j] != NULL && mx_strcmp(path -> islands_uniq[j], path -> islands[i]) != 0; j++) {}
        if (path->islands_uniq[j] == NULL) 
            path -> islands_uniq[j] = mx_strdup(path -> islands[i]);
        j = 0;
        for (; path->islands_uniq[j] != NULL && mx_strcmp(path -> islands_uniq[j], path -> islands2[i]) != 0; j++) {}
        if (path->islands_uniq[j] == NULL) 
            path -> islands_uniq[j] = mx_strdup(path -> islands2[i]);
    }

    // for (int i = 0; i < path->num_of_islands; i++) {
    //     path->islands_uniq[i] = (char *)malloc(1);
    //     path->islands_uniq[i][0] = '\0';
    // }

    // int flag = mx_set_unique(path->islands_uniq, path->islands, path->countrout) + 
    // mx_set_unique(path->islands_uniq, path->islands2, path->countrout);

    // if(flag != path->num_of_islands) {
    //     mx_printerr("error: invalid number of islands");
    //     mx_printerr("\n");
    //     exit (0);
    // }
}

// int mx_set_unique(char **unique, char **src, int size_src) {

//     int counter = 0;

//     for (int i = 0; i < size_src; i++) {
//         for (int j = 0;; j++) {
//             if (unique[j]) {
//                 if (mx_strcmp(unique[j], src[i]) == 0)
//                     break;
//                 if (unique[j][0] == '\0') {
//                     free(unique[j]);
//                     unique[j] = mx_strdup(src[i]);
//                     counter++;
//                     break;
//                 }
//             }
//             else {
//                 mx_printerr("error: invalid number of islands\n");
//                 exit(1);
//             }
            
//         }
//     }
//     return (counter);
//   }

