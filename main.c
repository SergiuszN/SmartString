#include <stdio.h>
#include "SmartString/SmartString.h"
#include "Service/Service.h"
//#include "SmartString/Tests/StringTests.h"

void test_SmartStringArray();

int main() {
//    Service service = new_Service();
//
//    SmartString file = service.fileReadAllLine("../JavaExamples/ex1.java");
//    file.echo(&file);

    test_SmartStringArray();

    getchar();
    return 0;
}

void test_SmartStringArray() {
    SmartString row1 = new_SmartStringFromString("123");
    SmartString row2 = new_SmartStringFromString("123");
    SmartString row3 = new_SmartStringFromString("123");

    SmartStringArray test = new_SmartStringArray(row1);
    test.add(&test, row2);
    test.add(&test, row3);

    SmartString res = new_SmartString();
    res.destroy(&res); res = test.get(&test, 0); res.echo(&res);
    res.destroy(&res); res = test.get(&test, 1); res.echo(&res);
    res.destroy(&res); res = test.get(&test, 2); res.echo(&res);

    test.destroy(&test);
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