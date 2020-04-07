//
// Created by walter on 7/4/20.
//

#include <iostream>
#include "Ejercicios.h"

using namespace std;

//PRE los calificaciones son numeros enteros entre 0 y 100 incluidos.
void ejercicio1() {
    int suma = 0;
    for (int i = 0; i < 10; i++) {
        int valor = 0;
        cout << "Ingrese valor: " << endl;
        cin >> valor;
        cout << "El valor ingresado fue: " << valor << endl;
        suma = suma + valor;
    }
    cout << "La suma de las notas de todos los alumnos es de:" << suma << endl;
    cout << "EL promedio entre todos los alumnos es de: " << suma / 10;
}
