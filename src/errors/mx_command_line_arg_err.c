 #include "pathfinder.h"


void mx_command_line_arg_err(int argc, char **argv) {
    
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder");
        mx_printerr(argv[1]);
        mx_printerr("\n");
        exit(1);
    }
}
