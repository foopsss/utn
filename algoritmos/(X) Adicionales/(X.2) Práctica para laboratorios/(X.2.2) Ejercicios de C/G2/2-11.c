/* Escribir un algoritmo que cargue un arreglo de 100 elementos aleatoriamente,
lo ordene de menor a mayor y muestre por pantalla el arreglo ordenado. */

#include <stdio.h>

#include "../functions.h"

int main(void) {
    const size_t vec_size = 100;
    const int lim_inf = -100, lim_sup = 100;
    int vec[vec_size];

    cargar_vector_enteros_aleatorios(vec, vec_size, lim_inf, lim_sup);
    printf("Valores del arreglo: \n");
    mostrar_vector_enteros(vec, vec_size);
    printf("\n");

    ordenar_vector_enteros(vec, vec_size);
    printf("Valores del arreglo ordenado: \n");
    mostrar_vector_enteros(vec, vec_size);
    printf("\n");

    return 0;
}
