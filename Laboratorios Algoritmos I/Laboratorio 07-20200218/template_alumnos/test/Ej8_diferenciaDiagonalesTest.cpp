#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(diferenciaDiagonalesTest, diag1MasGrande){
    vector<vector<int> > m = {
            {10,2,3,4},
            {5,10,7,8},
            {10,9,8,7},
            {4,0,0,1}
    };
    int res = diferenciaDiagonales(m);
    EXPECT_EQ(5,res);
}

TEST(diferenciaDiagonalesTest, diag2MasGrande){
    vector<vector<int> > m = {
            {1,2,3,4},
            {5,6,7,8},
            {10,9,8,7},
            {0,0,0,1}
    };
    int res = diferenciaDiagonales(m);
    EXPECT_EQ(4,res);
}

TEST(diferenciaDiagonalesTest, iguales){
    vector<vector<int> > m = {
            {1,2,3,1},
            {5,2,2,8},
            {10,3,3,7},
            {4,0,0,4}
    };
    int res = diferenciaDiagonales(m);
    EXPECT_EQ(0,res);
}

TEST(diferenciaDiagonalesTest, negativos){
    vector<vector<int> > m = {
            {-1,2,3,-4},
            {5,-6,7,8},
            {1,-9,-8,7},
            {0,0,0,1}
    };
    int res = diferenciaDiagonales(m);
    EXPECT_EQ(8,res);
}

TEST(diferenciaDiagonalesTest, dosXdos){
    vector<vector<int> > m = {
            {-1,2},
            {6,-6}
    };
    int res = diferenciaDiagonales(m);
    EXPECT_EQ(15,res);
}

TEST(diferenciaDiagonalesTest, unoXuno){
    vector<vector<int> > m = {
            {-1}
    };
    int res = diferenciaDiagonales(m);
    EXPECT_EQ(0,res);
}