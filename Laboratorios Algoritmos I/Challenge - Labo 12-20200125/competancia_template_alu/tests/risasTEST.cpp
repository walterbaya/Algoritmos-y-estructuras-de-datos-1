
#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include "../risas.h"

using namespace std;


/* Test Alumnos */
TEST(carcajadasTEST, prueba1) {

    vector<char> vdata;
    string s = "datos/risas/01";

    vdata = leerDatos(s);

    int N = risaMasLarga(vdata);

    EXPECT_EQ(N, 5);
}

TEST(carcajadasTEST, prueba2) {

    vector<char> vdata;
    string s = "datos/risas/54";

    vdata = leerDatos(s);

    int N = risaMasLarga(vdata);

    EXPECT_EQ(N, 86);
}
/* Test Alumnos */
