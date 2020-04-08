#include "../llenarTaxis.h"
#include "gtest/gtest.h"

// Tests Primera
TEST(LlenarTaxisTest1, TodasLasVariablesConElMismoValor) {
    int n = llenarTaxis1(1, 1, 1);
    EXPECT_EQ(n,2);
}
TEST(LlenarTaxisTest1, ConGruposDeDiferenteTamanio) {
    int n = llenarTaxis1(3, 1, 2);
    EXPECT_EQ(n,3);
}
TEST(LlenarTaxisTest1, ConG2Impar1) {
    int n = llenarTaxis1(3, 1, 2);
    EXPECT_EQ(n,3);
}
TEST(LlenarTaxisTest1, ConG2Impar0) {
    int n = llenarTaxis1(2, 1, 2);
    EXPECT_EQ(n,3);
}
TEST(LlenarTaxisTest1, ConG2Par2) {
    int n = llenarTaxis1(3, 2, 1);
    EXPECT_EQ(n,3);
}
TEST(LlenarTaxisTest1, ConG2Par0) {
    int n = llenarTaxis1(3, 2, 1);
    EXPECT_EQ(n,3);
}

//Test Segunda
TEST(LlenarTaxisTest2, TodasLasVariablesConElMismoValor) {
    int n = llenarTaxis2(1, 1, 1);
    EXPECT_EQ(n,2);
}
TEST(LlenarTaxisTest2, ConGruposDeDiferenteTamanio) {
    int n = llenarTaxis2(3, 1, 2);
    EXPECT_EQ(n,3);
}
TEST(LlenarTaxisTest2, ConG2Impar1) {
    int n = llenarTaxis2(3, 1, 2);
    EXPECT_EQ(n,3);
}
TEST(LlenarTaxisTest2, ConG2Impar0) {
    int n = llenarTaxis2(2, 1, 2);
    EXPECT_EQ(n,3);
}
TEST(LlenarTaxisTest2, ConG2Par2) {
    int n = llenarTaxis2(3, 2, 1);
    EXPECT_EQ(n,3);
}
TEST(LlenarTaxisTest2, ConG2Par0) {
    int n = llenarTaxis2(3, 2, 1);
    EXPECT_EQ(n,3);
}
//Test Tercera

TEST(LlenarTaxisTest3, TodasLasVariablesConElMismoValor) {
    int n = llenarTaxis3(1, 1, 1);
    EXPECT_EQ(n,2);
}
TEST(LlenarTaxisTest3, ConGruposDeDiferenteTamanio) {
    int n = llenarTaxis3(3, 1, 2);
    EXPECT_EQ(n,3);
}
TEST(LlenarTaxisTest3, ConG2Impar1) {
    int n = llenarTaxis3(3, 1, 2);
    EXPECT_EQ(n,3);
}
TEST(LlenarTaxisTest3, ConG2Impar0) {
    int n = llenarTaxis3(2, 1, 2);
    EXPECT_EQ(n,3);
}
TEST(LlenarTaxisTest3, ConG2Par2) {
    int n = llenarTaxis3(3, 2, 1);
    EXPECT_EQ(n,3);
}
TEST(LlenarTaxisTest3, ConG2Par0) {
    int n = llenarTaxis3(3, 2, 1);
    EXPECT_EQ(n,3);
}