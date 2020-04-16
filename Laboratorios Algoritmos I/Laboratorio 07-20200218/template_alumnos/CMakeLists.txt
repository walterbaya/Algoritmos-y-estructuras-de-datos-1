cmake_minimum_required(VERSION 3.6)
project(Labo07)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

set(SOURCE_FILES main.cpp
        ejercicios.cpp
        ejercicios.h
        test/Ej1_productoVectorialTest.cpp
        test/Ej2_trasponerTest.cpp
        test/Ej3_multiplicarTest.cpp
        test/Ej4_promediarTest.cpp
        test/Ej5_contarPicosTest.cpp
        test/Ej6_esTriangularTest.cpp
        test/Ej7_hayAmenazaTest.cpp
        test/Ej8_diferenciaDiagonalesTest.cpp test/Ej9_WillieElRobot.cpp)

add_executable(Labo07 ${SOURCE_FILES})

target_link_libraries(Labo07 gtest gtest_main)

