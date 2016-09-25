#ifndef CCLASECOMPILER_JAVACLASS_H
#define CCLASECOMPILER_JAVACLASS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../SmartString/SmartString.h"

typedef struct JavaClass {
    //variables

    //functions
    void (*classMacro) (struct SmartString*);
} JavaClass;

JavaClass new_JavaClass();
void JavaClassClearClassName(struct SmartString*);

#endif //CCLASECOMPILER_JAVACLASS_H
