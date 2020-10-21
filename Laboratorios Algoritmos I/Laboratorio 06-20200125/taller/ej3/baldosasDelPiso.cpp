int baldosasDelPiso(int M, int N, int B) {
    /*el problema original dice que los lados de las baldosas deben estar paralelos
     * al borde del suelo.*/

    int anchoOcupado = 0;
    int altoOcupado = 0;
    int nroHorizontales = 0;
    int nroVerticales = 0;

    while (anchoOcupado!=M) {
        if (anchoOcupado + B >= M) {
            anchoOcupado = M;
            nroHorizontales++;
        } else {
            anchoOcupado+=B;
            nroHorizontales++;
        }
    }
    while (altoOcupado!=N) {
        if (altoOcupado + B >= N) {
            altoOcupado = N;
            nroVerticales++;
        } else {
            altoOcupado+=B;
            nroVerticales++;
        }
    }
    return nroVerticales*nroHorizontales;
    // Borrar el return dummy y completar
}
