#include "list.h"
#include "status.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int list(){
    char path[1024] = "";
    strcat(path, getenv("HOME"));
    strcat(path, "/.config/workflow/lua");

    struct dirent *entry;
    DIR *pDir = opendir(path);

    int i;

    for(i = 0; entry = readdir(pDir); i++){
        if(entry->d_name[0] != '.'){
            printf("%s\n", entry->d_name);
        }
    }

    closedir(pDir);

    if(i == 2){
        fprintf(stderr, "workflow: no commands in %s\n", path);

        return ERROR_LIST;
    }

    return SUCCESS;
}
