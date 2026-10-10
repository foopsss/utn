/* Escribir un algoritmo que, dada una matriz de 5x10, sume los elementos de
todas las filas y los guarde en un arreglo de 5 posiciones. */

#include <stdio.h>

#include "../functions.h"

int main(void) {
    const size_t hor_size = 5, ver_size = 10;
    const int lim_inf = -100, lim_sup = 100;
    int mat[hor_size][ver_size], vec_suma_col[hor_size];

    printf("Matriz de enteros cargada\n");
    printf("=========================\n");
    cargar_matriz_enteros_aleatorios(hor_size, ver_size, mat, lim_inf,
                                     lim_sup);
    mostrar_matriz_enteros(hor_size, ver_size, mat);

    printf("Vector de suma de filas\n");
    printf("=======================\n");
    for (size_t i = 0; i < hor_size; i++) {
        vec_suma_col[i] = 0;

        for (size_t j = 0; j < ver_size; j++) {
            vec_suma_col[i] += mat[i][j];
        }

        printf("Suma de valores de la fila %zu: %d\n", i, vec_suma_col[i]);
    }

    return 0;
}
