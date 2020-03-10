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
//Si habria que modificar el codigo reemplazando el res por true al inicio y que cuando encuentre un pico se haga falso
//en ese caso se cumple el invariante.

// Ejercicio 2
//a y b son variables de control como i j

//PRE: n>0 && m > 0
int mcd(int m, int n) {
    int a = n;
    int b = m;
    int res = n;
    //PC : a == n && b == m && res == n
    while (a != b) {
        if (a < b) {
            b = b - a;
        } else {
            a = a - b;
        }
    }
    //QC: a == mcd(m,n)
    res = a;
    return res;
}
//QC: res == mcd(m,n)

// Ejercicio 3
int indiceMinSubsec(vector<int> v, int l, int r) {
    int res = r;
    for (int i = r; i >= l; i--) {
        if (v[res] > v[i]) {
            res = i;
        }
    }
    return res;
}

// Ejercicio 4
//Esto es el selection sort
void ordenar1(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        int temp = v[i];
        v[i] = v[indiceMinSubsec(v, i, v.size() - 1)];
        v[indiceMinSubsec(v, i, v.size() - 1)] = temp;
    }
}

// Ejercicio 5
void ordenar2(vector<int> &v) {
    int ceros = 0;
    int unos = 0;
    int dos = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0) {
            ceros++;
        } else if (v[i] == 1) {
            unos++;
        } else {
            dos++;
        }
    }
    for (int j = 0; j < ceros; j++) {
        v[j] = 0;
    }
    for (int k = ceros; k < unos + ceros; k++) {
        v[k] = 1;
    }
    for (int l = unos + ceros; l < dos + unos + ceros; l++) {
        v[l] = 2;
    }
}

//la idea de este ejercicio es hacer algo muy parecido a una cosa llamada bucket sort que se ve en algoritmos II
//esta forma toma O(n) es mas eficiente que la manera ingenua de hacerlo, de todas maneras el objetivo del ejercicio
//no era pensar en complejidades

// Ejercicio 6
tuple<int, int> division(int n, int d) {
    int q = 0;
    int r = n;
    while (r >= d) {
        q++;
        r -= d;
    }
    return make_tuple(q, r);
}
