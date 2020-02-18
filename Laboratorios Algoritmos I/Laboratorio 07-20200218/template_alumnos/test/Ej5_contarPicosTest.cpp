#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(contarPicosTest, matriz1) {
	vector<vector<int> > vec(10,vector<int>(10));
	for(int i=0;i<10;i++) {
		for(int j=0;j<10;j++) {
			vec[i][j] = ((1<<i)*((j+10)*41))%13;
		}
	}

	ASSERT_EQ(8, contarPicos(vec));
}

TEST(contarPicosTest, matriz2) {
	vector<vector<int> > vec(20,vector<int>(40,0));
	for(int i=0;i<10;i++) {
		for(int j=0;j<20;j++) {
			vec[2*i][2*j] = 1;
		}
	}
	ASSERT_EQ(200, contarPicos(vec));
}
