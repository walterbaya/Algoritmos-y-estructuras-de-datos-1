# include <iostream >
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

int fibonacciRecursivo(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
    }
}

//Ejercicio 5 iterativo con While
int fibonacciIterativo(int n) {
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
int fibonacciIterativoConFor(int n) {
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
int sumaImpares(int n){
    if(n == 1){
        return 0;
    }
    return (n % 2 != 0) ?  n + sumaImpares(n-1) : sumaImpares(n-1);
}


int main() {
    std::cout << "El resultado es: " << f(2, 3) << std::endl;
    std::cout << "Es primo?: " << esPrimo(17) << std::endl;
    std::cout << "Numero fibonacciRecursivo: " << fibonacciRecursivo(6) << std::endl;
    std::cout << "Numero fibonacciIterativo: " << fibonacciIterativo(6) << std::endl;
    std::cout << "Numero fibonacciIterativo con For: " << fibonacciIterativoConFor(6) << std::endl;
    std::cout<< "Suma impares Recursivo: " << sumaImpares(7)<< std::endl;
    return 0;
}
