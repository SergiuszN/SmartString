#ifndef CCLASECOMPILER_STRINGARRAY_H
#define CCLASECOMPILER_STRINGARRAY_H

#include "../String/String.h"

typedef struct StringArrayBlock {
    struct SmartString *left;
    struct SmartString *right;
    struct SmartString value;
} StringArrayBlock;

typedef struct SmartStringArray {
    // variables
    int length;
    int position;
    struct StringArrayBlock* array;

    // functions
    void (*addString) (struct SmartStringArray*, struct SmartString*);
    struct SmartString (*getString) (struct SmartStringArray*, int);
} SmartStringArray;


#endif //CCLASECOMPILER_STRINGARRAY_H
