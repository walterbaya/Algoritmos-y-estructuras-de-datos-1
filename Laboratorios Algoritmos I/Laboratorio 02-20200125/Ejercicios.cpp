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
    cout << "EL promedio entre todos los alumnos es de: " << suma / 10.0;
}

void ejercicio2() {
    int suma = 0;
    int cantidad = 0;
    cout << "Ingrese la cantidad de alumnos: " << endl;
    cin >> cantidad;
    cout << "La cantidad de alumnos ingresados fue:" << endl;

    for (int i = 0; i < cantidad; i++) {
        int valor = 0;
        cout << "Ingrese valor: " << endl;
        cin >> valor;
        cout << "El valor ingresado fue: " << valor << endl;
        suma = suma + valor;
    }
    cout << "La suma de las notas de todos los alumnos es de:" << suma << endl;
    cout << "EL promedio entre todos los alumnos es de: " << suma / 10.0;
}

void ejercicio3() {
    int suma = 0;
    int cantidad = 0;
    int cantReprobados = 0;
    int cantAprobados = 0;
    cout << "Ingrese la cantidad de alumnos: " << endl;
    cin >> cantidad;
    cout << "La cantidad de alumnos ingresados fue:" << endl;

    if (cantidad < 6) {
        cout << "ERROR! no puede ser que un curso tenga menos de 6 estudiantes" << endl;
    } else {
        for (int i = 0; i < cantidad; i++) {
            int valor = 0;
            cout << "Ingrese valor: " << endl;
            cin >> valor;
            cout << "El valor ingresado fue: " << valor << endl;
            if (valor < 6) {
                cantReprobados++;
            } else {
                cantAprobados++;
            }
            suma = suma + valor;
        }
        cout << "La suma de las notas de todos los alumnos es de: " << suma << endl;
        cout << "EL promedio entre todos los alumnos es de: " << suma / 10.0 << endl;
        cout << "El numero de aprobados fue: " << cantAprobados << endl;
        cout << "El numero de desaprobados fue: " << cantReprobados << endl;
        if (cantAprobados > (2.0 / 3.0)) {
            cout << "Se pueden incrementar las plazas del curso" << endl;
        }
    }
}

int potenciaDeUnNumero(int num, int pot) {
    int potencia = 1;
    for (int i = 1; i <= pot; i++) {
        potencia = potencia * num;
    }
    return potencia;
}

int largoDelNumero(int numero) {
    int num = numero;
    int largo = 0;
    while (num > 0) {
        num = num / 10;
        largo++;
    }
    return largo;
}

void ejercicio4() {
    int numeroDecimal = 0;
    int numeroBinario = 0;
    cout << "Ingrese un numero binario: " << endl;
    cin >> numeroBinario;
    int largo = largoDelNumero(numeroBinario);
    for (int i = 0; i < largo; i++) {
        int numTemp = numeroBinario % 10;
        numeroBinario = numeroBinario / 10;
        if (numTemp == 1) {
            numeroDecimal = numeroDecimal + potenciaDeUnNumero(2, i);
        }
    }
    cout << "El numero ingresado en decimal es: " << numeroDecimal << endl;
}

//Se pasa el radio por valor ya que no vamos a querer modificarlo.
float ejercicio5(float radio) {
    int pi = 3.14159;
    int diametro = 2 * radio;
    int area = pi * radio * radio;
    int circunferencia = 2 * pi * radio;
    cout << "El diametro es: " <<diametro<< "La circunferencia es: " <<circunferencia<<"el area es: "<<area<<endl;
}

void triplicarPorReferencia(int &n) {
    n = 3 * n;
}

int triplicarPorValor(int n) {
    return 3 * n;
}