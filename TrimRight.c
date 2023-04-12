#include <stdio.h>

void TrimRight(char* s) {
    if(!s) {
        return;
    }
    char* idxSpace = 0;
    char* idxNonSpace = 0;
    char* current = NULL;
    for(current = s; *current; current++) {
        if(*current == 0x20) {
            if(idxNonSpace > idxSpace) {
                idxSpace = current;
            }
        } else {
            idxNonSpace = current;
        }
    }
    char* end = current;
    int flag = 0;
    if(idxNonSpace < idxSpace) {
        flag = 1;
        
    } else if(idxSpace == idxNonSpace && *s) {
        idxSpace = s;
        flag = 1;
    }
    for(current = idxSpace; current < end && flag; current++) {
        *current = '\0';
    }
}