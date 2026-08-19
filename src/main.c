#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

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

    char filepath[1024];
    strcat(filepath, getenv("HOME"));
    strcat(filepath, "/.config/workflow/lua/");
    strcat(filepath, argv[1]);
    strcat(filepath, ".lua");

    execlp("luajit", "luajit", filepath, NULL);

    return 0;
}
