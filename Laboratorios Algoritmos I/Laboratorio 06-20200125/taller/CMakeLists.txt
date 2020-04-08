cmake_minimum_required(VERSION 3.6)
project(Labo06)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)


set(SOURCE_FILES main.cpp
        ej1/esPrimo.cpp
        ej1/Test/esPrimoTest.cpp
        ej1/puntaje.cpp
        ej1/Test/puntajeTEST.cpp
        ej2/llenarTaxis.cpp
        ej2/Test/llenarTaxisTEST.cpp
        )


add_executable(Labo06 ${SOURCE_FILES})

target_link_libraries(Labo06 gtest gtest_main)
