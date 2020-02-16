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

    std::cout <<"Estimaciones de busqueda binaria"<< std::endl;
    std::cout << asc1 << " " << asc2 << " " << asc3 << " " << asc4 << std::endl;
    std::cout <<"Estimaciones de JumpSearch"<< std::endl;
    std::cout << asc1C << " " << asc2C << " " << asc3C << " " << asc4C << std::endl;

    //Ejercicio 3

    //Evaluacion del size

    double tiempo1S = calculadoraTiempos(v100, "size", 0, 0);
    double tiempo2S = calculadoraTiempos(v1000A, "size", 0, 0);
    double tiempo3S = calculadoraTiempos(v10000I, "size", 0, 0);
    double tiempo4S = calculadoraTiempos(v100000D, "size", 0, 0);

    std::cout << "Evaluacion del size" << std::endl;
    std::cout << tiempo1S << " " << tiempo2S << " " << tiempo3S << " " << tiempo4S << std::endl;

    //Evaluacion del push

    double tiempo1P = calculadoraTiempos(v100A, "push", 0, 0);
    double tiempo2P = calculadoraTiempos(v1000I, "push", 0, 0);
    double tiempo3P = calculadoraTiempos(v10000D, "push", 0, 0);
    double tiempo4P = calculadoraTiempos(v100000, "push", 0, 0);

    std::cout << "Evaluacion del push" << std::endl;
    std::cout << tiempo1P << " " << tiempo2P << " " << tiempo3P << " " << tiempo4P << std::endl;

    //Evaluacion del pop

    double tiempo1Pop = calculadoraTiempos(v100I, "pop", 0, 0);
    double tiempo2Pop = calculadoraTiempos(v1000D, "pop", 0, 0);
    double tiempo3Pop = calculadoraTiempos(v100000, "pop", 0, 0);
    double tiempo4Pop = calculadoraTiempos(v10000A, "pop", 0, 0);

    std::cout << "Evaluacion del pop" << std::endl;
    std::cout << tiempo1Pop << " " << tiempo2Pop << " " << tiempo3Pop << " " << tiempo4Pop << std::endl;

    //Evaluacion del []

    double tiempo1C = calculadoraTiempos(v100D, "[]", 45, 0);
    double tiempo2C = calculadoraTiempos(v10000, "[]", 567, 0);
    double tiempo3C = calculadoraTiempos(v10000A, "[]", 12344, 0);
    double tiempo4C = calculadoraTiempos(v10000I, "[]", 1234, 0);

    std::cout << "Evaluacion del []" << std::endl;
    std::cout << tiempo1C << " " << tiempo2C << " " << tiempo3C << " " << tiempo4C << std::endl;

    //Evaluacion del asignacion

    double tiempo1A = calculadoraTiempos(v100D, "asignacion", 45, 345);
    double tiempo2A = calculadoraTiempos(v10000, "asignacion", 567, 55);
    double tiempo3A = calculadoraTiempos(v10000A, "asignacion", 12344, 6);
    double tiempo4A = calculadoraTiempos(v10000I, "asignacion", 1234, 7);

    std::cout << "Evaluacion del asignacion" << std::endl;
    std::cout << tiempo1A << " " << tiempo2A << " " << tiempo3A << " " << tiempo4A << std::endl;

    //Evaluacion clear

    double tiempo1Cl = calculadoraTiempos(v100D, "clear", 0, 0);
    double tiempo2Cl = calculadoraTiempos(v10000, "clear", 0, 0);
    double tiempo3Cl = calculadoraTiempos(v10000A, "clear", 0, 0);
    double tiempo4Cl = calculadoraTiempos(v10000I, "clear", 0, 0);

    std::cout << "Evaluacion del clear" << std::endl;
    std::cout << tiempo1Cl << " " << tiempo2Cl << " " << tiempo3Cl << " " << tiempo4Cl << std::endl;

    //Evaluacion del empty

    double tiempo1E = calculadoraTiempos(v100D, "size", 0, 0);
    double tiempo2E = calculadoraTiempos(v10000, "size", 0, 0);
    double tiempo3E = calculadoraTiempos(v10000A, "size", 0, 0);
    double tiempo4E = calculadoraTiempos(v10000I, "size", 0, 0);

    std::cout << "Evaluacion del empty" << std::endl;
    std::cout << tiempo1E << " " << tiempo2E << " " << tiempo3E << " " << tiempo4E << std::endl;

    return RUN_ALL_TESTS();
}
