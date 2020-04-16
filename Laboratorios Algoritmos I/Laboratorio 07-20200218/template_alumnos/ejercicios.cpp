#include "ejercicios.h"

vector<vector<int> > productoVectorial(vector<int> u, vector<int> v) {
    vector<vector<int>> res(u.size(), vector<int>(v.size()));
    for (int i = 0; i < u.size(); i++) {
        for (int j = 0; j < u.size(); j++) {
            res[i][j] = u[i] * v[j];
        }
    }
    return res;
}

void trasponer(vector<vector<int> > &m) {
    vector<vector<int>> res(m.size(), vector<int>(m.size()));
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size(); j++) {
            res[i][j] = m[j][i];
        }
    }
}

vector<vector<int> > multiplicar(vector<vector<int> > m1, vector<vector<int> > m2) {
    vector<vector<int> > res(m1.size(), vector<int>(m2[0].size()));
    for (int i = 0; i < m1.size(); i++) {
        for (int j = 0; j < m2[0].size(); j++) {
            for (int k = 0; k < m2.size(); k++) {
                res[i][j] = res[i][j] + m1[i][k] * m2[k][j];
            }
        }
    }
    return res;
}

int auxPromedioVecinos(vector<vector<int> > m, int i, int j) {
    int suma = m[i][j];
    int cantidad = 0;
    for (int k = j - 1; k <= j + 1; k++) {
        for (int l = i - 1; l <= i + 1; l++) {
            if (k >= 0 && k < m.size() && l >= 0 && l < m[0].size()) {
                suma = m[k][l] + suma;
                cantidad++;
            }
        }
    }
    return suma / cantidad;
}

vector<vector<int> > promediar(vector<vector<int> > m) {
    vector<vector<int> > res(m.size(), vector<int>(m[0].size()));
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++) {
            res[i][j] = auxPromedioVecinos(m, i, j);
        }
    }
    return res;
}


bool esPico(vector<vector<int>> m, int i, int j) {
    bool res = true;
    for (int k = i - 1; k <= i + 1 && res; k++) {
        for (int l = j - 1; l <= j + 1 && res; l++) {
            if (k >= 0 && l >= 0 && k < m.size() && l < m[0].size()) {
                res = m[k][l] < m[i][j] || (i == k && j == l);
            }
        }
    }
    return res;
}

int contarPicos(vector<vector<int> > m) {
    int res = 0;
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++) {
            if (esPico(m, i, j)) {
                res++;
            }
        }
    }
    return res;
}


bool esTriangularInferior(vector<vector<int> > m) {
    bool res = true;
    for (int i = 0; i < m.size(); i++) {
        bool aux = true;
        for (int j = i + 1; j < m.size(); j++) {
            if (m[i][j] != 0 && aux) {
                res = false;
                aux = false;
            }
        }
    }
    return res;
}

bool esTriangularSuperior(vector<vector<int> > m) {
    bool res = true;
    for (int i = 0; i < m.size(); i++) {
        bool aux = true;
        for (int j = 0; j < i; j++) {
            if (m[i][j] != 0 && aux) {
                res = false;
                aux = false;
            }
        }
    }
    return res;
}

bool esTriangular(vector<vector<int> > m) {
    return esTriangularInferior(m) || esTriangularSuperior(m);
}

//Usare abs provisto por las libreria para no implementarlo ya que fue implementado anteriormente en otra clase.
bool seAmenazan(int i1, int j1, int i2, int j2) {
    return (i1 != i2 || j1 != j2) && (i1 == i2 || j1 == j2 || abs(i1 - i2) == abs(j1 - j2));
}

bool amenazaAlguna(vector<vector<int> > m, int i1, int j1) {
    bool res = false;
    for (int i2 = 0; i2 < m.size() && !res; i2++) {
        for (int j2 = 0; j2 < m[0].size() && !res; j2++) {
            res = seAmenazan(i1, j1, i2, j2) && m[i2][j2] == 1;
        }
    }
    return res;
}

bool existeAmenaza(vector<vector<int> > m) {
    bool res = false;
    for (int i1 = 0; i1 < m.size() && !res; i1++) {
        for (int j1 = 0; j1 < m[0].size() && !res; j1++) {
            res = amenazaAlguna(m, i1, j1) && m[i1][j1] == 1;
        }
    }
    return res;
}

bool hayAmenaza(vector<vector<int> > m) {
    return existeAmenaza(m);
}

int diferenciaAbsoluta(int a, int b) {
    int res = b - a;
    if (a > b) {
        res = a - b;
    }
    return res;
}

int diferenciaDiagonales(vector<vector<int> > m) {
    int sumaDiagonal1 = 0;
    int sumaDiagonal2 = 0;
    for (int i = 0; i < m.size(); i++) {
        sumaDiagonal1 = m[i][i] + sumaDiagonal1;
        sumaDiagonal2 = m[i][m.size() - 1 - i] + sumaDiagonal2;
    }
    return diferenciaAbsoluta(sumaDiagonal2, sumaDiagonal1);
}


//Los ejercicios de ta te ti fueron subidos al tateti que se podra encontrar proximamente en mi git!! con el juego mismo.
=======
int nroCaminos(vector<vector<int> > m, int i, int j) {
    if (j == 0 || i == 0) {
        return 1;
    } else {
        return nroCaminos(m, i, j - 1) + nroCaminos(m, i - 1, j);
    }
}

/*
 * 1 2 3
 * 1 2 3
 * 1 2 3
 *
 * */
//PRE se supone que no va a ser vacia porque el robot no podria estar en ningun lugar.
int williElRobot(vector<vector<int> > m) {
    return nroCaminos(m, m.size() - 1, m[0].size() - 1);
}

