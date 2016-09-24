#include <stdio.h>
#include "SmartString/SmartString.h"
#include "Service/Service.h"
//#include "SmartString/Tests/StringTests.h"

int main() {
//    Service service = new_Service();
//
//    SmartString file = service.fileReadAllLine("../JavaExamples/ex1.java");
//    file.echo(&file);

    SmartString row1 = new_SmartStringFromString("test1");
    SmartString row2 = new_SmartStringFromString("test2");
    SmartString row3 = new_SmartStringFromString("test3");

    SmartStringArray test = new_SmartStringArray();
    test.addString(&test, &row1);
    test.addString(&test, &row2);
    test.addString(&test, &row3);

    SmartString res = test.getString(&test, 0);
    res.echo(&res);

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