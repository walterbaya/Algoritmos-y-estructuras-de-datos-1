#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(esTriangularTest, triangularSuperior){
    vector<vector<int> > m = {
            {1,2,0,4},
            {0,2,0,0},
            {0,0,3,4},
            {0,0,0,4}
        };
    bool res = esTriangular(m);
    EXPECT_TRUE(res);
}

TEST(esTriangularTest, triangularInferior){
    vector<vector<int> > m = {
            {1,0,0,0},
            {0,2,0,0},
            {0,8,3,0},
            {0,0,0,4}
    };
    bool res = esTriangular(m);
    EXPECT_TRUE(res);
}

TEST(esTriangularTest, casiTriangular){
    vector<vector<int> > m = {
            {1,0,0,0},
            {0,2,3,0},
            {0,0,3,0},
            {1,0,0,0}
    };
    bool res = esTriangular(m);
    EXPECT_FALSE(res);
}

TEST(esTriangularTest, cerosEnDiagonal){
    vector<vector<int> > m = {
            {0,0,0,4},
            {0,0,0,0},
            {0,0,0,0},
            {1,0,0,0}
    };
    bool res = esTriangular(m);
    EXPECT_FALSE(res);
}

TEST(esTriangularTest, dosXdos){
    vector<vector<int> > m = {
            {1,8},
            {0,2},
    };
    bool res = esTriangular(m);
    EXPECT_TRUE(res);
}