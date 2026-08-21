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

    else if(argc != 2){
        fprintf(stderr, "workflow: only 1 argument is allowed\n");

        return 1;
    }

    char filepath[1024];
    strcat(filepath, getenv("HOME"));
    strcat(filepath, "/.config/workflow/lua/");
    strcat(filepath, argv[1]);
    strcat(filepath, "/main.lua");

    pid_t pid = fork();

    if(pid == 0){
        if(strcmp(argv[1], "help") == 0){
            execlp("ruby", "ruby", "/usr/src/workflow/ruby/help.rb", NULL);
        }

        else{
            execlp("luajit", "luajit", "-O3", filepath, NULL);
        }
    }

    int status;

    waitpid(pid, &status, 0);

    return 0;
}
