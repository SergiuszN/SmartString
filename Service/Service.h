#ifndef CCLASECOMPILER_SERVICE_H
#define CCLASECOMPILER_SERVICE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../SmartString/SmartString.h"

typedef struct Service {
    //variables

    //functions
    struct SmartString (*fileReadAllLine) (char* fileName);

    //destructor
    void (*destroyService)(struct Service*);
} Service;

Service new_Service();


#endif //CCLASECOMPILER_SERVICE_H
