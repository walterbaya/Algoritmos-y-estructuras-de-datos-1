#ifndef COMPETENCIA_MAYAS_H
#define COMPETENCIA_MAYAS_H

#include <string>
#include <iostream>
#include <fstream>
#include <tuple>

using namespace std;

/* Utiles */
tuple<string,string> leerEntrada(string filename);
int leerSalida(string filename);
/* Utiles */

/* RESOLUCION ALUMNOS */
int posiblesApariciones(string w, string s);
/* RESOLUCION ALUMNOS  */

#endif //COMPETENCIA_MAYAS_H
