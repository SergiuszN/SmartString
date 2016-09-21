#include "Service.h"
#include <stdio.h>
#include <string.h>

char** explode(const char *src, const char token, int* len) {
    printf("%s\n",src);
    char** temp;
    return temp;
}

int count_chars(const char *src) {
    pch=strchr(str,'s');
    while (pch!=NULL)
    {
        printf ("found at %d\n",pch-str+1);
        pch=strchr(pch+1,'s');
    }
}

service Service() {
    struct service obj;
    obj.explode = &explode;
    return obj;
}