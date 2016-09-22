#include "Service.h"

SmartString fileReadAllLine(char* fileName) {
    // function read all file
    // and save into object SmartString
    FILE *in;
    char oneChar;
    SmartString allFile = new_SmartString();

    in=fopen(fileName,"r");

    while ((oneChar = (char) fgetc(in)) != EOF) {
        allFile.addChar(&allFile, oneChar);
    }

    fclose(in);
    free(in);

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