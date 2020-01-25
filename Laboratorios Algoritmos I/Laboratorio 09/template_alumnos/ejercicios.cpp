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


int indicePico(vector<int> v) {
    return -1;
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
    return -1;
}

int menorMasGrande(vector<int> v, int x) {
    return -1;
}

vector<int> masCercanoK(vector<int> v, int k, int x) {
    return {};
}
