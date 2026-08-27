#include "docs.h"
#include <stdio.h>
#include <string.h>
#include "status.h"

void readme(){
    FILE *pFile = fopen("/usr/src/workflow/README.md", "r");
    char buffer[1024];

    while(fgets(buffer, sizeof(buffer), pFile)){
        printf("%s", buffer);
    }

    fclose(pFile);
}

void commands(){
    FILE *pFile = fopen("/usr/src/workflow/COMMANDS.md", "r");
    char buffer[1024];

    while(fgets(buffer, sizeof(buffer), pFile)){
        printf("%s", buffer);
    }

    fclose(pFile);
}

void contributing(){
    FILE *pFile = fopen("/usr/src/workflow/CONTRIBUTING.md", "r");
    char buffer[1024];

    while(fgets(buffer, sizeof(buffer), pFile)){
        printf("%s", buffer);
    }

    fclose(pFile);
}

int docs(char *doc){
    if(strcmp(doc, "commands") == 0){
        commands();
    }

    else if(strcmp(doc, "readme") == 0){
        readme();
    }

    else if(strcmp(doc, "contributing") == 0){
        contributing();
    }

    else{
        fprintf(stderr, "workflow: %s is not a doc\n", doc);

        return ERROR_ARGS;
    }
}
