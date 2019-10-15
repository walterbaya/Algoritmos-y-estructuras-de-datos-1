#include "definiciones.h"
#include "auxiliares.h"

//Auxiliares desde esEncuestaValida

bool vacia(vector<vector<dato> > t) {
    return t.size() == 0;
}


bool esMatriz(vector<vector<dato> > t) {
    bool res = true;
    for (int j = 0; j < t.size(); j++) {
        for (int i = 0; i < j; i++) {
            if (t[i].size() != t[j].size()) {
                res = false;
            }
        }
    }
    return res;
}

bool cantidadCorrectaDeColumnasI(eph_i ti) {
    bool res = true;
    for (int i = 0; i < ti.size(); i++) {
        if (ti[i].size() != cantidadItemsIndividuo) {
            res = false;
        }
    }
    return res;
}


bool cantidadCorrectaDeColumnasH(eph_i th) {
    bool res = true;
    for (int i = 0; i < th.size(); i++) {
        if (th[i].size() != cantidadItemsHogar) {
            res = false;
        }
    }
    return res;
}

bool hayHogarConCodigo(eph_h th, int c) {
    int i = 0;
    bool res = false;
    while (i < th.size() && !res) {
        res = th[i][HogCodusu] == c;
        i++;
    }
    return res;
}

bool hayIndividuoConCodigo(eph_i ti, int c) {
    int i = 0;
    bool res = false;
    while (i < ti.size() && !res) {
        res = ti[i][IndCodusu] == c;
        i++;
    }
    return res;
}

bool hayIndividuosSinHogares(eph_i ti, eph_h th) {
    int i = 0;
    bool res = false;
    while (i < ti.size() && !res) {
        res = !hayHogarConCodigo(th, ti[i][IndCodusu]);
        i++;
    }
    return res;

}

bool hayHogaresSinIndividuos(eph_i ti, eph_h th) {
    int i = 0;
    bool res = false;
    while (i < th.size() && !res) {
        res = !hayIndividuoConCodigo(ti, th[i][HogCodusu]);
        i++;
    }
    return res;
}


bool hayRepetidosI(eph_i ti) {
    bool res = false;
    int i = 0;
    while (i < ti.size() && !res) {
        int j = i + 1;
        while (j < ti.size() && !res) {
            res = ti[i][IndCodusu] == ti[j][IndCodusu] && ti[i][Componente] == ti[j][Componente];
            j++;
        }
        i++;
    }
    return res;
}

bool hayRepetidosH(eph_h th) {
    bool res = false;
    int i = 0;
    while (i < th.size() && !res) {
        int j = i + 1;
        while (j < th.size() && !res) {
            res = th[i][HogCodusu] == th[j][HogCodusu];
            j++;
        }
        i++;
    }
    return res;
}


bool esSuHogar(hogar h, individuo i) {
    return h[HogCodusu] == i[IndCodusu];
}

int cantHabitantes(hogar h, eph_i ti) {
    int res = 0;
    for (int i = 0; i < ti.size(); i++) {
        if (esSuHogar(h, ti[i])) {
            res = res + 1;
        }
    }
    return res;
}

bool mismoAnioYTrimestreI(eph_i ti) {
    bool res = true;
    int i = 0;
    while (i < ti.size() && res) {
        res = ti[0][IndAnio] == ti[i][IndAnio] && ti[0][IndTrim] == ti[i][IndTrim];
        i++;
    }
    return res;
}

bool mismoAnioYTrimestreH(eph_h th) {
    bool res = true;
    int i = 0;
    while (i < th.size() && res) {
        res = th[0][HogAnio] == th[i][HogAnio] && th[0][HogTrim] == th[i][HogTrim];
        i++;
    }
    return res;
}

bool mismoAnioYTrimestre(eph_i ti, eph_h th) {
    return mismoAnioYTrimestreH(th) && mismoAnioYTrimestreI(ti) && th[0][HogAnio] == ti[0][IndAnio] &&
           th[0][HogTrim] == ti[0][IndTrim];
}

bool menosDe21MiembrosPorHogar(eph_h th, eph_i ti) {
    bool res = true;
    int i = 0;
    while (i < th.size() && res) {
        res = cantHabitantes(th[i], ti) < 21;
        i++;
    }
    return res;
}

bool cantidadValidaDormitorios(eph_h th) {
    bool res = true;
    int i = 0;
    while (i < th.size() && res) {
        res = th[i][qHabitaciones] >= th[i][qDormitorios];
        i++;
    }
    return res;
}

bool individuoValido(individuo i) {
    return i[IndCodusu] > 0 && i[Componente] && i[IndTrim] > 0 && i[IndTrim] <= 4 &&
           i[Genero] > 0 && i[Genero] <= 2 && i[Edad] >= 0 && (i[Nivel_Ed] == 0 || i[Nivel_Ed] == 1) &&
           i[Estado] <= 1 && i[Estado] >= -1 && i[Cat_Ocup] <= 4 && i[Cat_Ocup] >= 0 &&
           (i[IngresoTot] >= 0 || i[IngresoTot] == -1) && i[LugarTrabajo] > 0 && i[LugarTrabajo] <= 10;
}

bool valoresEnRangoI(eph_i ti) {
    bool res = true;
    int i = 0;
    while (i < ti.size() && res) {
        res = individuoValido(ti[i]);
        i++;
    }
    return res;
}

bool hogarValido(hogar h) {
    return h[HogCodusu] > 0 && h[HogTrim] > 0 && h[HogTrim] <= 4 && h[Tenencia] > 0 &&
           h[Tenencia] <= 3 && h[Region] > 0 && h[Region] <= 6 && (h[Mas500k] == 0 || h[Mas500k] == 1) &&
           h[Tipo] > 0 && h[Tipo] <= 5 && h[qHabitaciones] > 0 && h[qDormitorios] >= 1 &&
           (h[trabajaHogar] == 1 || h[trabajaHogar] == 2);
}

bool valoresEnRangoH(eph_h th) {
    bool res = true;
    int i = 0;
    while (i < th.size() && res) {
        res = hogarValido(th[i]);
        i++;
    }
    return res;
}


//Auxiliares desde histograma habitacional

int maximaCantidadHabitaciones(eph_h th, int region) {
    int res = 0;
    for (int i = 0; i < th.size(); i++) {
        if (th[i][Region] == region && th[i][qHabitaciones] > res) {
            res = th[i][qHabitaciones];
        }

    }
    return res;
}

bool esCasa(hogar h) {
    return h[Tipo] == 1;
}

int cantHogaresCasaConNHabitaciones(eph_h th, int region, int habitaciones) {
    int res = 0;
    for (int i = 0; i < th.size(); i++) {
        if (esCasa(th[i]) && th[i][qHabitaciones] == habitaciones && th[i][Region] == region) {
            res = res + 1;
        }

    }
    return res;
}


//Auxiliares desde laCasaEstaQuedandoChica
bool hogarConHacinamientoCritico(hogar h, eph_i ti) {
    return cantHabitantes(h, ti) > 3 * h[qDormitorios];
}

bool esHogarValido(hogar h, int region) {
    return esCasa(h) && h[Region] == region && h[Mas500k] == 0;
}

float cantHogaresValidos(eph_h th, int region) {
    int res = 0;
    for (int i = 0; i < th.size(); ++i) {
        if (esHogarValido(th[i], region)) {
            res = res + 1;
        }

    }
    return res;
}

float cantHogaresValidosConHC(eph_h th, eph_i ti, int region) {
    int res = 0;
    for (int i = 0; i < th.size(); ++i) {
        if (esHogarValido(th[i], region) && hogarConHacinamientoCritico(th[i], ti)) {
            res = res + 1;
        }
    }
    return res;
}

float proporcionDeCasasConHC(eph_h th, eph_i ti, int region) {
    float res = 0;
    if (cantHogaresValidos(th, region) > 0) {
        res = cantHogaresValidosConHC(th, ti, region) / cantHogaresValidos(th, region);
    }
    return res;
}

//Auxiliares desde creceElTeleworkingEnCiudadesGrandes


bool realizarSusTareasEnEsteHogar(individuo i) {
    return i[LugarTrabajo] == 6;
}

bool esCasaODepartamento(hogar h) {
    return h[Tipo] == 1 || h[Tipo] == 2;
}

bool suHogarEsCasaODepartamento(individuo i, eph_h th) {
    int j = 0;
    bool res = false;
    while (j < th.size() && !res) {
        res = esSuHogar(th[j], i) && esCasaODepartamento(th[j]);
        j++;
    }
    return res;
}


bool esDeCiudadGrande(individuo i, eph_h th) {
    int j = 0;
    bool res = false;
    while (j < th.size() && !res) {
        res = esSuHogar(th[j], i) && th[j][Mas500k] == 1;
        j++;
    }
    return res;
}

bool trabaja(individuo i) {
    return i[Estado] == 1;
}

bool individuoEnHogarValido(individuo i, eph_h th) {
    return esDeCiudadGrande(i, th) && suHogarEsCasaODepartamento(i, th);
}

bool trabajaEnSuVivienda(individuo i, eph_h th) {
    return realizarSusTareasEnEsteHogar(i) && suHogarEsCasaODepartamento(i, th);
}

float cantIndividuosQueTrabajan(eph_h th, eph_i ti) {
    int res = 0;
    for (int k = 0; k < ti.size(); k++) {
        if (trabaja(ti[k]) && individuoEnHogarValido(ti[k], th)) {
            res++;
        }
    }
    return res;
}

float cantIndividuosTrabajandoEnSuVivienda(eph_h th, eph_i ti) {
    int res = 0;
    for (int k = 0; k < ti.size(); k++) {
        if (trabaja(ti[k]) && trabajaEnSuVivienda(ti[k], th) && individuoEnHogarValido(ti[k], th)) {
            res++;
        }
    }
    return res;
}

float proporcionTeleworking(eph_h th, eph_i ti) {
    float res = 0;
    if (cantIndividuosQueTrabajan(th, ti) > 0) {
        res = cantIndividuosTrabajandoEnSuVivienda(th, ti) / cantIndividuosQueTrabajan(th, ti);
    }
    return res;
}

//Auxiliares desde ordenarRegionYCODUSU

bool hogarEstaAntesSegunRegion(hogar h1, hogar h2) {
    return h1[Region] < h2[Region];
}

bool hogarEstaAntesSegunCodusu(hogar h1, hogar h2) {
    return h1[Region] == h2[Region] && h1[HogCodusu] < h2[HogCodusu];
}

bool individuoEstaAntesSegunComponente(individuo i1, individuo i2) {
    return i1[IndCodusu] == i2[IndCodusu] && i1[Componente] < i2[Componente];
}

void ordenarThPorRegion(eph_h &th) {
    for (int i = 0; i < th.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (hogarEstaAntesSegunRegion(th[i], th[j])) {
                hogar temp = th[j];
                th[j] = th[i];
                th[i] = temp;
            }
        }
    }

}

void ordenarThPorCodusu(eph_h &th) {
    for (int i = 0; i < th.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (hogarEstaAntesSegunCodusu(th[i], th[j])) {
                hogar temp = th[j];
                th[j] = th[i];
                th[i] = temp;
            }
        }
    }

}

void ordenarTiSegunComponente(eph_i &ti) {
    for (int i = 0; i < ti.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (individuoEstaAntesSegunComponente(ti[i], ti[j])) {
                individuo temp = ti[j];
                ti[j] = ti[i];
                ti[i] = temp;
            }
        }
    }

}

void ordenarTiSegunCodusuEnTh(eph_h th, eph_i &ti) {
    int posicionSwap = 0;
    for (int i = 0; i < th.size(); i++) {
        for (int j = posicionSwap; j < ti.size(); j++) {
            if (ti[j][IndCodusu] == th[i][HogCodusu]) {
                individuo temp = ti[posicionSwap];
                ti[posicionSwap] = ti[j];
                ti[j] = temp;
                posicionSwap++;
            }

        }

    }
}


void ordenarThPorRegionYCodusu(eph_h &th) {
    ordenarThPorRegion(th);
    ordenarThPorCodusu(th);
}


void ordenarTiPorCodusuDeHogarYComponente(eph_i &ti, eph_h th) {
    ordenarTiSegunCodusuEnTh(th, ti);
    ordenarTiSegunComponente(ti);
}








//Auxiliares desde muestraHomogenea


float ingresos(hogar h, eph_i ti) {
    float sumaIngresos = 0;
    for (int i = 0; i < ti.size(); i++) {
        if (ti[i][IndCodusu] == h[HogCodusu] && ti[i][IngresoTot] > -1) {
            sumaIngresos = sumaIngresos + ti[i][IngresoTot];
        }
    }
    return sumaIngresos;
}

//Se supone e y k dos enteros mayores iguales a 0
bool esElDeMenorIngresosDesdeE(eph_h th, eph_i ti, int e, int k) {
    bool res = true;
    for (int i = e; i < th.size() && res; i++) {
        if (ingresos(th[k], ti) > ingresos(th[i], ti)) {
            res = false;
        }
    }
    return res;
}


void ordenarPorIngresos(eph_h &th, eph_i ti) {
    int i = 0;
    int principio = 0;
    hogar temp;
    while (i < th.size()) {
        if (esElDeMenorIngresosDesdeE(th, ti, principio, i)) {
            temp = th[principio];
            th[principio] = th[i];
            th[i] = temp;
            principio++;
            i = principio;
        } else {
            i++;
        }
    }
}


vector<vector<int> > secuenciasDePosicionesDeTamanio2ConIgualDiferenciaDeIngreso(eph_h th, eph_i ti) {
    vector<vector<int> > secuenciaPar;
    for (int i = 0; i < th.size(); i++) {
        for (int j = i + 1; j < th.size(); j++) {
            if (ingresos(th[j], ti) - ingresos(th[i], ti) > 0) {
                secuenciaPar.push_back({i, j});
            }
        }
    }
    return secuenciaPar;
}


bool igualDiferenciaDeIngresos(vector<int> v1, vector<int> v2, eph_h th, eph_i ti) {
    return ingresos(th[v1[v1.size() - 1]], ti) - ingresos(th[v1[v1.size() - 2]], ti) ==
           ingresos(th[v2[v2.size() - 1]], ti) - ingresos(th[v2[v2.size() - 2]], ti);
}


bool sePuedenCombinar(vector<int> v1, vector<int> v2, eph_h th, eph_i ti) {
    return v1[v1.size() - 1] == v2[0] && igualDiferenciaDeIngresos(v1, v2, th, ti);
}

void combinarListas(vector<int> &v1, vector<int> v2) {
    v1.push_back(v2[1]);
}

//se supone la lista no vacia.
vector<int> creaPosicionHomogeneaMasGrandeIniciadaEnK(vector<vector<int> > lista, int k, eph_h th, eph_i ti) {
    vector<int> homogeneaParcial = lista[k];
    for (int i = k; i < lista.size() - 1; i++) {
        if (sePuedenCombinar(homogeneaParcial, lista[i + 1], th, ti)) {
            combinarListas(homogeneaParcial, lista[i + 1]);
        }
    }
    return homogeneaParcial;
}

//Se supone la lista no vacia.
vector<vector<int> > listaPosicionesDeHomogeneas(vector<vector<int> > lista, eph_h th, eph_i ti) {
    vector<vector<int> > listaPosiciones;
    for (int i = 0; i < lista.size() - 2; i++) {
        listaPosiciones.push_back(creaPosicionHomogeneaMasGrandeIniciadaEnK(lista, i, th, ti));
    }
    return listaPosiciones;
}

//se supone la lista no vacia.
vector<int> listaMasGrande(vector<vector<int> > lista) {
    vector<int> masGrande = lista[0];
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].size() > masGrande.size()) {
            masGrande = lista[i];
        }
    }
    return masGrande;
}

//se supone la listaOrdenada no vacia
vector<hogar> homogeneaMasGrandeEncontrada(vector<hogar> listaOrdenada, vector<int> listaMasGrande) {
    vector<hogar> homogenea;
    for (int i = 0; i < listaMasGrande.size(); i++) {
        homogenea.push_back(listaOrdenada[listaMasGrande[i]]);
    }
    return homogenea;
}




//Auxiliares desde corregirRegion

void modificarAPampeana(hogar &h) {
    h[Region] = 5;
}

bool estaEnRegionBsAs(hogar h) {
    return h[Region] == 1;
}

//Auxiliares ejercicio Yapa


float ingresosPerCapitaHogar(hogar h, eph_i ti) {
    return ingresos(h, ti) / cantHabitantes(h, ti);
}

float ingresosHasta(int n, eph_h th, eph_i ti) {
    float ingresosAcum = 0;
    for (int i = 0; i <= n; i++) {
        ingresosAcum = ingresosAcum + ingresosPerCapitaHogar(th[i], ti);
    }
}

float integralDeIngresosObservados(eph_h th, eph_i ti) {
    float integral = 0;
    for (int i = 0; i < th.size(); i++) {
        integral = integral + ingresosHasta(i - 1, th, ti) / ingresosHasta(th.size() - 1, th, ti) +
                   ingresosPerCapitaHogar(th[i], ti) / (ingresosHasta(th.size() - 1, th, ti) * 2);
    }

    return integral / th.size();
}

float areaObservada(eph_h th, eph_i ti) {
    float areaIgualdadTotal = 0.5;
    return areaIgualdadTotal - integralDeIngresosObservados(th, ti);
}

