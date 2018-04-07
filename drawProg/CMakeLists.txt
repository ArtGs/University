cmake_minimum_required(VERSION 3.8)
project(drawProg)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Figures.cpp
        Figures.h
        main.cpp WObject.cpp WObject.h IDLIST.h Mouse.cpp Mouse.h)

add_executable(drawProg ${SOURCE_FILES})