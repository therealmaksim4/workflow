#include "generate.h"
#include "status.h"
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>

int generate(const char *command_name){
    char filepath[1024] = "";
    strcat(filepath, getenv("HOME"));
    strcat(filepath, "/.config/workflow/lua/");
    strcat(filepath, command_name);

    mkdir(filepath, 0755);

    strcat(filepath, "/main.lua");

    FILE *pFile = fopen(filepath, "w");
    char content[1024] = "dofile(\"/usr/src/workflow/bin/all.luac\")\n"
        "\n"
        "global.on_command_start()\n"
        "\n"
        "check_command_name_color(\"";
    strcat(content, command_name);
    strcat(content, "\")\n"
            "\n"
            "-- Your code goes here\n"
            "\n"
            "check_command_name_color(\"");
    strcat(content, command_name);
    strcat(content, "\")\n"
            "\n"
            "global.on_command_end()");

    fprintf(pFile, content);

    fclose(pFile);

    return SUCCESS;
}
