#include "remove_command.h"
#include "status.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

int remove_command(const char *command_name){
    char filepath[1024] = "";
    strcat(filepath, getenv("HOME"));
    strcat(filepath, "/.config/workflow/lua/");
    strcat(filepath, command_name);

    struct stat buffer;

    if(stat(filepath, &buffer) != 0){
        fprintf(stderr, "workflow: no %s command\n", command_name);

        return ERROR_REMOVE_COMMAND;
    }

    pid_t pid = fork();

    if(pid == 0){
        execlp("rm", "rm", "-rf", filepath, NULL);
    }

    int status;

    waitpid(pid, &status, 0);

    return SUCCESS;
}
