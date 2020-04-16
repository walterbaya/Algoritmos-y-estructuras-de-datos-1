int llenarTaxis1(int g1, int g2, int g3) {
    //si tengo un grupo de tres ninguno de dos y una de 1 tendria segun esto que poner como minimo g3 + 1 y eso esta mal
    //porque cada grupo de uno lo podria convinar con uno de tres y ahorrarme un taxi por cada combinacion.
	int res = g3 + (g2 + 1) / 2 + (g1 + 3) / 4;
	return res;
}

int llenarTaxis2(int g1, int g2, int g3) {
	int res = g3; //inicialmente tengo un taxi por cada grupo de tres

	if (g1 <= g3) { //si hay menos grupos de uno que de tres no agrego taxis porque los meto juntos los de 3 con los de 1
		g1 = 0;
	} else {
		g1 = g1 - g3;
	}

	return res + (g2 + 1) / 2 + (g1 + 3) / 4;  //otra vez esta mal el hecho de que si  tengo un grupo de 2 y
	                                          // tengo 1 grupo de una persona sobrante lo podria combinar con ese de dos y me ahorraria
	                                          //un taxi en este caso estaria agregando un taxi por el de dos y uno por el de uno.

}

int llenarTaxis3(int g1, int g2, int g3) {
	int res = g3;

	if (g1 <= g3) {
		g1 = 0;
	} else {
		g1 = g1 - g3;
	}

	res = res + g2 / 2; //agrego por cada 2 grupos de 2 personas un auto mas el problema es si tengo un solo grupo de dos!
	// o un numero impar me esta faltando un auto y eso ocasiona todo el error.
	if (g2 % 2 == 0) {
		if (g1 >= 2) {
			g1 = g1 - 2;
		} else {
			g1 = 0;
		}
	}

	return res + (g1 + 3) / 4;
}
