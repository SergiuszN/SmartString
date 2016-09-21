cmake_minimum_required(VERSION 3.6)
project(cClaseCompiler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")

set(SOURCE_FILES
        main.c
        SmartString/String/String.c
        SmartString/StringArray/StringArray.c
        SmartString/Tests/StringTests.c
        )
add_executable(cClaseCompiler ${SOURCE_FILES})