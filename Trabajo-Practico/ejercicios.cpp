#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"


bool esEncuestaValida(eph_h th, eph_i ti) {
    bool res = false;
    if (!vacia(ti) && !vacia(th) && esMatriz(ti) && esMatriz(th) && cantidadCorrectaDeColumnasI(ti) &&
        cantidadCorrectaDeColumnasH(th) && !hayIndividuosSinHogares(ti, th) && !hayHogaresSinIndividuos(ti, th) &&
        !hayRepetidosI(ti) && !hayRepetidosH(th) && mismoAnioYTrimestre(ti, th) && menosDe21MiembrosPorHogar(th, ti) &&
        cantidadValidaDormitorios(th) && valoresEnRangoI(ti) && valoresEnRangoH(th)) {
        res = true;
    }
    return res;
}


//Se supone que la encuesta conformada por th y ti es valida y que el rango de region es correcto.
vector<int> histHabitacional(eph_h th, eph_i ti, int region) {
    vector<int> res(maximaCantidadHabitaciones(th, region));
    for (int i = 0; i < res.size(); i++) {
        res[i] = cantHogaresCasaConNHabitaciones(th, region, i + 1);
    }
    return res;
}

//Se supone que la encuesta ingresada es válida.
vector<float> laCasaEstaQuedandoChica(eph_h th, eph_i ti) {
    vector<float> res(6);
    for (int i = 0; i < res.size(); i++) {
        res[i] = proporcionDeCasasConHC(th, ti, i + 1);
    }
    return res;
}


//se supone que la encuesta ingresada es valida y que el año de t1i es menor al de t2i y los trimestres son iguales
bool creceElTeleworkingEnCiudadesGrandes(eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i) {
    bool res = false;
    if (proporcionTeleworking(t2h, t2i) > proporcionTeleworking(t1h, t1i)) {
        res = true;
    }
    return res;
}


//Se supone que la encuesta es valida
void ordenarRegionYCodusu(eph_h &th, eph_i &ti) {
    ordenarThPorRegionYCodusu(th);
    ordenarTiPorCodusuDeHogarYComponente(ti, th);
}


//Se supone que la encuesta es valida
vector<hogar> muestraHomogenea(eph_h th, eph_i ti) {
    vector<hogar> muestraHomogeneaObtenida;
    ordenarPorIngresos(th, ti);
    vector<vector<int> > secuenciasTamanio2 = secuenciasDePosicionesDeTamanio2ConIgualDiferenciaDeIngreso(th, ti);

    if (secuenciasTamanio2.size() != 0) {

        vector<vector<int> > vectorHomogeneas = listaPosicionesDeHomogeneas(secuenciasTamanio2, th, ti);
        vector<int> posicionHomogeneaMasGrande = listaMasGrande(vectorHomogeneas);
        vector<hogar> muestraHomogeneaMasGrande = homogeneaMasGrandeEncontrada(th, posicionHomogeneaMasGrande);

        if (muestraHomogeneaMasGrande.size() >= 3) {
            muestraHomogeneaObtenida = muestraHomogeneaMasGrande;
        }
    }
    return muestraHomogeneaObtenida;
}

//Se supone que la encuesta es valida
void corregirRegion(eph_h &th, eph_i ti) {
    for (int i = 0; i < th.size(); i++) {
        if (estaEnRegionBsAs(th[i])) {
            modificarAPampeana(th[i]);
        }
    }
}


//suponemos que la encuesta es validad y la tabla de hogares fue ordenada por ingresos de menor a mayor
float indiceGini(eph_h th, eph_i ti) {
    float areaIgualdadTotal = 0.5;
    float indice;
    indice = areaObservada(th, ti) / areaIgualdadTotal;
    return indice;
}




