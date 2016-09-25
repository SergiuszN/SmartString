#include "JavaClass.h"


void JavaClassClassMacro(SmartString* text) {
    // function parse all input Java text
    // find class declaration and delete them from code
    // after replaced all static class call
    // for local function call

    // set variables
    int undefined = -1;
    int classPosition;
    int bracketsClassPosition;

    SmartString className = new_SmartString();
    SmartString replacedText = new_SmartString();
    SmartString beforeClassText = new_SmartString();
    SmartString classText = new_SmartString();
    SmartString afterClassText = new_SmartString();

    // while all class not parse
    while ((classPosition = text->strRPos(text, "class ")) != undefined) {
        // find brackets class block
        bracketsClassPosition = text->strPos(text, classPosition, '{');
        // get full class name like 'class Some '
        className.setString(&className, text->subStr(text, classPosition, bracketsClassPosition).row);

        // get before inner and after block
        beforeClassText.destroy(&beforeClassText);
        beforeClassText = text->subStr(text,0, classPosition);
        classText = (text->getBlock(text, '{', '}', bracketsClassPosition - 1));
        afterClassText = text->subStr(text, bracketsClassPosition + classText.length + 2, -1);

        // set new file text
        text->destroy(text);
        text->setString(text, beforeClassText.row);
        text->addString(text, &classText);
        text->addString(text, &afterClassText);

        // replace all class constant call
        replacedText.destroy(&replacedText);
        JavaClassClearClassName(&className);
        replacedText = text->strReplace(text, className.row, "");

        // set interpreted class text
        text->setString(text, replacedText.row);
    }

    // free memory
    className.destroy(&className);
    replacedText.destroy(&replacedText);
    beforeClassText.destroy(&beforeClassText);
    classText.destroy(&classText);
    afterClassText.destroy(&afterClassText);
}

void JavaClassClearClassName(SmartString* fullClassName) {
    // function accept class name like 'class Name '
    // and change on 'Name.'

    // get position first space symbol
    int startPosition = fullClassName->strPos(fullClassName, 0, ' ') + 1;
    // get position second space symbol
    int stopPosition = fullClassName->strPos(fullClassName, startPosition, ' ');

    // sub by first and second space 'class Name ' -> 'Name'
    SmartString clear = fullClassName->subStr(fullClassName, startPosition, stopPosition);

    // set new value into pointer
    fullClassName->destroy(fullClassName);
    fullClassName->setString(fullClassName, clear.row);

    // add '.' to back class name
    fullClassName->addChar(fullClassName, '.');

    // free memory
    clear.destroy(&clear);
}

//-------------------------------------------
//              Constructor
//-------------------------------------------

JavaClass new_JavaClass() {
    // create new object
    JavaClass obj;

    //connection all function
    obj.classMacro = &JavaClassClassMacro;

    return obj;
}