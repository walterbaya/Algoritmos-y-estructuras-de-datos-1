cmake_minimum_required(VERSION 3.17)
project(Laboratorio10)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

set(SOURCE_FILES src/ejercicios.cpp src/ejercicios.h src/risas.cpp src/risas.h tests/risasTEST.cpp tests/tests.cpp)

add_executable(Laboratorio10 ${SOURCE_FILES})

target_link_libraries(Laboratorio10 gtest gtest_main)