#include <stdio.h>
#include "SmartString/SmartString.h"
#include "Service/Service.h"
#include "SmartString/Tests/StringTests.h"

int main() {
    // define objects classes helpers
    Service service = new_Service();
    // read java source code
    SmartString file = service.fileReadAllText("../JavaExamples/ex3.java");
    // delete comments from code
    service.deleteAllComments(&file);

    printf("--------------------------------------\n");
    file.echo(&file);

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