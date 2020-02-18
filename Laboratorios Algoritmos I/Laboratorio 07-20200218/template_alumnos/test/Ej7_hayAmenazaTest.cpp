#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(hayAmenazaTest, matriz1) {
	vector<vector<int> > vec(8,vector<int>(8,0));
	vec[0][2] = vec[1][5] = vec[2][3] = vec[3][0] = vec[4][7] = vec[5][4] = vec[6][6] = vec[7][1] = 1;
	ASSERT_EQ(0, hayAmenaza(vec));
}

TEST(hayAmenazaTest, matriz2) {
	vector<vector<int> > vec(8,vector<int>(8,0));
	vec[0][2] = vec[1][5] = vec[2][3] = vec[3][0] = vec[4][7] = vec[5][1] = vec[6][6] = vec[7][4] = 1;
	ASSERT_EQ(1, hayAmenaza(vec));
}

TEST(hayAmenazaTest, matriz3) {
	vector<vector<int> > vec(3,vector<int>(4,0));
	vec[0][0] = vec[1][3] = vec[2][1] = 1;
	ASSERT_EQ(0, hayAmenaza(vec));
}

TEST(hayAmenazaTest, matriz4) {
	vector<vector<int> > vec(3,vector<int>(4,0));
	vec[0][0] = vec[2][3] = vec[2][1] = 1;
	ASSERT_EQ(1, hayAmenaza(vec));
}

TEST(hayAmenazaTest, matriz5) {
	vector<vector<int> > vec(3,vector<int>(4,0));
	vec[0][0] = vec[1][3] = vec[2][3] = 1;
	ASSERT_EQ(1, hayAmenaza(vec));
}




