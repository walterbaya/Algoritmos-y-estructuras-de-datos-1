# include <iostream>

using namespace std;
/*Ejercicio 2
 int f(int x, int y) {
    return x + y;
}
 * */

//Ejercicio 3
int f(int x, int y) {
    int res;
    if (x > y) {
        res = x + y;
    } else {
        res = x * y;
    }
    return res;
}

//Ejercicio 4
bool esPrimo(int n) {
    bool res = true;
    for (int i = 2; i < n && res; i++) {
        if (n % i == 0) {
            res = false;
        }
    }
    return res;
}
//Ejercicio 5 Recursivo

int fibonacciR(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacciR(n - 1) + fibonacciR(n - 2);
    }
}

//Ejercicio 5 iterativo con While
int fibonacciW(int n) {
    int nMenos2 = 0;
    int nMenos1 = 1;
    int res = 0;
    int i = 0;
    while (i < n - 1) {
        res = nMenos1 + nMenos2;
        nMenos2 = nMenos1;
        nMenos1 = res;
        i++;
    }
    return res;
}

//Ejercicio 5 iterativo con for
int fibonacciF(int n) {
    int nMenos2 = 0;
    int nMenos1 = 1;
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
        res = nMenos1 + nMenos2;
        nMenos2 = nMenos1;
        nMenos1 = res;
    }
    return res;
}

//Ejercicio 6 Recursivo
int sumaImparesR(int n) {
    if (n == 1) {
        return 0;
    }
    return (n % 2 != 0) ? n + sumaImparesR(n - 1) : sumaImparesR(n - 1);
}

//Ejercicio 6 iterativo con while
int sumaImparesW(int n) {
    int i = 0;
    int suma = 0;
    while (i < n) {
        if (i % 2 != 0) {
            suma = suma + i;
        }
    }
    return suma;
}

//Ejercicio 6 iterativo con for
int sumaImparesF(int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 != 0) {
            suma = suma + i;
        }
    }
    return suma;
}

//Ejercicio 7 recursivo
int divisoresHasta(int n, int k) {
    if (k == 1) {
        return 1;
    } else if (n % k == 0) {
        return k + divisoresHasta(n, k - 1);
    } else {
        return divisoresHasta(n, k - 1);
    }
}

//Ejercicio 7 iterativo con while
int sumaDivisoresW(int n) {
    int i = 0;
    int suma = 0;
    while (i < n) {
        if (n % i == 0) {
            suma = suma + i;
        }
    }
    return suma;
}


//Ejercicio 7 iterativo con for
int sumaDivisoresF(int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        if (n % i == 0) {
            suma = suma + i;
        }
    }
    return suma;
}

//Ejercicio 8 recursivo


//Ejercicio 8 iterativo con while


//Ejercicio 8 iterativo con for


int main() {
    cout << "El resultado es: " << f(2, 3) << endl;
    cout << "Es primo?: " << esPrimo(17) << endl;
    cout << "Numero fibonacciRecursivo: " << fibonacciR(6) << endl;
    cout << "Numero fibonacciIterativo: " << fibonacciW(6) << endl;
    cout << "Numero fibonacciIterativo con For: " << fibonacciF(6) << endl;
    cout << "Suma impares Recursivo: " << sumaImparesR(7) << endl;
    cout << "Suma impares Recursivo: " << sumaImparesW(7) << endl;
    cout << "Suma impares Recursivo: " << sumaImparesF(7) << endl;
    cout << "suma divisores Recursivo: " << sumaDivisoresR(9) << endl;
    //cout << "suma divisores Recursivo: " << sumaDivisoresW(9) << endl;
    //cout << "suma divisores Recursivo: " << sumaDivisoresF(9) << endl;
    return 0;
}
