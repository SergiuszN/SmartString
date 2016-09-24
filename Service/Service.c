#include "Service.h"

SmartString fileReadAllLine(char* fileName) {
    // function read all file
    // and save into object SmartString

    // define variables
    FILE *in;
    char oneChar;
    SmartString allFile = new_SmartString();

    // open user file for reading
    in=fopen(fileName,"r");

    // if file not defined
    // print error end return void SmartString
    if (!in) {
        printf("Error! File: '%s' not finded!\n", fileName);
        return new_SmartString();
    }

    // reading all file
    while ((oneChar = (char) fgetc(in)) != EOF) {
        allFile.addChar(&allFile, oneChar);
    }

    // close file and clear memory
    fclose(in);

    return allFile;
}


//-------------------------------------------
//              Constructor
//-------------------------------------------

Service new_Service() {
    //set start parameters
    struct Service obj;

    //connection all function
    obj.fileReadAllLine = &fileReadAllLine;

    //end-------------------
    return obj;
}