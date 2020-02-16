#include <iostream>
#include "gtest/gtest.h"
#include "ejercicios.h"


int main(int argc, char **argv) {
    std::cout << "Implementando GTest!!" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    //Tamaño 100
    double asc1 = tiempoEjecucion(100, "asc", "binaria");
    double desc1 = tiempoEjecucion(100, "desc", "binaria");
    double asc1C = tiempoEjecucion(100, "asc", "s");
    double desc1C = tiempoEjecucion(100, "desc", "s");
    //tamaño 1000
    double asc2 = tiempoEjecucion(1000, "asc", "binaria");
    double desc2 = tiempoEjecucion(1000, "desc", "binaria");
    double asc2C = tiempoEjecucion(1000, "asc", "s");
    double desc2C = tiempoEjecucion(1000, "desc", "s");
    //tamaño 10000
    double asc3 = tiempoEjecucion(10000, "asc", "binaria");
    double desc3 = tiempoEjecucion(10000, "desc", "binaria");
    double asc3C = tiempoEjecucion(10000, "asc", "s");
    double desc3C = tiempoEjecucion(10000, "desc", "s");
    //tamaño 100000
    double asc4 = tiempoEjecucion(100000, "asc", "binaria");
    double desc4 = tiempoEjecucion(100000, "desc", "binaria");
    double asc4C = tiempoEjecucion(100000, "asc", "s");
    double desc4C = tiempoEjecucion(100000, "desc", "s");


    std::cout << asc1 << " " << asc2 << " " << asc3 << " " << asc4 << std::endl;
    std::cout << asc1C << " " << asc2C << " " << asc3C << " " << asc4C << std::endl;
    return RUN_ALL_TESTS();
}
