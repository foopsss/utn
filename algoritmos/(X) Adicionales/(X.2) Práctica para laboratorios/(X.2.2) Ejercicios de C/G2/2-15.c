/* Escribir un algoritmo que, dada una matriz de 5x10, sume los elementos de
todas las filas y los guarde en un arreglo de 5 posiciones. */

#include <stdio.h>

#include "../functions.h"

int main(void) {
    const size_t hor_size_mat = 5, ver_size_mat = 10;
    const int lim_inf = -100, lim_sup = 100;
    int mat[hor_size_mat][ver_size_mat], vec_suma_col[hor_size_mat];

    printf("Matriz de enteros cargada\n");
    printf("=========================\n");
    cargar_matriz_enteros_aleatorios(hor_size_mat, ver_size_mat, mat, lim_inf,
                                     lim_sup);
    mostrar_matriz_enteros(hor_size_mat, ver_size_mat, mat);

    printf("Vector de suma de filas\n");
    printf("=======================\n");
    for (size_t i = 0; i < hor_size_mat; i++) {
        vec_suma_col[i] = 0;

        for (size_t j = 0; j < ver_size_mat; j++) {
            vec_suma_col[i] += mat[i][j];
        }

        printf("Suma de valores de la fila %zu: %d\n", i, vec_suma_col[i]);
    }

    return 0;
}
