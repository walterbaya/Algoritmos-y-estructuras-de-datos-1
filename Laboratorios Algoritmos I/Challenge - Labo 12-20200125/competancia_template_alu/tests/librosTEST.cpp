//
// Created by Pablo on 24/11/2017.
//

#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <vector>
#include "../libros.h"

using namespace std;


TEST(testLibros, prueba1) {

    string filename = "datos/libros/1-01";
    vector<int> p;
    int s;
    long out;

    p = leerEntrada(filename+".in",s);

    out = caminoMasCorto(p,s);

    EXPECT_EQ(out, leerRta(filename+".out"));
}

TEST(testLibros, prueba2) {

    string filename = "datos/libros/2-06";
    vector<int> p;
    int s;
    long out;

    p = leerEntrada(filename+".in",s);

    out = caminoMasCorto(p,s);

    EXPECT_EQ(out, leerRta(filename+".out"));
}

TEST(testLibros, prueba3) {

    string filename = "datos/libros/4-09";
    vector<int> p;
    int s;
    long out;

    p = leerEntrada(filename+".in",s);

    out = caminoMasCorto(p,s);

    EXPECT_EQ(out, leerRta(filename+".out"));
}

TEST(testLibros, prueba4) {

    string filename = "datos/libros/5-10";
    vector<int> p;
    int s;
    long out;

    p = leerEntrada(filename+".in",s);

    out = caminoMasCorto(p,s);

    EXPECT_EQ(out, leerRta(filename+".out"));
}
