#ifndef CCLASECOMPILER_SERVICE_H
#define CCLASECOMPILER_SERVICE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../SmartString/SmartString.h"

typedef struct Service {
    //variables

    //functions
    struct SmartString (*fileReadAllText) (char* fileName);
    void (*deleteAllComments) (SmartString*);
} Service;

Service new_Service();


#endif //CCLASECOMPILER_SERVICE_H
