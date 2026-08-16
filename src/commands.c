#include "commands.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int command_interpreter(char *command){
    if(strcmp(command, "help") == 0){
        execlp("luajit", "luajit", "/usr/src/workflow/lua/help.lua", NULL);
    }

    else if(strcmp(command, "cheat") == 0){
        execlp("luajit", "luajit", "/usr/src/workflow/lua/cheat.lua", NULL);
    }

    else{
        fprintf(stderr, "Invalid option\n");

        return 1;
    }

    return 0;
}
