#ifndef CCLASECOMPILER_JAVAFUNCTION_H
#define CCLASECOMPILER_JAVAFUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include "../../SmartString/SmartString.h"

typedef struct JavaFunction {
    //variables

    //functions
    void (*mainFunctionMacro) (struct SmartString*);
    struct SmartStringArray (*functionTokenDelimiter) (struct SmartString*);
    void (*run) (struct JavaFunction*, struct SmartString*);

} JavaFunction;

JavaFunction new_JavaFunction();

#endif //CCLASECOMPILER_JAVAFUNCTION_H
