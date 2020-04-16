#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(WillieElRobot, 4X4){
    vector<vector<int> > m = {
            {1,0,0,0},
            {0,0,0,0},
            {0,0,0,0},
            {0,0,0,0}
    };
    int res = williElRobot(m);
    EXPECT_EQ(20,res);
}

TEST(WillieElRobot, 3X4){
    vector<vector<int> > m = {
            {1,0,0,0},
            {0,0,0,0},
            {0,0,0,0}
    };
    int res = williElRobot(m);
    EXPECT_EQ(10,res);
}

TEST(WillieElRobot, 1X1){
    vector<vector<int> > m = {
            {1}
    };
    int res = williElRobot(m);
    EXPECT_EQ(1,res);
}

TEST(WillieElRobot, 1X4){
    vector<vector<int> > m = {
            {1,0,0,0}
    };
    int res = williElRobot(m);
    EXPECT_EQ(1,res);
}