#include <iostream>
#include "gtest/gtest.h"
#include "ejercicios.h"


int main(int argc, char **argv) {
    std::cout << "Implementando GTest!!" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    //Vectores
    vector<int> v100 = construir_vector(100, "asc");
    vector<int> v1000 = construir_vector(1000, "asc");
    vector<int> v10000 = construir_vector(10000, "asc");
    vector<int> v100000 = construir_vector(100000, "asc");

    vector<int> v100D = construir_vector(100, "desc");
    vector<int> v1000D = construir_vector(1000, "desc");
    vector<int> v10000D = construir_vector(10000, "desc");
    vector<int> v100000D = construir_vector(100000, "desc");

    vector<int> v100A = construir_vector(100, "azar");
    vector<int> v1000A = construir_vector(1000, "azar");
    vector<int> v10000A = construir_vector(10000, "azar");
    vector<int> v100000A = construir_vector(100000, "azar");

    vector<int> v100I = construir_vector(100, "iguales");
    vector<int> v1000I = construir_vector(1000, "iguales");
    vector<int> v10000I = construir_vector(10000, "iguales");
    vector<int> v100000I = construir_vector(100000, "iguales");


    //Ejercicio 2
    //Tamaño 100
    double asc1 = tiempoEjecucion("binaria", v100);
    double asc1C = tiempoEjecucion("s", v100);
    //tamaño 1000
    double asc2 = tiempoEjecucion("binaria", v1000);
    double asc2C = tiempoEjecucion("s", v1000);
    //tamaño 10000
    double asc3 = tiempoEjecucion("binaria", v10000);
    double asc3C = tiempoEjecucion("s", v10000);
    //tamaño 100000
    double asc4 = tiempoEjecucion("binaria", v100000);
    double asc4C = tiempoEjecucion("s", v100000);

    std::cout << asc1 << " " << asc2 << " " << asc3 << " " << asc4 << std::endl;
    std::cout << asc1C << " " << asc2C << " " << asc3C << " " << asc4C << std::endl;

    //Ejercicio 3




    return RUN_ALL_TESTS();
}
