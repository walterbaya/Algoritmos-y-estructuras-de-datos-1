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

vector<vector<int> > promediar(vector<vector<int> > m) {
    //COMPLETAR
    vector<vector<int> > res;
    return res;
}

int contarPicos(vector<vector<int> > m) {
    //COMPLETAR
    return 1;
}

bool esTriangular(vector<vector<int> > m) {
    //COMPLETAR
    return true;
}

bool hayAmenaza(vector<vector<int> > m) {
    //COMPLETAR
    return true;
}

int diferenciaDiagonales(vector<vector<int> > m) {
    //COMPLETAR
    return 0;
}