#include "../template-alumnos/ejercicios.h"


// Ejercicio 1
bool existePico(vector<int> v) {
    int i = 1;
    bool res = false;
    while (i < v.size() - 1) {
        if (v[i] > v[i + 1] && v[i] > v[i - 1]) {
            res = true;
        }
        i++;
    }
    return res;
}

// Ejercicio 2
int mcd(int m, int n) {
    return 0;
}

// Ejercicio 3
int indiceMinSubsec(vector<int> v, int l, int r) {
    return 0;
}

// Ejercicio 4
void ordenar1(vector<int> &v) {
    return;
}

// Ejercicio 5
void ordenar2(vector<int> &v) {
    return;
}

// Ejercicio 6
tuple<int, int> division(int n, int d) {
    return make_tuple(0, 0);
}
