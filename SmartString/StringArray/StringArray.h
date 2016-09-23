#ifndef CCLASECOMPILER_STRINGARRAY_H
#define CCLASECOMPILER_STRINGARRAY_H

#include "../String/String.h"

typedef struct StringArrayBlock {
    struct SmartString *left;
    struct SmartString *right;
    struct SmartString value;
} StringArrayBlock;



#endif //CCLASECOMPILER_STRINGARRAY_H
