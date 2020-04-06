#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "anagramas.h"

using namespace std;

int main() {
    string palabra, palabra2;
    cout << "Ingrese una palabra en ingles con letras en minuscula:" << endl;
    cin >> palabra;

    ifstream dicci("ingles.dic");
    vector<string> listaPalabras;
    string word;
    while (getline(dicci, word)) {
        listaPalabras.push_back(word);
    }
    int cantidadAnagrama = 0;
    for (int i = 0; i < listaPalabras.size(); ++i) {
        if (esAnagrama(listaPalabras[i], palabra)) {
            cout << "Son anagramas: " << listaPalabras[i] << " y " << palabra << endl;
            cantidadAnagrama++;
        }
    }
    cout << "La cantidad de anagramas es: " << cantidadAnagrama << endl;
    return 0;
}

bool esAnagrama(string p1, string p2) {
    return esAnagrama1(p1, p2);
}

bool esAnagrama1(string p1, string p2) {
    ordenarString(p1);
    ordenarString(p2);
    return p1 == p2;
}

bool esAnagrama2(string p1, string p2) {
    int productoPrimero = 1;
    int productoSegundo = 1;
    for (int i = 0; i < p1.size(); i++) {
        productoPrimero = charToPrimo(p1[i]) * productoPrimero;
    }
    for (int j = 0; j < p2.size(); j++) {
        productoSegundo = charToPrimo(p2[j]) * productoSegundo;
    }
    return productoPrimero == productoSegundo;
}

int posMinimo(int i, string palabra) {
    char minimo = palabra[i];
    int posMinimo = i;
    for (int k = i; k < palabra.size(); k++) {
        if (posicionEnAlfabeto(minimo) > posicionEnAlfabeto(palabra[k])) {
            minimo = palabra[k];
            posMinimo = k;
        }
    }
    return posMinimo;
}

void ordenarString(string &palabra) {
    for (int i = 0; i < palabra.size(); i++) {
        int pos = posMinimo(i, palabra);
        char temp = palabra[i];
        palabra[i] = palabra[pos];
        palabra[pos] = temp;
    }
}

int esPrimo(int n) {
    bool res = true;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            res = false;
        }
    }
    return res;
}

int posicionPrimo(int p) {
    int contadorPrimos = 0;
    int primo = 2;
    int i = 2;
    while (contadorPrimos < p) {
        if (esPrimo(i)) {
            contadorPrimos++;
            primo = i;
        }
        i++;
    }
    return primo;
}

int charToPrimo(char c) {
    int pos = posicionEnAlfabeto(c);
    int primo = posicionPrimo(pos);
    return primo;
}

int posicionEnAlfabeto(char c) {
    int i = c;
    return i - 96;
}
/*La funcion que usa el ordenamiento parece ser mas rapida aunque ordenar es de tipo O(n^2) luego el algoritmos tiene
 * complejidad de peor caso O(n^2) y luego tengo que la segunda tiene complejidad  O(1) tiene generar un primo ya que a lo sumo hay 24 letras y  se puede suponer constante eso
 * es O(1) porque solo hay 24 eso hay que hacerlo con cada palabra luego recorrer y hacer el producto costaria O(n) luego tiene sentido usar
 * la implementacion que hace el producto de primos.*/
// deal tiene 6 anagramas
//pyrotic tiene 2 anagramas
//else tiene 4 anagramas
//en la practica parece razonable en el caso de numeros pequeños usar la forma 1 ya que generar un primo puede tardar mas que n en algunos casos si n
//es mas chico que 24.