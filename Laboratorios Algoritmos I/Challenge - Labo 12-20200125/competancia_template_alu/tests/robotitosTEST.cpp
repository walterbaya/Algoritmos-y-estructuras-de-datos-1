//
// Created by Pablo on 24/11/2017.
//

#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <vector>
#include "../robotitos.h"

using namespace std;


TEST(testRobots, prueba1) {

    string s = "datos/robotitos/sample1";
    vector<int> X;
    vector<int> Y;
    vector<int> W;
    vector<int> S;
    int A,B,T, out;

    int res = leerDatos(s+".in",A,B,T,X,Y,W,S);

    out = calcularTiempoRecoleccion(A,B,T,X,Y,W,S);

    EXPECT_EQ(out, leerTiempoReal(s+".out"));
}

TEST(testRobots, prueba2) {

    string s = "datos/robotitos/sample2";
    vector<int> X;
    vector<int> Y;
    vector<int> W;
    vector<int> S;
    int A,B,T, out;

    int res = leerDatos(s+".in",A,B,T,X,Y,W,S);

    out = calcularTiempoRecoleccion(A,B,T,X,Y,W,S);

    EXPECT_EQ(out, leerTiempoReal(s+".out"));
}

TEST(testRobots, prueba3) {

    cout << "Prueba 3" << endl;
    string s = "datos/robotitos/st1-point-on-line-weak";
    vector<int> X;
    vector<int> Y;
    vector<int> W;
    vector<int> S;
    int A,B,T, out;

    int res = leerDatos(s+".in",A,B,T,X,Y,W,S);

    out = calcularTiempoRecoleccion(A,B,T,X,Y,W,S);

    EXPECT_EQ(out, leerTiempoReal(s+".out"));
}
