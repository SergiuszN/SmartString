#include "StringArray.h"

//-------------------------------------------
//            SmartStringArray
//                functions
//-------------------------------------------

void ssa_push(SmartStringArray* this, SmartString* text) {
    SmartStringArrayNode* prevNode = this->getNode(this, this->length - 1);
    SmartStringArrayNode* newNode = new_SmartStringArrayNode(text);

    if (this->length == 0) {
        this->head = newNode;
    } else {
        prevNode->next = newNode;
        newNode->prev = prevNode;
    }

    this->length += 1;
}

SmartStringArrayNode* ssa_getNode(SmartStringArray* this, int position) {
    SmartStringArrayNode* pointer = this->head;

    for (int i=0; i<position; i++) {
        pointer = pointer->next;
    }

    return pointer;
}

SmartString* ssa_get(SmartStringArray* this, int position) {
    SmartStringArrayNode* node = this->getNode(this, position);
    return node->value;
}

void ssa_destroy(SmartStringArray* this) {
    SmartStringArrayNode* node;
    int length = (this->length-1 < 0) ? 0 : this->length-1;

    for (int i=length;i>=0;i--) {
        node = this->getNode(this, i);
        free(node->value->row);
        free(node->value);
        free(node);
        node->value = NULL;
        node->prev = NULL;
        node->next = NULL;
    }

    this->head = NULL;
    this->destroy = NULL;
    this->get = NULL;
    this->getNode = NULL;
    this->length = NULL;
    this->push = NULL;
    this->find = NULL;
    this->findFrom = NULL;
}

int ssa_find(SmartStringArray* this, SmartString* find) {
    SmartStringArrayNode *node;
    int position = -1;

    for (int i=0; i<this->length; i++) {
        node = this->getNode(this, i);
        if (find->equal(find, node->value)) {
            position = i;
        }
    }

    return position;
}

int ssa_findFrom(SmartStringArray* this, SmartString* find, int startPosition) {
    SmartStringArrayNode *node;
    int position = -1;

    if (startPosition >= this->length) {
        return position;
    }

    for (int i=startPosition; i<this->length; i++) {
        node = this->getNode(this, i);
        if (find->equal(find, node->value)) {
            position = i;
        }
    }

    return position;
}

//-------------------------------------------
//              Constructor
//-------------------------------------------

SmartStringArray new_SmartStringArray() {
    // memory set
    SmartStringArray obj;
    SmartString emptyString = new_SmartString();

    // startup value set
    obj.head = new_SmartStringArrayNode(&emptyString);
    obj.length = 0;

    //connection all function
    obj.push = &ssa_push;
    obj.getNode = &ssa_getNode;
    obj.get = &ssa_get;
    obj.destroy = &ssa_destroy;
    obj.find = &ssa_find;
    obj.findFrom = &ssa_findFrom;

    emptyString.destroy(&emptyString);
    return obj;
}

SmartStringArrayNode* new_SmartStringArrayNode(SmartString* text) {
    // create new value
    SmartStringArrayNode* obj = (SmartStringArrayNode*) malloc(sizeof(SmartStringArrayNode));

    // set empty row
    obj->value = (SmartString*) malloc(sizeof(SmartString));
    obj->value = new_SmartStringPointer(obj->value);
    obj->value->setString(obj->value, text->getString(text));

    // default pointer to prev next
    obj->prev = NULL;
    obj->next = NULL;

    return obj;
}