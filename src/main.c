#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "docs.h"
#include "status.h"
#include "edit_config.h"
#include "list.h"
#include "generate.h"
#include "remove_command.h"

void usage(){
    printf("Usage: [-h] [-l] [-g command_name] [-c text_editor] [-d doc] [-R command_name] [-r command_name]\n");
}

int main(int argc, char *argv[]){
    if(argc == 1){
        usage();

        return SUCCESS;
    }

    struct stat buffer;
    int opt;

    while((opt = getopt(argc, argv, "hlgcdRr:")) != -1){
        switch(opt){
            case 'h':
                usage();
                
                return SUCCESS;
                break;

            case 'l':
                goto list;
                break;

            case 'g':
                goto generate;
                break;

            case 'c':
                goto edit_config;
                break;

            case 'd':
                goto documentation;
                break;

            case 'R':
                goto remove_command;
                break;

            case 'r':
                goto lua;
                break;
        }
    }

    return SUCCESS;

lua:
    char command[1024];
    strcpy(command, argv[2]);

    char filepath[1024] = "";
    strcat(filepath, getenv("HOME"));
    strcat(filepath, "/.config/workflow/lua/");
    strcat(filepath, command);
    strcat(filepath, "/main.lua");

    if(system("lua -v > /dev/null 2>&1") != 0){
        fprintf(stderr, "workflow: lua interpreter is not installed\n");

        return ERROR;
    }

    else if(argc != 3){
        fprintf(stderr, "workflow: too much arguments given\n");

        return ERROR;
    }

    else if(stat(filepath, &buffer) != 0){
        fprintf(stderr, "workflow: no %s command\n", command);

        return ERROR;
    }

    else{
        execlp("lua", "lua", filepath, NULL);
    }

generate:
    if(argc != 3){
        fprintf(stderr, "workflow: 2 arguments must be given when running generate\n");

        return ERROR;
    }

    else{
        return generate(argv[2]);
    }

edit_config:
    if(argc != 3){
        fprintf(stderr, "workflow: 2 arguments must be given when running config\n");

        return ERROR;
    }

    else{
        return edit_config(argv[2]);
    }

list:
    if(argc != 2){
        fprintf(stderr, "workflow: too much arguments given\n");

        return ERROR;
    }

    else{
        return list();
    }

documentation:
    if(argc != 3){
        fprintf(stderr, "workflow: 2 arguments must be given when running docs\n");

        return ERROR;
    }

    else{
        return docs(argv[2]);
    }

remove_command:
    if(argc != 3){
        fprintf(stderr, "workflow: 2 arguments must be given when running docs\n");

        return ERROR;
    }

    else{
        return remove_command(argv[2]);
    }
}
