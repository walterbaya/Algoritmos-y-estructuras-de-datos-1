#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

bool esMatriz(vector<vector<dato> > t);

bool vacia(vector<vector<dato> > t);

bool cantidadCorrectaDeColumnasI(eph_i ti);

bool cantidadCorrectaDeColumnasH(eph_h th);

bool hayIndividuosSinHogares(eph_i ti, eph_h th);

bool hayHogaresSinIndividuos(eph_i ti, eph_h th);

bool hayRepetidosI(eph_i ti);

bool hayRepetidosH(eph_h th);

bool mismoAnioYTrimestre(eph_i ti, eph_h th);

bool menosDe21MiembrosPorHogar(eph_h th, eph_i ti);

bool cantidadValidaDormitorios(eph_h th);

bool valoresEnRangoI(eph_i ti);

bool valoresEnRangoH(eph_h th);

int maximaCantidadHabitaciones(eph_h th, int region);

int cantHogaresCasaConNHabitaciones(eph_h th, int region, int habitaciones);

float proporcionDeCasasConHC(eph_h th, eph_i ti, int region);

float proporcionTeleworking(eph_h th, eph_i ti);

void ordenarThPorRegionYCodusu(eph_h &th);

void ordenarTiPorCodusuDeHogarYComponente(eph_i &ti, eph_h th);

float areaObservada(eph_h th, eph_i ti);

void ordenarPorIngresos(eph_h &th, eph_i ti);

vector<int> listaMasGrande(vector<vector<int> > lista);

vector<vector<int> > secuenciasDePosicionesDeTamanio2ConIgualDiferenciaDeIngreso(eph_h th, eph_i ti);

vector<vector<int> > listaPosicionesDeHomogeneas(vector<vector<int> > lista, eph_h th, eph_i ti);

vector<hogar> homogeneaMasGrandeEncontrada(vector<hogar> listaOrdenada, vector<int> listaMasGrande);

void modificarAPampeana(hogar &h);

bool estaEnRegionBsAs(hogar h);

#endif
