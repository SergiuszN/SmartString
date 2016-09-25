#include "StringArray.h"

//-------------------------------------------
//          SmartStringArrayBlock
//                functions
//-------------------------------------------

SmartStringArrayBlock* pushBack(SmartStringArrayBlock* this, SmartString value) {

    // add new element in to back

    SmartStringArrayBlock *newBlock = new_SmartStringArrayBlock(value);
    SmartStringArrayBlock *nextBlock = this->next;

    this->next = newBlock;

    newBlock->prev = this;
    newBlock->field = value;
    newBlock->next = nextBlock;


    if (nextBlock != NULL) {
        nextBlock->prev = newBlock;
    }

    return(newBlock);
}

SmartStringArrayBlock* getBlockByKey(SmartStringArrayBlock* this, int key) {
    // function return element with key number
    // or NULL if not isset

    SmartStringArrayBlock *tempArray = this;
    int count = 0;

    while (tempArray) {

        if (key == count) {
            break;
        }

        tempArray = tempArray->next;
        count += 1;
    }

    return tempArray;
}

void destroySmartStringArrayBlock(SmartStringArrayBlock* this, int length) {
    // iterate on all SmartStringArrayBlock and delete SmartString
    // after delete SmartStringArrayBlock pointer

    SmartStringArrayBlock *tempArray = this;
    SmartStringArrayBlock *nextArray;
    int count = 0;

    while (count < length) {
        nextArray = tempArray->next;

        (tempArray->field).destroy(&(tempArray->field));
        free(tempArray);

        tempArray = nextArray;
        count += 1;
    }
}

//-------------------------------------------
//            SmartStringArray
//                functions
//-------------------------------------------

void addToSmartStringArray(SmartStringArray* this, SmartString value) {
    // use SmartStringArrayBlock pushBack function
    this->current = this->current->pushBack(this->current, value);
    // increment length
    this->length += 1;
}

SmartString getToSmartStringArray(SmartStringArray* this, int key) {
    // get SmartStringArrayBlock with key == 'key'
    SmartStringArrayBlock* block = this->head->getBlock(this->head, key);
    // return SmartString object
    return block->field;
}

void destroySmartStringArray(SmartStringArray* this) {
    // use destructor SmartStringArrayBlock class
    this->head->destroy(this->head, this->length);
}

//-------------------------------------------
//              Constructor
//-------------------------------------------

SmartStringArrayBlock* new_SmartStringArrayBlock(SmartString value) {

    // memory set
    SmartStringArrayBlock* obj = (SmartStringArrayBlock*) malloc(sizeof(SmartStringArrayBlock));

    // startup value set
    obj->field = value;
    obj->next = NULL;
    obj->prev = NULL;

    //connection all function
    obj->pushBack = &pushBack;
    obj->getBlock = &getBlockByKey;
    obj->destroy = &destroySmartStringArrayBlock;

    //end-------------------
    return obj;
}

SmartStringArray new_SmartStringArray(SmartString value) {
    // memory set
    SmartStringArray obj;

    // startup value set
    obj.head = new_SmartStringArrayBlock(value);
    obj.current = obj.head;
    obj.length = 1;

    //connection all function
    obj.add = &addToSmartStringArray;
    obj.get = &getToSmartStringArray;
    obj.destroy = &destroySmartStringArray;

    return obj;
}