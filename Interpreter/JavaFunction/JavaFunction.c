#include "JavaFunction.h"

void JavaFunctionMacro(SmartString* text) {

}

//-------------------------------------------
//              Constructor
//-------------------------------------------

JavaFunction new_JavaFunction() {
    // create new object
    JavaFunction obj;

    //connection all function
    obj.functionMacro = &JavaFunctionMacro;

    return obj;
}