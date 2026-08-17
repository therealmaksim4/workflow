#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    if(argc == 1){
        printf("workflow is a CLI tool that helps you build scripts that will enhance your coding\n");
        printf("Put your scripts in ~/.config/workflow/lua and the next time you run workflow type \"workflow your_command\"\n");

        return 1;
    }

    else if(argc != 2){
        fprintf(stderr, "workflow: only 1 argument is allowed\n");

        return 1;
    }

    execlp("luajit", "luajit", "/usr/src/workflow/lua/commands.lua", argv[1], NULL);

    return 0;
}
