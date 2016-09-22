#include "StringTests.h";
#include "../SmartString.h";

void testSmartStringFramework() {
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
}