#include <stdio.h>
#include "SmartString/SmartString.h"
#include "Service/Service.h"
#include "SmartString/Tests/StringTests.h"

void test();

int main() {

    for (int i=0;i<200000;i++) {
        test();
        if (i%1000 == 0) {
            printf("1000!");
        }
    }

    printf("close\n");
    getchar();
    return 0;


    /*
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
    functionInterpreter.run(&functionInterpreter, &file);*/

    //printf("--------------------------------------\n");
    //file.echo(&file);

//    testSmartStringFramework();


}

void test() {
    SmartStringArray array = new_SmartStringArray();
    SmartString val = new_SmartStringFromString("wahaha1");
    //array.push(&array, &val);

    val.destroy(&val);
    array.destroy(&array);
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