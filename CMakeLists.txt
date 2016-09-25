cmake_minimum_required(VERSION 3.6)
project(cClaseCompiler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(SOURCE_FILES
        main.c
        SmartString/String/String.c
        SmartString/StringArray/StringArray.c
        SmartString/Tests/StringTests.c
        Service/Service.c
        Interpreter/JavaClass/JavaClass.c
        )
add_executable(cClaseCompiler ${SOURCE_FILES})