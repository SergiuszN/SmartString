#include <stdio.h>
#include "SmartString/SmartString.h"
#include "Service/Service.h"
#include "SmartString/Tests/StringTests.h"

void test_SmartStringArray();

int main() {
//    Service service = new_Service();
//
//    SmartString file = service.fileReadAllLine("../JavaExamples/ex1.java");
//    file.echo(&file);

    testSmartStringFramework();

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