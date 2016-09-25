#include "StringTests.h";
#include "../SmartString.h";

void testSmartStringFramework() {
    printf("*** Test SmartString Class...\n");
    test_SmartString();

    printf("*** Test SmartStringArray Class...\n");
    test_SmartStringArray();
}

void test_SmartString() {
    test_new_SmartString();
    test_new_SmartStringFromString();
    test_setString();
    test_getLength();
    test_getChar();
    test_getString();
    test_addString();
    test_addChar();
    test_copy();
    test_equal();
    test_subStr();
    test_strRPos();
    test_allTrim();
    test_strPos();
    test_trim();
    test_strReplace();
    test_getBlock();
    test_deleteAllBetween();
}

void test_SmartStringArray() {
    test_add();
    test_get();
    test_find();
}

void test_new_SmartString() {
    printf("* Test new_SmartString()...\n");
    SmartString string = new_SmartString();

    if (strlen(string.row) == 0 && string.length == 0) {
        printf("    Ok\n");
    } else {
        printf("    Error\n");
    }

    string.destroy(&string);
}

void test_new_SmartStringFromString() {
    printf("* Test new_SmartStringFromString()...\n");
    SmartString string = new_SmartStringFromString("It`s a simple test!");

    if (strcmp(string.row, "It`s a simple test!") == 0 && string.length == strlen("It`s a simple test!")) {
        printf("    Ok\n");
    } else {
        printf("    Error\n");
    }

    string.destroy(&string);
}

void test_setString() {
    printf("* Test setString()...\n");
    SmartString string = new_SmartString();
    string.setString(&string, "It`s a simple test!");

    if (strcmp(string.row, "It`s a simple test!") == 0 && string.length == strlen("It`s a simple test!")) {
        printf("    Ok\n");
    } else {
        printf("    Error\n");
    }

    string.destroy(&string);
}


void test_getLength() {
    printf("* Test getLength()...\n");
    SmartString string = new_SmartStringFromString("It`s a simple test!");

    if (string.getLength(&string) == strlen("It`s a simple test!")) {
        printf("    Ok\n");
    } else {
        printf("    Error\n");
    }

    string.destroy(&string);
}

void test_getChar() {
    printf("* Test getChar()...\n");
    SmartString string = new_SmartStringFromString("It`s a simple test!");

    if (string.getChar(0, &string) != '\0' && string.getChar(string.length, &string) == '\0') {
        printf("    Ok\n");
    } else {
        printf("    Error\n");
    }

    string.destroy(&string);
}

void test_getString() {
    printf("* Test getString()...\n");
    SmartString string = new_SmartStringFromString("It`s a simple test!");

    if (strcmp(string.getString(&string),"It`s a simple test!") == 0) {
        printf("    Ok\n");
    } else {
        printf("    Error\n");
    }

    string.destroy(&string);
}

void test_addString() {
    printf("* Test addString()...\n");
    SmartString string = new_SmartStringFromString("It`s a simple test!");
    SmartString addString = new_SmartStringFromString("Add String");

    string.addString(&string, &addString);

    if (strcmp(string.getString(&string),"It`s a simple test!Add String") == 0 && string.length == strlen("It`s a simple test!Add String")) {
        printf("    Ok\n");
    } else {
        printf("    Error\n");
    }

    string.destroy(&string);
    addString.destroy(&addString);
}

void test_addChar() {
    printf("* Test addChar()...\n");
    SmartString string = new_SmartStringFromString("It`s a simple test!");
    char space = ' ';

    string.addChar(&string, space);

    if (strcmp(string.getString(&string),"It`s a simple test! ") == 0 && string.length == strlen("It`s a simple test! ")) {
        printf("    Ok\n");
    } else {
        printf("    Error\n");
    }

    string.destroy(&string);
}

void test_copy() {
    printf("* Test copy()...\n");
    SmartString string = new_SmartStringFromString("It`s a simple test!");
    SmartString copyString = string.copy(&string);

    if (strcmp(string.row, copyString.row) == 0 && string.length == copyString.length) {
        printf("    Ok\n");
    } else {
        printf("    Error\n");
    }

    string.destroy(&string);
    copyString.destroy(&copyString);
}

void test_equal() {
    printf("* Test equal()...\n");
    SmartString string = new_SmartStringFromString("It`s a simple test!");
    SmartString copyString = new_SmartStringFromString("It`s a simple test!");

    if (string.equal(&string, &copyString)) {
        printf("    Ok\n");
    } else {
        printf("    Error\n");
    }

    string.destroy(&string);
    copyString.destroy(&copyString);
}

void test_subStr() {
    printf("* Test subStr()...\n");
    SmartString string = new_SmartStringFromString("It`s a simple test!");

    int startPosition = 7;
    int length = 6;
    int stopPosition = startPosition + length;

    SmartString subString = string.subStr(&string, startPosition, stopPosition);

    if (strcmp(subString.row, "simple") == 0 && subString.length == 6) {
        printf("    Ok\n");
    } else {
        printf("    Error\n");
    }

    string.destroy(&string);
    subString.destroy(&subString);
}

void test_strRPos() {
    printf("* Test strRPos()...\n");
    SmartString string = new_SmartStringFromString("It`s a simple test!");
    SmartString needle = new_SmartStringFromString("simple");

    int truePosition = 7;

    int foundPosition = string.strRPos(&string, needle.getString(&needle));

    if (foundPosition == truePosition) {
        printf("    Ok\n");
    } else {
        printf("    Error\n");
    }

    string.destroy(&string);
    needle.destroy(&needle);
}

void test_allTrim() {
    printf("* Test allTrim()...\n");
    SmartString string = new_SmartStringFromString("    It`s a \nsimple\t\t test!      ");
    SmartString trueResponse = new_SmartStringFromString("It`sasimpletest!");

    SmartString returnedResponse = string.allTrim(&string);

    if (trueResponse.equal(&trueResponse, &returnedResponse)) {
        printf("    Ok\n");
    } else {
        printf("    Error\n");
    }

    string.destroy(&string);
    trueResponse.destroy(&trueResponse);
    returnedResponse.destroy(&returnedResponse);
}

void test_strPos() {
    printf("* Test strPos()...\n");
    SmartString string = new_SmartStringFromString("It`s a simple test!");

    int startPosition = 3;
    int currentPosition = 8;
    char needle = 'i';

    int foundPosition = string.strPos(&string, startPosition, needle);

    if (foundPosition == currentPosition) {
        printf("    Ok\n");
    } else {
        printf("    Error\n");
    }

    string.destroy(&string);
}

void test_trim() {
    printf("* Test trim()...\n");
    SmartString string = new_SmartStringFromString("   It`s\n a          simple\t test!     ");
    SmartString stringGood = new_SmartStringFromString(" It`s a simple test! ");

    SmartString trimString = string.trim(&string);

    if(trimString.equal(&trimString, &stringGood)) {
        printf("    Ok\n");
    } else {
        printf("    Error\n");
    }

    string.destroy(&string);
    stringGood.destroy(&stringGood);
    trimString.destroy(&trimString);
}

void test_strReplace() {
    printf("* Test strReplace()...\n");
    SmartString string = new_SmartStringFromString("simple It`s a simple test simple!simple");
    SmartString stringGood = new_SmartStringFromString("rakamakafoo It`s a rakamakafoo test rakamakafoo!rakamakafoo");

    SmartString searchWord = new_SmartStringFromString("simple");
    SmartString replaceWord = new_SmartStringFromString("rakamakafoo");

    SmartString response = string.strReplace(&string, searchWord.row, replaceWord.row);

    if(response.equal(&response, &stringGood)) {
        printf("    Ok\n");
    } else {
        printf("    Error\n");
    }

    string.destroy(&string);
    stringGood.destroy(&stringGood);
    searchWord.destroy(&searchWord);
    replaceWord.destroy(&replaceWord);
    response.destroy(&response);
}

void test_getBlock() {
    printf("* Test getBlock()...\n");
    SmartString string = new_SmartStringFromString("Class main { if() {value {asdh lasdj {asdasd  }laksjd }1} value 2 }");
    SmartString blockClass = string.getBlock(&string, '{', '}', 15);

    SmartString blockClassValue = new_SmartStringFromString("value {asdh lasdj {asdasd  }laksjd }1");

    if(blockClass.equal(&blockClass, &blockClassValue)) {
        printf("    Ok\n");
    } else {
        printf("    Error\n");
    }

    string.destroy(&string);
    blockClass.destroy(&blockClass);
    blockClassValue.destroy(&blockClassValue);
}

void test_deleteAllBetween() {
    printf("* Test deleteAllBetween()...\n");
    SmartString string = new_SmartStringFromString("Class main { if() /*{value {asdh*/ lasdj {asdasd  }/*laksjd }1} val*/ue 2 }");

    SmartString start = new_SmartStringFromString("/*");
    SmartString stop = new_SmartStringFromString("*/");

    SmartString clearString = string.deleteAllBetween(&string, &start, &stop);

    SmartString rightClearString = new_SmartStringFromString("Class main { if()  lasdj {asdasd  }ue 2 }");

    if(clearString.equal(&clearString, &rightClearString)) {
        printf("    Ok\n");
    } else {
        printf("    Error\n");
    }

    string.destroy(&string);
    start.destroy(&start);
    stop.destroy(&stop);
    clearString.destroy(&clearString);
    rightClearString.destroy(&rightClearString);
}

void test_add() {
    printf("* Test add()...\n");
    SmartString row1 = new_SmartStringFromString("row1");
    SmartString row2 = new_SmartStringFromString("row2");

    SmartStringArray array = new_SmartStringArray(row1);
    array.add(&array, row2);

    if(array.length == 2) {
        printf("    Ok\n");
    } else {
        printf("    Error\n");
    }

    row1.destroy(&row1);
    row2.destroy(&row2);
    array.destroy(&array);
}

void test_get() {
    printf("* Test get()...\n");
    SmartString row1 = new_SmartStringFromString("row1");
    SmartString row2 = new_SmartStringFromString("row2");

    SmartStringArray array = new_SmartStringArray(row1);
    array.add(&array, row2);

    SmartString response = array.get(&array, 1);

    if(row2.equal(&row2, &response)) {
        printf("    Ok\n");
    } else {
        printf("    Error\n");
    }

    row1.destroy(&row1);
    row2.destroy(&row2);
    response.destroy(&response);
    array.destroy(&array);
}

void test_find() {
    printf("* Test find()...\n");
    SmartString row1 = new_SmartStringFromString("row1");
    SmartString row2 = new_SmartStringFromString("row2");
    SmartString row3 = new_SmartStringFromString("row3");
    SmartString row5 = new_SmartStringFromString("row5");

    SmartStringArray array = new_SmartStringArray(row1);
    array.add(&array, row2);
    array.add(&array, row3);

    int positionRow3 = array.find(&array, &row3);
    int positionRow5 = array.find(&array, &row5);

    int notFind = -1;
    int row3Find = 2;

    if(positionRow3 == row3Find && positionRow5 == notFind) {
        printf("    Ok\n");
    } else {
        printf("    Error\n");
    }

    row1.destroy(&row1);
    row2.destroy(&row2);
    row3.destroy(&row3);
    row5.destroy(&row5);
    array.destroy(&array);
}