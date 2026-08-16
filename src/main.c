#include <stdio.h>
#include "commands.h"

int main(int argc, char *argv[]){
    if(argc == 1){
        fprintf(stderr, "Type: \"workflow help\" for a help menu\n");

        return 1;
    }

    else if(argc != 2){
        fprintf(stderr, "Only 1 argument is allowed\n");

        return 1;
    }

    int retval = command_interpreter(argv[1]);

    return retval;
}
