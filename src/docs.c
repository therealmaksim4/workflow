#include "docs.h"
#include <stdio.h>
#include <string.h>
#include "status.h"
#include <ctype.h>
#include <sys/stat.h>

int docs(char *doc){
    for(int i = 0; doc[i]; i++){
        doc[i] = toupper(doc[i]);
    }

    char filepath[1024] = "";
    strcat(filepath, "/usr/src/workflow/");
    strcat(filepath, doc);
    strcat(filepath, ".md");

    struct stat stat_buffer;

    if(stat(filepath, &stat_buffer) == 0){
        FILE *pFile = fopen(filepath, "r");
        char buffer[1024];

        while(fgets(buffer, sizeof(buffer), pFile)){
            printf("%s", buffer);
        }

        fclose(pFile);
    }

    else{
        fprintf(stderr, "workflow: %s is not a doc\n", doc);

        return ERROR_DOCS;
    }

    return SUCCESS;
}
