#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    if(argc == 1){
        printf("Put your scripts in ~/.config/workflow/lua and the next time you run workflow type \"workflow your_command\"\n");
        printf("To see all commands type \"workflow help\"\n");

        return 0;
    }

    char *command = argv[1];

    char filepath[1024];
    strcat(filepath, getenv("HOME"));
    strcat(filepath, "/.config/workflow/lua/");
    strcat(filepath, argv[1]);
    strcat(filepath, "/main.lua");

    pid_t pid = fork();

    if(pid == 0){
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
    }

    int status;

    waitpid(pid, &status, 0);

    goto exit;

lua:
    if(argc != 2){
        fprintf(stderr, "workflow: too much arguments given\n");
    }

    else{
        execlp("lua", "lua", filepath, NULL);
    }

generate:
    if(argc != 3){
        fprintf(stderr, "workflow: 3 arguments must be given when running generate.rb\n");
    }

    else{
        execlp("ruby", "ruby", "/usr/src/workflow/ruby/generate.rb", argv[2], NULL);
    }

edit_config:
    if(argc != 2){
        fprintf(stderr, "workflow: 3 arguments must be given when running edit_config.rb\n");
    }

    else{
        execlp("ruby", "ruby", "/usr/src/workflow/ruby/edit_config.rb", argv[2], NULL);
    }

help:
    if(argc != 2){
        fprintf(stderr, "workflow: too much arguments given\n");
    }

    else{
        execlp("ruby", "ruby", "/usr/src/workflow/ruby/help.rb", NULL);
    }

exit:
    return 0;
}
