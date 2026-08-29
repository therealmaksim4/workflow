#include "help.h"
#include "status.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int help(){
    char path[1024] = "";
    strcat(path, getenv("HOME"));
    strcat(path, "/.config/workflow/lua");

    char command[1024] = "";
    strcat(command, "ls -1 ");
    strcat(command, path);

    FILE *fp = popen(command, "r");
    char buffer[1024];

    while(fgets(buffer, sizeof(buffer), fp)){
        printf(buffer);
    }

    pclose(fp);

    return SUCCESS;
}
