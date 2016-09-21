#include <stdio.h>
#include "SmartString/SmartString.h"
#include "SmartString/Tests/StringTests.h"

int main() {
//    smartStringPresentation();
//    smartStringTest();
    testSmartStringFramework();

    getchar();
    return 0;
}

/*
void smartStringPresentation() {
    struct SmartString string = new_SmartString();
    string.setString(&string, "Hello, World!");

//    struct SmartString substring = string.substr(&string,0,1);
//    substring.echo(&substring);

    struct SmartString newString = new_SmartStringFromString("From SmartString!");

    printf("First Row : %s\n", string.getString(&string));
    printf("Second Row : %s\n", newString.getString(&newString));

    printf("Concatenation with space between...\n");
    string.addChar(&string, '|');
    string.addString(&string, &newString);

    printf("String length = %d\n", string.getLength(&string));

    printf("Print String manual : %s\n", string.getString(&string));

    printf("Print String By Echo Function : ");
    string.echo(&string);

    printf("Printing while not '\\0' : ");
    int i=0;
    while (string.getChar(i, &string) != '\0') {
        printf("%c", string.getChar(i, &string));
        i++;
    }
}

 */