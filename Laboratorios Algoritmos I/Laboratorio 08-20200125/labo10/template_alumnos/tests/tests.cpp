#include "../gtest/gtest.h"
#include "../src/ejercicios.h"

/////////////////////////// split ///////////////////////////
TEST(splitTest, vacio){
	vector<string> v = {};
	ASSERT_EQ(v, split("", ' '));
}

TEST(splitTest, frase){
	vector<string> v = {"hola", "mundo", "se", "programar"};
	ASSERT_EQ(v, split("hola mundo se programar", ' '));
}

TEST(splitTest, sinEspacios){
	vector<string> v = {"hola"};
	ASSERT_EQ(v, split("hola", ' '));
}

TEST(splitTest, EspacioAlFinal){
	vector<string> v = {"hola"};
	ASSERT_EQ(v, split("hola ", ' '));
}

TEST(splitTest, EspacioAlPrincipio){
	vector<string> v = {"hola"};
	ASSERT_EQ(v, split(" hola", ' '));
}

TEST(splitTest, variosEspciosEnElMedio){
	vector<string> v = {"Esto", "es", "un", "string", "con", "distintos", "espaciados"};
	ASSERT_EQ(v, split("Esto   es un   string  con distintos   espaciados", ' '));
}

TEST(splitTest, otroDelimitador){
	vector<string> v = {"Toto", " Cholo", " Tom", " Moncho", " Rodolfo", " Otto", " Pololo"};
	ASSERT_EQ(v, split("Toto, Cholo, Tom, Moncho, Rodolfo, Otto, Pololo", ','));
}

/////////////////////////// darVueltaPalabra ///////////////////////////

TEST(darVueltaPalabraTest, unaPalabra){
	ASSERT_EQ("hola", darVueltaPalabra("hola"));
}

TEST(darVueltaPalabraTest, variosPalabras){
	ASSERT_EQ("programar se mundo hola", darVueltaPalabra("hola mundo se programar"));
}

TEST(darVueltaPalabraTest, variosEspacios){
	ASSERT_EQ("programar se mundo hola", darVueltaPalabra("  hola   mundo   se   programar  "));
}

TEST(darVueltaPalabraTest, vacio){
	ASSERT_EQ("", darVueltaPalabra(""));
}

/////////////////////////// subsecuencia ///////////////////////////

TEST(subsecuenciaTest, vacias){
	ASSERT_TRUE(subsecuencia("", ""));
}

TEST(subsecuenciaTest, s1MasGrande){
	ASSERT_FALSE(subsecuencia("asdas", "sd"));
}

TEST(subsecuenciaTest, iguales){
	ASSERT_TRUE(subsecuencia("asds", "asds"));
}

TEST(subsecuenciaTest, substring){
	ASSERT_TRUE(subsecuencia("asd", "juasdop"));
}

TEST(subsecuenciaTest, subsec){
	ASSERT_TRUE(subsecuencia("asd", "laaidsakikdop"));
}

TEST(subsecuenciaTest, desordendos){
	ASSERT_FALSE(subsecuencia("aiksd", "lllaaiiissskikdop"));
}

TEST(subsecuenciaTest, s1Repes){
	ASSERT_FALSE(subsecuencia("asdasdds", "aadasdasds"));
	ASSERT_TRUE(subsecuencia("asdasdds", "laaiskjhsdsmamksmdsds"));
}

/////////////////////////// agruparAnagramas ///////////////////////////

TEST(agruparAnagramas, unElemento) {
	vector<string> in = {"hola"};
	vector<vector<string> > out = {{"hola"}};
	ASSERT_EQ(out, agruparAnagramas(in));
}

TEST(agruparAnagramas, unoDeCada) {
	vector<string> in = {"hola","solo","uno","otro"};
	vector<vector<string> > out = {{"hola"},{"solo"},{"uno"},{"otro"}};
	ASSERT_EQ(out, agruparAnagramas(in));
}

TEST(agruparAnagramas, sinRepes) {
	vector<string> in = {"hola","aloh","laoh","solo","uno", "onu","otro", "varios", "rioasv", "saovir", "irvaos"};
	vector<vector<string> > out = {{"hola","aloh","laoh"},{"solo"},{"uno", "onu"},{"otro"}, {"varios", "rioasv", "saovir", "irvaos"}};
	ASSERT_EQ(out, agruparAnagramas(in));
}

TEST(agruparAnagramas, conRepes) {
	vector<string> in = {"hola","aloh","laoh","solo","hola", "solo", "uno", "onu","otro", "varios", "rioasv", "saovir", "irvaos"};
	vector<vector<string> > out = {{"hola","aloh","laoh","hola"},{"solo", "solo"},{"uno", "onu"},{"otro"}, {"varios", "rioasv", "saovir", "irvaos"}};
	ASSERT_EQ(out, agruparAnagramas(in));
}

TEST(agruparAnagramas, enOrden) {
	vector<string> in = {"hola","rioasv", "laoh","solo","uno", "otro", "onu", "varios", "aloh", "saovir", "irvaos"};
	vector<vector<string> > out = {{"hola","laoh","aloh"}, {"rioasv","varios", "saovir", "irvaos"}, {"solo"}, {"uno", "onu"},{"otro"}};
	ASSERT_EQ(out, agruparAnagramas(in));
}

/////////////////////////// esPalindromo ///////////////////////////

TEST(esPalindromoTest, impar){
	ASSERT_TRUE(esPalindromo("menem"));
}

TEST(esPalindromoTest, par){
	ASSERT_TRUE(esPalindromo("roor"));
	ASSERT_FALSE(esPalindromo("pkjiejkp"));
}

TEST(esPalindromoTest, unaLetra){
	ASSERT_TRUE(esPalindromo("l"));
}

TEST(esPalindromoTest, dosLetras){
	ASSERT_TRUE(esPalindromo("ll"));
	ASSERT_FALSE(esPalindromo("lk"));
}


/////////////////////////// tieneRepetidos ///////////////////////////

TEST(tieneRepetidosTest, vacio) {
	ASSERT_FALSE(tieneRepetidos(""));
}

TEST(tieneRepetidosTest, unElemento) {
	ASSERT_FALSE(tieneRepetidos("e"));
}

TEST(tieneRepetidosTest, unRepe) {
	ASSERT_TRUE(tieneRepetidos("casa"));
}

TEST(tieneRepetidosTest, sinRepes) {
	ASSERT_FALSE(tieneRepetidos("mouse"));
}

/////////////////////////// rotar ///////////////////////////

TEST(rotarTest, sinRotar){
	ASSERT_EQ("igual", rotar("igual", 0));
}

TEST(rotarTest, rotarI){
	ASSERT_EQ("aligu", rotar("igual", 2));
}

TEST(rotarTest, rotarN){
	ASSERT_EQ("igual", rotar("igual", 5));
}

TEST(rotarTest, rotarMasDeN){
	ASSERT_EQ("ualig", rotar("igual", 8));
}

/////////////////////////// darVueltaK ///////////////////////////

TEST(darVueltaKTest, todoElString){
	ASSERT_EQ("aloh", darVueltaK("hola", 4));
}

TEST(darVueltaKTest, justo){
	ASSERT_EQ("libros", darVueltaK("ilrbso", 2));
}

TEST(darVueltaKTest, tePasaste){
	ASSERT_EQ("moctupodaar", darVueltaK("computadora", 3));
}

TEST(darVueltaKTest, noDarVuelta){
	ASSERT_EQ("computadora", darVueltaK("computadora", 1));
}
