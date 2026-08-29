#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "docs.h"
#include "status.h"
#include "edit_config.h"
#include "help.h"
#include "generate.h"

int main(int argc, char *argv[]){
    if(argc == 1){
        printf("Put your scripts in ~/.config/workflow/lua and the next time you run workflow type \"workflow your_command\"\n");
        printf("To see all commands type \"workflow help\"\n");

        return SUCCESS;
    }

    char command[1024];
    strcpy(command, argv[1]);

    char filepath[1024] = "";
    strcat(filepath, getenv("HOME"));
    strcat(filepath, "/.config/workflow/lua/");
    strcat(filepath, command);
    strcat(filepath, "/main.lua");

    struct stat buffer;

    if(strcmp(command, "help") == 0){
        goto help;
    }

    else if(strcmp(command, "generate") == 0){
        goto generate;
    }

    else if(strcmp(command, "config") == 0){
        goto edit_config;
    }

    else if(strcmp(command, "docs") == 0){
        goto documentation;
    }

    else{
        goto lua;
    }

    return SUCCESS;

lua:
    if(system("lua -v > /dev/null 2>&1") != 0){
        fprintf(stderr, "workflow: lua interpreter is not installed\n");

        return ERROR_LUA;
    }

    else if(argc != 2){
        fprintf(stderr, "workflow: too much arguments given\n");

        return ERROR_ARGS;
    }

    else if(stat(filepath, &buffer) != 0){
        fprintf(stderr, "workflow: no %s command\n", command);

        return ERROR_LUA;
    }

    else{
        execlp("lua", "lua", filepath, NULL);
    }

generate:
    if(argc != 3){
        fprintf(stderr, "workflow: 2 arguments must be given when running generate\n");

        return ERROR_ARGS;
    }

    else{
        return generate(argv[2]);
    }

edit_config:
    if(argc != 3){
        fprintf(stderr, "workflow: 2 arguments must be given when running config\n");

        return ERROR_ARGS;
    }

    else{
        return edit_config(argv[2]);
    }

help:
    if(argc != 2){
        fprintf(stderr, "workflow: too much arguments given\n");

        return ERROR_ARGS;
    }

    else{
        return help();
    }

documentation:
    if(argc != 3){
        fprintf(stderr, "workflow: 2 arguments must be given when running docs\n");

        return ERROR_ARGS;
    }

    else{
        return docs(argv[2]);
    }
}
