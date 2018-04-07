cmake_minimum_required(VERSION 3.8)
project(Dialog)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp IDLIST.h WObject.h WObject.cpp)
add_executable(Dialog ${SOURCE_FILES})