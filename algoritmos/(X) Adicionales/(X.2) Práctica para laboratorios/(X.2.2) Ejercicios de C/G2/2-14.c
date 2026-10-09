/* Escribir un algoritmo que ponga números aleatorios en una matriz de 5x5 y
luego muestre la misma por pantalla. */

#include "../functions.h"

int main(void) {
    const size_t hor_size = 5, ver_size = 5;
    const int lim_inf = -100, lim_sup = 100;
    int mat[hor_size][ver_size];

    cargar_matriz_enteros_aleatorios(hor_size, ver_size, mat, lim_inf,
                                     lim_sup);
    mostrar_matriz_enteros(hor_size, ver_size, mat);

    return 0;
}
