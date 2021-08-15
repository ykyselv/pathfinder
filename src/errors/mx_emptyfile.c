#include "pathfinder.h"

void mx_emptyfile(char *file) {
    char *newstr = mx_file_to_str(file);
    
    if (mx_strlen(newstr) == 0) {
        mx_printerr("error: file ");
        mx_printerr(file);
        mx_printerr(" is empty\n");
        exit(1);
    }
    free(newstr);
}
