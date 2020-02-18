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


int main() {
    std::cout << "El resultado es: " << f(2, 3) << std::endl;
    std::cout << "Es primo?: "<< esPrimo(17);

    return 0;
}
