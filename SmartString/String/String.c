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

SmartString subStr(SmartString* this, int start, int end) {
    //return sub row from this row
    //start from 'int start'
    //end in 'int end' or end of string if 'int end == -1'

    //create new string
    SmartString subString = new_SmartString();

    //save length base row
    int endPosition = this->getLength(this);

    //if end position define save new length
    int endPositionNotDefine = -1;
    if (end != endPositionNotDefine) {
        endPosition = end;
    }

    //save new sub string char by char
    for (int i=start; i<endPosition; i++) {
        subString.addChar(&subString, this->getChar(i, this));
    }

    //return sub string
    return subString;
}

SmartString allTrim(SmartString* this) {
    // delete all \n \t ' ' symbol from row
    SmartString trimString = new_SmartString();

    for (int i=0; i < this->length; i++) {
        // if it`s \n \t ' ' skip step
        if (this->row[i] == ' ' || this->row[i] == '\t' || this->row[i] == '\n') {
            continue;
        }
        // else add char to trimString
        trimString.addChar(&trimString, this->row[i]);
    }

    //return clear object
    return trimString;
}

int strRPos(SmartString* haystack, char* needle) {
    // function returns a position to the first occurrence
    // of row needle in row haystack, or a 'int -1'
    // if row needle is not part of haystack.
    int notFound = -1;
    int position = notFound;
    // get pointer to first occurrence or null
    char* pointer = strstr(haystack->row, needle);

    //if pointer not null change position
    if (pointer) {
        position = (int) (pointer - haystack->row);
    }

    return position;
}

int strPos(SmartString* this, int startPosition, char needle) {
    //return position of the required symbol
    //start from 'int startPosition'
    //end in 'int endPosition'

    //find how many symbols have string
    int endPosition = this->getLength(this);

    int currentPosition = -1;

    for (int i=startPosition; i<endPosition ; i++) {
        if (this->row[i] == needle) {
            currentPosition = i;
            break;
        }
    }

    return currentPosition;
}

SmartString trim(SmartString* this) {
    //remove spaces, tabs and carry of a line, then leave one space
    int endPosition = this->getLength(this);
    SmartString newRow = new_SmartString();

    //remove tabs and carry of a line
    for (int i = 0; i < endPosition; i++) {
        if(this->row[i] == '\n' || this->row[i] == '\t') {
            this->row[i] = ' ';
        }
    }
    //remove spaces
    for (int i = 0; i < endPosition-1; i++) {
        if(this->row[i] != ' ' || this->row[i+1] != ' ') {
            newRow.addChar(&newRow, this->row[i]);
        }
    }

    newRow.addChar(&newRow, this->row[endPosition-1]);

    return newRow;
}

SmartString strReplace(SmartString* this, char* search, char* replace) {
    // create SmartString from replace row
    SmartString replaceString = new_SmartStringFromString(replace);
    // create base newString from base row
    SmartString newString = this->copy(this);

    // create free leftString and rightString
    SmartString leftString = new_SmartString();
    SmartString rightString = new_SmartString();

    // set base parameters
    int searchWordLength = strlen(search);
    int nullPosition = -1;
    int searchStringPosition;

    // replace words while search words is set
    do {
        // find new position search row in base row
        searchStringPosition = newString.strRPos(&newString, search);

        // if search word find
        if (searchStringPosition != nullPosition) {
            // clear left adn right row
            leftString.destroy(&leftString);
            rightString.destroy(&rightString);

            // set new left and right row
            leftString = newString.subStr(&newString, 0, searchStringPosition);
            rightString = newString.subStr(&newString, searchStringPosition + searchWordLength, -1);

            // clear base row
            newString.destroy(&newString);
            newString = new_SmartString();

            // set new base row
            newString.addString(&newString, &leftString);
            newString.addString(&newString, &replaceString);
            newString.addString(&newString, &rightString);
        } else {
            // no more search keyword
            break;
        }
    } while (1); // break point implemented in do

    // free memory
    replaceString.destroy(&replaceString);
    leftString.destroy(&leftString);
    rightString.destroy(&rightString);

    // return new replaced row
    return newString;
}

SmartString getBlock(SmartString* this, char startChar, char stopChar, int startPosition) {
    // declare vars
    SmartString textInsideBlock = new_SmartString();
    SmartString textWithOutBracket;
    int counterBrackets = 0;

    // get start block position
    int startOfBlock = this->strPos(this, startPosition, startChar);

    for (int i=startOfBlock; i < this->length; i++) {
        // if find start brackets increment brackets counter
        if (this->row[i] == startChar) {
            counterBrackets += 1;
        }

        // if find stop brackets decrement brackets counter
        if (this->row[i] == stopChar) {
            counterBrackets -= 1;
        }

        // add char into text block to temp variable
        textInsideBlock.addChar(&textInsideBlock, this->row[i]);

        // is block end?
        if (counterBrackets == 0) {
            break;
        }
    }

    // sub start and stop brackets
    textWithOutBracket = textInsideBlock.subStr(&textInsideBlock,1,textInsideBlock.length-1);

    // free memory
    textInsideBlock.destroy(&textInsideBlock);

    // return response
    return textWithOutBracket;
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
    memset(obj.row, '\0', obj.length + andLastSymbol);
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
    obj.subStr = &subStr;
    obj.strRPos = &strRPos;
    obj.allTrim = &allTrim;
    obj.strPos = &strPos;
    obj.trim = &trim;
    obj.strReplace = &strReplace;
    obj.getBlock = &getBlock;

    //end-------------------
    return obj;
}