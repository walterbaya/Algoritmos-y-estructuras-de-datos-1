//
// Created by Pablo on 22/11/2017.
//

#ifndef CLION_UTILES_H
#define CLION_UTILES_H

#include <vector>
#include <string>

using namespace std;

int leerTiempoReal(string s);
int leerDatos(string s, int& A, int& B, int& T, vector<int>& X, vector<int>& Y, vector<int>& W, vector<int>& S);
int calcularTiempoRecoleccion(int A, int B, int T, vector<int> X, vector<int> Y, vector<int> W, vector<int> S);

#endif //CLION_UTILES_H
