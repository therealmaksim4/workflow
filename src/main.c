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
#include "macros.h"

void usage(){
    printf("workflow %s\n", VERSION);
    printf("Usage: [-h] [-l] [-g command_name] [-c text_editor] [-d doc] [-R command_name] [-r command_name]\n");
}

void version(){
    printf("workflow %s\n", VERSION);
}

int main(int argc, char *argv[]){
    if(argc == 1){
        usage();

        return SUCCESS;
    }

    else if(argc > 3){
        fprintf(stderr, "workflow: too many arguments given\n");

        return ERROR;
    }

    struct stat buffer;
    int opt;

    while((opt = getopt(argc, argv, "hvlg:c:d:R:r:")) != -1){
        switch(opt){
            case 'h':
                usage();
                
                return SUCCESS;
                break;

            case 'v':
                version();

                return SUCCESS;
                break;

            case 'l':
                return list();
                break;

            case 'g':
                return generate(argv[2]);
                break;

            case 'c':
                return edit_config(argv[2]);
                break;

            case 'd':
                return docs(argv[2]);
                break;

            case 'R':
                return remove_command(argv[2]);
                break;

            case 'r':
                goto lua;
                break;
        }
    }

    return ERROR;

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

    else if(stat(filepath, &buffer) != 0){
        fprintf(stderr, "workflow: no %s command\n", command);

        return ERROR;
    }

    else{
        execlp("lua", "lua", filepath, NULL);
    }
}
