#include "edit_config.h"
#include "status.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int edit_config(char *text_editor){
    char command[1024] = "";
    strcat(command, text_editor);
    strcat(command, " ");
    strcat(command, getenv("HOME"));
    strcat(command, "/.config/workflow/config.lua");

    system(command);

    return SUCCESS;
}
