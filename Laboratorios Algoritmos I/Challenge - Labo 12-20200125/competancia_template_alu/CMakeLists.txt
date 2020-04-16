cmake_minimum_required(VERSION 3.6)
project(competencia)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

set(SOURCE_FILES main.cpp
        risas.cpp
        risas.h
        tests/risasTEST.cpp
        libros.cpp
        libros.h
        tests/librosTEST.cpp
        mayas.cpp
        tests/mayasTEST.cpp
        mayas.h
        robotitos.cpp
        robotitos.h
        tests/robotitosTEST.cpp)
add_executable(competencia ${SOURCE_FILES})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

target_link_libraries(competencia gtest gtest_main)

