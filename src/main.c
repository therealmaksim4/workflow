#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

typedef enum{
    SUCCESS = 0,
    ERROR_ARGS = 1,
    ERROR_LUA = 2,
    ERROR_RUBY = 3,
}Status;

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
    if(system("ruby -v > /dev/null 2>&1") != 0){
        fprintf(stderr, "workflow: ruby interpreter not installed\n");

        return ERROR_RUBY;
    }

    else if(argc != 3){
        fprintf(stderr, "workflow: 3 arguments must be given when running generate.rb\n");

        return ERROR_ARGS;
    }

    else{
        execlp("ruby", "ruby", "/usr/src/workflow/ruby/generate.rb", argv[2], NULL);
    }

edit_config:
    if(system("ruby -v > /dev/null 2>&1") != 0){
        fprintf(stderr, "workflow: ruby interpreter not installed\n");

        return ERROR_RUBY;
    }

    else if(argc != 2){
        fprintf(stderr, "workflow: 3 arguments must be given when running edit_config.rb\n");

        return ERROR_ARGS;
    }

    else{
        execlp("ruby", "ruby", "/usr/src/workflow/ruby/edit_config.rb", argv[2], NULL);
    }

help:
    if(system("ruby -v > /dev/null 2>&1") != 0){
        fprintf(stderr, "workflow: ruby interpreter not installed\n");

        return ERROR_RUBY;
    }

    else if(argc != 2){
        fprintf(stderr, "workflow: too much arguments given\n");

        return ERROR_ARGS;
    }

    else{
        execlp("ruby", "ruby", "/usr/src/workflow/ruby/help.rb", NULL);
    }
}
