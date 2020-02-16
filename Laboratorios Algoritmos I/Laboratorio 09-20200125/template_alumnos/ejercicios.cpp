#include "ejercicios.h"
#include "time.h"
#include <ctime>
#include "stdlib.h"
#include <string>
#include <cmath>
#include<iostream>

using namespace std;

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

double ejemplo_como_calcular_tiempos() {
    using namespace std;
    clock_t begin = clock();

    for (int i = 0; i < 100000; i++) {
        // nada
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

//Ejercicio 2

double tiempoEjecucion (int size, string mode,string tipo){
    vector<int> v = construir_vector(size,mode);
    using namespace std;
    clock_t begin = clock();
    if(tipo == "binaria"){
        int i = busquedaBinaria(v,5);
    }
    else{
        int i = busquedaJumpSearch(v,5);
    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / (CLOCKS_PER_SEC / 1000);
    return elapsed_secs;
}
/* Los valores obtenidos fueron
 * Binaria asc y dsc


a) 
b)

 * */

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