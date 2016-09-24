#include "StringArray.h"

void arrayAddString(SmartStringArray* this, SmartString* new) {

    StringArrayBlock newArray;

    if (this->length == 0) {
        newArray = new_StringArrayBlock(NULL, new);
        this->array = &newArray;
        this->position += 1;
    } else {
        if (this->position == this->length)
        newArray = new_StringArrayBlock(this->array, new);
        this->array = &newArray;
        this->position += 1;
    }

    this->length += 1;
}

void iterateTo(SmartStringArray* this, int position) {

    if (this->position == position) {
        return;
    }

    if (this->position < position) {
        while (this->position != position) {
            this->array = this->array->right;
            this->position += 1;
        }
    }

    if (this->position > position) {
        while (this->position != position) {
            this->array = this->array->left;
            this->position -= 1;
        }
    }
}

SmartString arrayGetString(SmartStringArray* this, int position) {
    iterateTo(this, position);

    SmartString copy = (this->array->value).copy(&this->array->value);

    return copy;
}

//-------------------------------------------
//              Constructor
//-------------------------------------------

SmartStringArray new_SmartStringArray() {
    //set start parameters
    SmartStringArray obj;
    obj.length = 0;
    obj.position = 0;
    obj.array = NULL;

    //connection all function
    obj.addString = &arrayAddString;
    obj.getString = &arrayGetString;

    //end-------------------
    return obj;
}

StringArrayBlock new_StringArrayBlock(StringArrayBlock* this, SmartString* new) {
    StringArrayBlock obj;

    if (this == NULL) {
        obj.left = NULL;
        obj.value = new_SmartStringFromString(new->getString(new));
    } else {
        obj.left = this;
        obj.value = new_SmartStringFromString(new->getString(new));
        this->right = &obj;
    }

    return obj;
}