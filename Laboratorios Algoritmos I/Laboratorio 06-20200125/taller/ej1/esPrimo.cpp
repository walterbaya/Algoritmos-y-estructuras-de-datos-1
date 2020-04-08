#include "esPrimo.h"

bool esPrimo(int n) {
	if (n < 2) {
		return false;
	} else {
		for (int i = 2; i < n; i++) {
			if (n % i == 0) {
				return false;
			}
		}
		return true;
	}
}
//Esta implementacion es correcta.
//Se podria demostrar utilizando WP que es la forma que usamos en este curso para demostrar la correctitud
//El hecho de que corra todos los test no significa que el programa es correcto.