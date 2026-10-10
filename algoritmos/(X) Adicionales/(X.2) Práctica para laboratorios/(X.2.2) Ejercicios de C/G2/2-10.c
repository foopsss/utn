/* Escribir un algoritmo donde se cargue un arreglo de enteros de diez
posiciones con números aleatorios y se solicite un entero al usuario,
devolviendo todas las posiciones donde se encuentra el valor ingresado
en el arreglo. */

#include <stdio.h>

#include "../functions.h"

int main(void) {
    const size_t vec_size = 10;
    const int lim_inf = -100, lim_sup = 100;
    int vec[vec_size], num_us, cant_coincidencias = 0;

    printf("Introduzca un número a buscar en el arreglo: ");
    scanf("%d", &num_us);
    printf("\n");

    cargar_vector_enteros_aleatorios(vec, vec_size, lim_inf, lim_sup);
    printf("Valores del arreglo: \n");
    mostrar_vector_enteros(vec, vec_size);
    printf("\n");

    for (size_t i = 0; i < vec_size; i++) {
        if (vec[i] == num_us) {
            printf("Número encontrado en la posición %zu del arreglo.\n", i);
            cant_coincidencias += 1;
        }
    }

    if (cant_coincidencias == 0) {
        printf(
            "No se encontró el número introducido en el arreglo generado "
            "aleatoriamente.\n");
    }

    return 0;
}
