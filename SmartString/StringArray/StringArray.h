#ifndef CCLASECOMPILER_STRINGARRAY_H
#define CCLASECOMPILER_STRINGARRAY_H

#include "../String/String.h"

typedef struct SmartStringArrayNode {
    struct SmartString *value;
    struct SmartStringArrayNode *next;
    struct SmartStringArrayNode *prev;
}SmartStringArrayNode;

typedef struct SmartStringArray {
    int length;
    struct SmartStringArrayNode *head;

    void (*push) (struct SmartStringArray*, struct SmartString*);
    struct SmartStringArrayNode* (*getNode) (struct SmartStringArray*, int);
    struct SmartString* (*get) (struct SmartStringArray*, int);
    void (*destroy) (struct SmartStringArray*);
    int (*find) (struct SmartStringArray*,struct SmartString*);
    int (*findFrom)(struct SmartStringArray*,struct SmartString*, int);
}SmartStringArray;

SmartStringArray new_SmartStringArray();
SmartStringArrayNode* new_SmartStringArrayNode(struct SmartString*);

#endif //CCLASECOMPILER_STRINGARRAY_H
