#ifndef ROBOTS_UTILES_H
#define ROBOTS_UTILES_H

#include <vector>
#include <string>

using namespace std;

vector<int> leerEntrada(string filename, int & s);
long leerRta(string filename);
long caminoMasCorto(std::vector<int> p, int s);

#endif //CLION_UTILES_H
