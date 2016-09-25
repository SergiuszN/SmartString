#ifndef CCLASECOMPILER_STRINGARRAY_H
#define CCLASECOMPILER_STRINGARRAY_H

#include "../String/String.h"

typedef struct SmartStringArrayBlock {
    // variables
    struct SmartString field;
    struct SmartStringArrayBlock *next;
    struct SmartStringArrayBlock *prev;

    // functions
    struct SmartStringArrayBlock* (*pushBack) (struct SmartStringArrayBlock*, struct SmartString);
    struct SmartStringArrayBlock* (*getBlock) (struct SmartStringArrayBlock*, int);
    void (*destroy) (struct SmartStringArrayBlock*, int);

} SmartStringArrayBlock;

typedef struct SmartStringArray {
    // variables
    int length;
    struct SmartStringArrayBlock *head;
    struct SmartStringArrayBlock *current;

    // functions
    void (*add)(struct SmartStringArray*, struct SmartString);
    SmartString (*get)(struct SmartStringArray*, int);
    void (*destroy) (struct SmartStringArray*);

} SmartStringArray;


SmartStringArrayBlock* new_SmartStringArrayBlock(struct SmartString);
SmartStringArray new_SmartStringArray(struct SmartString);

#endif //CCLASECOMPILER_STRINGARRAY_H
