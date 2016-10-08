#include <stdio.h>
#include "SmartString/SmartString.h"
#include "Service/Service.h"
#include "Interpreter/Interpreter.h"
#include "SmartString/Tests/StringTests.h"

int main() {
    // define objects classes helpers
    Service service = new_Service();
    JavaClass classInterpreter = new_JavaClass();
    JavaFunction functionInterpreter = new_JavaFunction();

    // read java source code
    SmartString file = service.fileReadAllText("../JavaExamples/ex3.java");

    // delete comments from code
    service.deleteAllComments(&file);

    // interpret classes
    classInterpreter.classMacro(&file);

    // interpret functions
    functionInterpreter.run(&functionInterpreter, &file);

    //printf("--------------------------------------\n");
    //file.echo(&file);

//    testSmartStringFramework();

    getchar();
    return 0;
}

//    functions for test SmartString Framework
//    testSmartStringFramework();
//    * memory test--------
//    int i=0;
//    while (i<1000) {
//        testSmartStringFramework();
//        system("cls");
//    }
//    * ------------------