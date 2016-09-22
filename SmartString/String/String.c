#include "String.h"

void echo(SmartString* var) {
    //print string into console
    printf("%s\n",var->row);
}

void setString(SmartString* var, const char* string) {
    //set length
    size_t andLastSymbol = 1;
    var->length = strlen(string);

    //free memory
    var->destroy(var);

    //set row
    var->row = (char*) malloc(var->length + andLastSymbol);
    memcpy(&var->row[0], string, var->length + andLastSymbol);
}

size_t getLength(SmartString* var) {
    //object oriented method to get
    //length of string from
    //SmartString object
    return var->length;
}

char getChar(int i, SmartString* var) {
    //returned one char if exist
    //and '\0' if not
    if (i < var->length) {
        return var->row[i];
    } else {
        return '\0';
    }
}

char* getString(SmartString* var) {
    //object oriented method to get
    //String from SmartString object
    return var->row;
}

void addString(SmartString* to, SmartString* from) {
    //set start parameters
    size_t andLastSymbol = 1;
    size_t toLength = to->length;
    size_t fromLength = from->length + andLastSymbol;
    size_t newLength = toLength + fromLength;

    //copy value
    char copyFirstValue[newLength];
    strcpy(copyFirstValue, to->row);

    //memory free
    to->destroy(to);

    //concatenation row
    to->row = malloc(newLength);
    memcpy(&to->row[0], copyFirstValue, toLength);
    memcpy(&to->row[toLength], from->row, fromLength);

    //set new length
    to->length = newLength - andLastSymbol;
}

void addChar(SmartString* to, char from) {
    //convert char to char*
    char charToArray[2];
    memset(charToArray, '\0', 2);
    charToArray[0] = from;

    //use addString function
    struct SmartString string = new_SmartStringFromString(charToArray);
    addString(to, &string);

    //free memory
    string.destroy(&string);
}

SmartString copy(SmartString* this) {
    //return copy of this object
    return new_SmartStringFromString(this->row);
}

int equal(SmartString* left, SmartString* right) {
    //return 1 if left and right string equal
    //return 0 if left and right string not equal
    if (strcmp(left->row, right->row) == 0) {
        return 1;
    } else {
        return 0;
    }
}

//-------------------------------------------
//              Destructor
//-------------------------------------------

void destroy(SmartString* this) {
    //free class memory
    free(this->row);
}

//-------------------------------------------
//              Constructor
//-------------------------------------------

SmartString new_SmartString() {
    //return new free object SmartString
    return new_SmartStringFromString("");
}

SmartString new_SmartStringFromString(const char* var) {
    size_t andLastSymbol = 1;

    //set start parameters
    struct SmartString obj;

    //set length
    obj.length = strlen(var);

    //set row
    obj.row = (char*) malloc(obj.length + andLastSymbol);
    memset(obj.row, '\0', obj.length);
    strcpy(obj.row, var);

    //connection all function
    obj.echo = &echo;
    obj.getLength = &getLength;
    obj.getChar = &getChar;
    obj.getString = &getString;
    obj.addString = &addString;
    obj.addChar = &addChar;
    obj.setString = &setString;
    obj.destroy = &destroy;
    obj.copy = &copy;
    obj.equal = &equal;

    //end-------------------
    return obj;
}