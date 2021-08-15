 #include "pathfinder.h"

void mx_fileerr(char *file) {
    int fd = open(file, O_RDONLY);
    
        if (fd <= 0) {
            mx_printerr("error: file ");
            mx_printerr(file);
            mx_printerr(" does not exist\n");
            close(fd);
            exit(1);
        }
}
