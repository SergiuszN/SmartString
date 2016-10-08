#include "JavaFunction.h"

void JavaFunctionRun(JavaFunction *this, SmartString* text) {
    this->mainFunctionMacro(text);
    SmartStringArray functionTokenArray = this->functionTokenDelimiter(text);


}

SmartStringArray JavaFunctionTokenDelimiter(SmartString* text) {

    // create trimmed copy of text
    SmartString trimText = text->trim(text);
    SmartString copyOfText = new_SmartStringFromString(trimText.row);
    trimText.destroy(&trimText);

    // define base variable

    SmartString left = new_SmartString();
    SmartString right = new_SmartString();

    SmartString function = new_SmartString();
    SmartString parameters = new_SmartString();
    SmartString name = new_SmartString();
    SmartString type = new_SmartString();
    SmartString emptyRow = new_SmartString();

    int blockStart;
    int blockStop;
    int parametersBlockStart;
    int parametersBlockStop;
    int nameStartPosition;
    int typeStartPosition;

    SmartStringArray functionTokenArray = new_SmartStringArray(emptyRow);

    // get function block
    while (! (function = copyOfText.getBlock(&copyOfText, '{', '}', 0)).equal(&function, &emptyRow)) {
        // get position start stop function
        blockStart = copyOfText.strRPos(&copyOfText, function.row);
        blockStop = blockStart + function.length;

        // get parameters function
        parameters.destroy(&parameters);
        parametersBlockStart = copyOfText.revertStrPos(&copyOfText, blockStart, '(');
        parametersBlockStop = copyOfText.revertStrPos(&copyOfText, blockStart, ')');
        parameters = copyOfText.subStr(&copyOfText, parametersBlockStart+1, parametersBlockStop);

        // get name function
        name.destroy(&name);
        nameStartPosition = copyOfText.revertStrPos(&copyOfText, parametersBlockStart-1, ' ');
        name = copyOfText.subStr(&copyOfText, nameStartPosition+1, parametersBlockStart);

        // get returned type function
        type.destroy(&type);
        typeStartPosition = copyOfText.revertStrPos(&copyOfText, nameStartPosition-1, ' ');
        type = copyOfText.subStr(&copyOfText, typeStartPosition+1, nameStartPosition);

        functionTokenArray.add(&functionTokenArray, type);
        functionTokenArray.add(&functionTokenArray, name);
        functionTokenArray.add(&functionTokenArray, parameters);
        functionTokenArray.add(&functionTokenArray, function);

        left.destroy(&left);
        right.destroy(&right);

        left = copyOfText.subStr(&copyOfText, 0, typeStartPosition);
        right = copyOfText.subStr(&copyOfText, blockStop+1, -1);

        copyOfText.setString(&copyOfText, left.row);
        copyOfText.addString(&copyOfText, &right);

        function.destroy(&function);
    }

    SmartString clearStaticMethods = copyOfText.strReplace(&copyOfText, "static", "");
    copyOfText.setString(&copyOfText, clearStaticMethods.row);
    clearStaticMethods.destroy(&clearStaticMethods);

    functionTokenArray.add(&functionTokenArray, copyOfText);
    copyOfText.destroy(&copyOfText);

    printf("%s\n", functionTokenArray.get(&functionTokenArray, 8).row);

    return functionTokenArray;
}

void JavaMainFunctionMacro(SmartString* text) {
    // get replaced row
    SmartString replacedText = text->strReplace(text, "static void run()", "void main()");

    // set replaced row in main text variable
    text->setString(text, replacedText.row);

    // free memory
    replacedText.destroy(&replacedText);
}

//-------------------------------------------
//              Constructor
//-------------------------------------------

JavaFunction new_JavaFunction() {
    // create new object
    JavaFunction obj;

    //connection all function
    obj.functionTokenDelimiter = &JavaFunctionTokenDelimiter;
    obj.mainFunctionMacro = &JavaMainFunctionMacro;
    obj.run = &JavaFunctionRun;

    return obj;
}