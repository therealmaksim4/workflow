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

    char filepath[1024];
    strcat(filepath, getenv("HOME"));
    strcat(filepath, "/.config/workflow/lua/");
    strcat(filepath, argv[1]);
    strcat(filepath, "/main.lua");

    pid_t pid = fork();

    if(pid == 0){
        if(strcmp(argv[1], "help") == 0){
            if(argc != 2){
                fprintf(stderr, "workflow: too much arguments given\n");
            }

            else{
                execlp("ruby", "ruby", "/usr/src/workflow/ruby/help.rb", NULL);
            }
        }

        else if(strcmp(argv[1], "generate") == 0){
            if(argc != 3){
                fprintf(stderr, "workflow: 3 arguments must be given when running generate.rb\n");
            }

            else{
                execlp("ruby", "ruby", "/usr/src/workflow/ruby/generate.rb", argv[2], NULL);
            }
        }

        else if(strcmp(argv[1], "config") == 0){
            if(argc != 3){
                fprintf(stderr, "workflow: 3 arguments must be given when running generate.rb\n");
            }

            else{
                execlp("ruby", "ruby", "/usr/src/workflow/ruby/edit_config.rb", argv[2], NULL);
            }
        }

        else{
            if(argc != 2){
                fprintf(stderr, "workflow: too much arguments given\n");
            }

            else{
                execlp("lua", "lua", filepath, NULL);
            }
        }
    }

    int status;

    waitpid(pid, &status, 0);

    return 0;
}
