/* Escriba un algoritmo que, dada una matriz de 3x4 de enteros, encuentre el
mayor valor. */

#include <limits.h>
#include <stdio.h>

#include "../functions.h"

int main(void) {
    const size_t hor_size = 3, ver_size = 4;
    const int lim_inf = -100, lim_sup = 100;
    int mat[hor_size][ver_size], mayor_valor = INT_MIN, fila_mayor_valor,
                                 columna_mayor_valor;

    printf("Matriz de enteros cargada\n");
    printf("=========================\n");
    cargar_matriz_enteros_aleatorios(hor_size, ver_size, mat, lim_inf,
                                     lim_sup);
    mostrar_matriz_enteros(hor_size, ver_size, mat);

    // Bug: por algún motivo, usar "j" como variable para iterar sobre
    // las columnas genera un crasheo con el mensaje "segmentation fault".
    //
    // Un análisis con GDB muestra que, por alguna razón, "j" toma valores
    // irrisorios y ninguna de las cosas que probé para arreglarlo funcionó.
    // Por lo tanto, dejo "k" y "l" como las variables de iteración, con
    // las cuales el programa funciona sin problemas por algún motivo.
    for (size_t k = 0; k < hor_size; k++) {
        for (size_t l = 0; l < ver_size; l++) {
            if (mat[k][l] > mayor_valor) {
                mayor_valor = mat[k][l];
                fila_mayor_valor = k;
                columna_mayor_valor = l;
            }
        }
    }

    printf("El valor de mayor tamaño en la matriz es: %d\n", mayor_valor);
    printf("Fue encontrado en la fila %d y en la columna %d.\n",
           fila_mayor_valor, columna_mayor_valor);

    return 0;
}
