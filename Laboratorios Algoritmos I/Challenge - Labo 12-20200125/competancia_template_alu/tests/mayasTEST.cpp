#include "gtest/gtest.h"
#include "../mayas.h"
#include <sstream>

#define test(i,s) TEST(mayaTEST, s){string path = "datos/maya/"; stringstream sin; sin << "writing" << i << ".in"; string filename_in = path + sin.str(); stringstream sout; sout << "writing" << i << ".res"; string filename_out = path + sout.str(); tuple<string,string> t = leerEntrada(filename_in); int actual = posiblesApariciones(get<0>(t), get<1>(t)); int expected = leerSalida(filename_out); EXPECT_EQ(actual, expected);}

test(1,writing1);
test(2,writing2);
