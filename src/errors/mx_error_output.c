 #include "pathfinder.h"

void mx_error_output(int line) {
    char *linenbr = mx_itoa(line);
    
    mx_printerr("error: line ");
    mx_printerr(linenbr);
    mx_printerr(" is not valid\n");
    free(linenbr);
    exit(1);
}
