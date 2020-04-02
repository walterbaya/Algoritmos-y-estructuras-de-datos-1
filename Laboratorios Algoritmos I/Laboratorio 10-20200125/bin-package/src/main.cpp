#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void ordenar(vector<int> &items) {
    //implementacion usando insertion sort
    clock_t begin = clock();
    for (int i = 1; i < items.size(); i++) {
        int inicial = i;
        for (int j = i; j >= 0; j--) {
            if (items[i] < items[j]) {
                int temp = items[j];
                items[j] = items[i];
                items[i] = temp;
                i = j;
            }
        }
        i = inicial;
    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / (CLOCKS_PER_SEC / 1000);
    cout << "El tiempo que conlleva ordenar: " << elapsed_secs << endl;
}

int bestFit(int W, vector<int> &items) {
    multiset<int> restos;
    for (int i = 0; i < (int) items.size(); ++i) {
        restos.insert(W);
    }
    int res = 0;
    for (int i = 0; i < (int) items.size(); ++i) {
        multiset<int>::iterator it = restos.lower_bound(items[i]);
        int restoAct = *it;
        if (restoAct == W) {
            res++;
        }
        restoAct -= items[i];
        restos.erase(it);
        restos.insert(restoAct);
    }
    return res;
}

void realizarPackaging(string archivo) {
    int N, W, aux;
    ifstream bpp(archivo);
    bpp >> N >> W;
    vector<int> items;
    for (int i = 0; i < N; ++i) {
        bpp >> aux;
        items.push_back(aux);
    }
    bpp.close();
    cout << "La cantidad de items son: " << items.size() << endl;
    //Se levantan los items y la capacidad del contenedor
    cout << "Se levantan los items y la capacidad del contenedor" << endl;
    //Se corre best-fit
    int cant1 = bestFit(W, items);
    cout << "Con la idea bestFit, se consigue una asignacion con " << cant1 << " contenedores" << endl;
    //Se ordenan los items
    ordenar(items);
    //Se corre best-fit-decreasing
    int cant2 = bestFit(W, items);
    cout << "Con la idea bestFitDecreasing, se consigue una asignacion con " << cant2 << " contenedores" << endl;
}

int main() {
    /*
     *Ordenar 1000 conlleva 21.523
     *Ordenar 10000 conlleva 2040.18
     *Ordenar 100000 conlleva 201666
     * Ordenar 1000000 conlleva
     *
     * cantTiempo = 2*10^(2*(cantDigitos-3)+1)
     *10
     * 2*10*10*10
     * 2*10*10*10*10*10
     * 2*10*10*10*10*10*10*10
     * 2*.....................................
     * 2*..........................................
     * 2*.....................................................
     * pero cantDigitos = log n
     * luego
     * cantTiempo = 2*10^(2*log(n)-5)
     * cantTiempo = 2*n^2/c   donde c es una constante
     * luego la cantTiempo tiene una complejidad de tipo O(n^2)
     * */
    realizarPackaging("BPP4.in");
    return 0;
}
