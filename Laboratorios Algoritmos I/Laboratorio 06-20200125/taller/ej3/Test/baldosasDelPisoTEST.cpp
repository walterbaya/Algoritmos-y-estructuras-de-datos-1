#include "../baldosasDelPiso.h"
#include "gtest/gtest.h"

// Escribir tests aca:

TEST(ambosDivisibles,baldosas){
    int N=4;
    int M=4;
    int B=2;
    EXPECT_EQ(baldosasDelPiso(M,N,B),4);
}

TEST(mDivisible,baldosas){
    int N=6;
    int M=12;
    int B=4;
    EXPECT_EQ(baldosasDelPiso(M,N,B),6);
}

TEST(nDivisible,baldosas){
    int N=50;
    int M=12;
    int B=10;
    EXPECT_EQ(baldosasDelPiso(M,N,B),10);
}
TEST(ningunoDivisible,baldosas){
    int N=6;
    int M=6;
    int B=4;
    EXPECT_EQ(baldosasDelPiso(M,N,B),4);
}
