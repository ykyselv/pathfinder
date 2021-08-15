#include "pathfinder.h"

void mx_invalidline(char **str, t_path *path) {

    for (int i = 0; str[i] != NULL; i++) { 
        if (!mx_atoi(&str[i][mx_strlen(str[i])-1]) && (str[i][mx_strlen(str[i])-1]) != '0') 
            mx_error_output(i + 2);

        for (int j = 0; str[i][j] != '\0'; j++) {
            if (str[i][j] != '-' && !mx_isalpha(str[i][j]) && str[i][j] != ',' && !mx_isdigit(str[i][j]))
                mx_error_output(i + 2);
            if (str[i][j] == '-' && !mx_isalpha(str[i][j - 1]))
                mx_error_output(i + 2);
            if (str[i][j] == '-' && !mx_isalpha(str[i][j + 1])) 
                mx_error_output(i + 2);
            if (str[i][j] == ',' && !mx_isdigit(str[i][j + 1]))
                mx_error_output(i + 2);
            if ((mx_isdigit(str[i][j]) && str[i][j - 1] != ',') && (mx_isdigit(str[i][j]) && !mx_isdigit(str[i][j - 1])))
                mx_error_output(i + 2);
        }
         
        for (int k = 0; str[i][k] != '\0'; k++) {

            if (str[i][k] == '-') {
                for (int p = k + 1; str[i][p] != '\0'; p++) {
                    if (str[i][p] == '-')
                    mx_error_output(i + 2);
                }
                break;
            }
            else if (str[i][k] == ',') {
                mx_error_output(i + 2);
            }
        }
    }
}

            
