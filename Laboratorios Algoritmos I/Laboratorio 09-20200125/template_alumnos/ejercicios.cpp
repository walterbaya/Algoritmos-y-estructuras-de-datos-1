#include "ejercicios.h"
#include "time.h"
#include <ctime>
#include "stdlib.h"
#include <string>
#include <cmath>
#include<iostream>

using namespace std;


//Ejercicio 1
int busquedaBinaria(vector<int> v, int x) {
    int med = v.size() / 2;
    int izq = 0;
    int der = v.size() - 1;
    int res = -1;
    bool seAlcanzoTamanio0 = false;
    bool encontrado = false;
    bool ordDesc = false;
    if (v.size() > 0) {
        if (v[0] > v[1]) {
            ordDesc = true;
        }
    }
    if (ordDesc) {
        while (!seAlcanzoTamanio0 && !encontrado) {
            if (der - izq == 0) {
                seAlcanzoTamanio0 = true;
            }
            if (v[med] == x) {
                encontrado = true;
                res = med;
            } else {
                if (v[med] > x) {
                    izq = med + 1;
                    med = (izq + der) / 2;
                } else {
                    der = med;
                    med = med / 2;
                }
            }
        }
    } else {
        while (!seAlcanzoTamanio0 && !encontrado) {
            if (der - izq == 0) {
                seAlcanzoTamanio0 = true;
            }
            if (v[med] == x) {
                encontrado = true;
                res = med;
            } else {
                if (v[med] < x) {
                    izq = med + 1;
                    med = (izq + der) / 2;
                } else {
                    der = med;
                    med = med / 2;
                }
            }
        }
    }
    return res;
}

int busquedaJumpSearch(vector<int> v, int x) {
    //este algoritmos funciona como una busqueda lineal cuando el vector esta ordenado al reves
    //lo ideal seria utilizar la misma estrategia pero a la inversa
    int res = -1;
    int m = 0;
    bool encontrado = false;
    int raiz = (int) sqrt(v.size());
    while (v[m] < x && m < v.size()) {
        m = m + raiz;
    }
    if (m != 0) {
        m = m - raiz;
    }
    for (int i = m; i < v.size() && !encontrado; i++) {
        if (v[i] == x) {
            encontrado = true;
            res = i;
        }
    }
    return res;
}

int buscar(vector<int> v, int x) {
    return busquedaBinaria(v, x);
    //return busquedaJumpSearch(v, x);
}

//Ejercicio 2
double calculadoraTiempos(vector<int> v, string operacion, int i, int value) {
    using namespace std;
    clock_t begin = clock();

    if (operacion == "size") {
        clock_t begin = clock();
        clock_t end = clock();
        v.size();
        double elapsed_secs = double(end - begin) / (CLOCKS_PER_SEC / 1000);

    } else if (operacion == "push") {
        clock_t begin = clock();
        v.push_back(2);
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / (CLOCKS_PER_SEC / 1000);
    } else if (operacion == "pop") {
        clock_t begin = clock();
        v.pop_back();
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / (CLOCKS_PER_SEC / 1000);
    } else if (operacion == "[]") {
        clock_t begin = clock();
        v[i];
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / (CLOCKS_PER_SEC / 1000);
    } else if (operacion == "asignacion") {
        clock_t begin = clock();
        v[i] = value;
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / (CLOCKS_PER_SEC / 1000);
    } else if (operacion == "clear") {
        clock_t begin = clock();
        v.clear();
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / (CLOCKS_PER_SEC / 1000);
    } else {
        clock_t begin = clock();
        v.empty();
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / (CLOCKS_PER_SEC / 1000);
    }

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / (CLOCKS_PER_SEC / 1000);
    return elapsed_secs;
}

vector<int> construir_vector(int size, string mode) {
    vector<int> res{};
    time_t t;
    srand((unsigned) time(&t));
    int base = rand() % 100;
    int step;
    for (int i = 0; i < size; i++) {
        step = rand() % 100;
        if (mode == "asc") {
            res.push_back(base + step);
            base += step;
        }
        if (mode == "desc") {
            res.push_back(base - step);
            base -= step;
        }
        if (mode == "azar") {
            res.push_back(step);
        }
        if (mode == "iguales") {
            res.push_back(base);
        }
    }
    return res;
}

double tiempoEjecucion(string tipo, vector<int> v) {
    using namespace std;
    clock_t begin = clock();
    if (tipo == "binaria") {
        //asegura que el valor no este en v y asi es el peor caso de busqueda binaria
        int value = v[0] - 1;
        int i = busquedaBinaria(v, value);
    } else {
        int value = 5;
        int i = busquedaJumpSearch(v, value);
    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / (CLOCKS_PER_SEC / 1000);
    return elapsed_secs;
}

/* Los valores obtenidos fueron (tomando siempre misma entrada ascendente
    0.008 0.006 0.021 1.073

    0.009 0.009 0.025 0.956


a)Se puede ver que los valores cambian, pero poco.Los valores siempre estan dentro de un rango
 y son muy parecidos por lo que en cierta forma "se podria decir que no cambian". o no dependen mucho de las constantes
 en general dependen mas del tamaño de la entrada como se ve al aumentar el tamaño de entrada aumenta el valor de tiempo y tambien
 noto que esto se debe a las constantes en los casos porque las operaciones cuestan lo mismo se supone.
 b)Segun la aproximacion de arriba sabemos que el algoritmos entra siempre en peor caso dado que se estara buscando un
 elemento del vector que no esta en el mismo y por lo tanto tiene que hacer todas las iteraciones luego suponiendo que es algo de la
 forma Clog2(n)
 c100 = 0.0012       c100 = 0.0014
 c1000= 0.0006       c1000 = 0.0009
 c10000 = 0.0016     c10000 = 0.0016
 c100000 = 0.064      c100000 = 0.057

 De manera que asi podemos ver los valores que toma c pareceria ser para mi que c = 0.001 masomenos aunque los ultimos valores dan algo mayor
 puede tener que ver un poco con que el algoritmo puede ser que en tiempo sea Clog(n)+C2log(n)+...+CN=Clog(n)+C
 quizas la C final crece por alguna razon.

Para realizar la estimacion de C para el algoritmos de jumpSearch
 */

//Ejercicio 3
/*
Estimaciones de busqueda binaria
0.008 0.006 0.02 0.843
Estimaciones de JumpSearch
0.007 0.026 0.241 2.872
Evaluacion del size
0.012 0.01 0.01 0.014
Evaluacion del push
0.019 0.013 0.021 0.778
Evaluacion del pop
0.012 0.011 0.017 0.012
Evaluacion del []
0.013 0.011 0.009 0.01
Evaluacion del asignacion
0.012 0.01 0.011 0.01
Evaluacion del clear
0.012 0.012 0.01 0.01
Evaluacion del empty
0.01 0.012 0.01 0.01
 *
 * Conclusiones
 *
 * Size: es constante O(1)
 * Push: pareceria ser dependiente del tamaño del vector los tiempos son mayores a los de jumpSearch o busqueda binaria.
 * sin embargo se sabe que es O (1) salvo en algunos casos donde puede ser O(n)
 * Pop: es constante O(1)
 * [] : es constante O(1) no depende claramente del i
 * asignacion : es constante O(1) no depende claramente del i
 * Clear : es constante O(1)
 * Empty : es constante O(1)
 *
 * */
//Ejercicio 4
int indicePico(vector<int> v) {
    int medio = v.size() / 2;
    int primero = 0;
    int ultimo = v.size() - 1;
    bool encontrado = false;
    int res = -1;
    while (ultimo - primero >= 0 && !encontrado) {
        if (ultimo - primero == 0) {
            res = primero;
            encontrado = true;
        } else if (ultimo - primero == 1) {
            if (v[primero] > v[ultimo]) {
                res = primero;
                encontrado = true;
            } else {
                res = ultimo;
                encontrado = true;
            }
        } else if (v[medio] >= v[medio - 1] && v[medio] >= v[medio + 1]) {
            res = medio;
            encontrado = true;
        } else if (v[medio + 1] > v[medio]) {
            primero = medio + 1;
            medio = (primero + ultimo) / 2;
        } else {
            ultimo = medio;
            medio = (primero + medio) / 2;
        }
    }
    return res;
}

//Ejercicio 5
int puntoFijo(vector<int> v) {
    int med = v.size() / 2;
    int izq = 0;
    int der = v.size() - 1;
    int res = -1;
    bool tamanioMinimo = false;
    while (!tamanioMinimo) {
        if (der - izq == 0) {
            tamanioMinimo = true;
        }
        if (v[med] == med) {
            if (der - izq == 0) {
                res = med;
                tamanioMinimo = true;
            } else {
                res = med;
                der = med;
                med = med / 2;
            }
        }
        if (v[med] > med) {
            der = med;
            med = med / 2;
        } else {
            izq = med + 1;
            med = (izq + der) / 2;
        }

    }
    return res;
}

//Ejercicio 6
int encontrarRotado(vector<int> v, int x) {
    int medio = v.size() / 2;
    int ultimo = v.size() - 1;
    int primero = 0;
    int res = -1;
    bool encontrado = false;
    while (ultimo - primero > 0 && !encontrado) {
        if (x == v[medio]) {
            res = medio;
            encontrado = true;
        } else if (x > v[medio]) {
            if (x < v[ultimo]) {
                primero = medio;
                medio = medio + ultimo / 2;
            } else {
                ultimo = medio;
                medio = primero + medio / 2;
            }
        } else {
            if (v[primero] < x) {
                ultimo = medio;
                medio = primero + medio / 2;
            } else {
                primero = medio;
                medio = medio + ultimo / 2;
            }
        }
    }
    if (ultimo - primero == 0) {
        if (v[medio] == x) {
            res = medio;
        }
    }

    return res;
}

//Ejercicio 7
int menorMasGrande(vector<int> v, int x) {
    int izq = 0;
    int der = v.size() - 1;
    int med = (izq + der) / 2;
    int res = -1;
    bool tamanioMinimo = false;
    while (!tamanioMinimo) {
        if (v[med] >= x) {
            res = med;
            der = med;
            med = med / 2;
        } else {
            izq = med + 1;
            med = (izq + der) / 2;
        }
        if (der - izq == 0) {
            tamanioMinimo = true;
        }
    }
    return res;
}

//Ejercicio 8
//PRE: Seguro hay uno que devolver.
int posicionDelMasCercanoEnModulo(vector<int> v, int x) {
    int medio = v.size() / 2;
    int izquierda = 0;
    int derecha = v.size() - 1;
    int res = medio;
    bool encontrado = false;
    while (!encontrado) {
        if (abs(x - v[medio]) <= abs(x - v[medio - 1]) && abs(x - v[medio]) <= abs(x - v[medio + 1])) {
            res = medio;
            encontrado = true;
        } else if (abs(x - v[medio]) > abs(x - v[medio - 1]) && abs(x - v[medio - 1]) < abs(x - v[medio + 1])) {
            derecha = medio;
            medio = (medio + izquierda) / 2;
        } else {
            izquierda = medio;
            medio = (medio + derecha) / 2 + 1;
        }
    }
    return res;
}

vector<int> masCercanoK(vector<int> v, int k, int x) {
    int pos = posicionDelMasCercanoEnModulo(v, x);
    int izq = pos;
    int der = pos;
    bool finalAlcanzado = false;
    vector<int> res = {};

    while (der - izq < k && !finalAlcanzado) {
        if (pos == 0 || izq == 0) {
            if (der == v.size() - 1) {
                finalAlcanzado = true;
                izq--;
            } else {
                der++;
            }
        } else if (pos == v.size() - 1 || izq == v.size() - 1) {
            if (izq > 0) {
                izq--;
            }
        } else if (abs(v[der + 1] - x) >= abs(v[izq - 1] - x)) {
            izq--;
        } else {
            der++;
        }
    }
    if (v.size() > 1) {
        if (v[0] > v[1]) {
            for (int i = der; i > izq; i--) {
                res.push_back(v[i]);
            }
        } else {
            for (int i = izq; i < der; i++) {
                if (v[i] != x) {
                    res.push_back(v[i]);
                }
            }
        }
    } else if (v.size() == 1) {
        if (k == 1) {
            res.push_back(v[izq]);
        }
    }
    return res;
}