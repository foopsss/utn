/* Crear una función que, dado un arreglo de enteros de 10 posiciones, escriba
por pantalla cual es el mayor número, cual es el menor y cual es el promedio.

Obtener además las posiciones donde se encuentran las primeras ocurrencias del
mayor y menor elemento del arreglo. */

#include <limits.h>
#include <stdio.h>

#include "../functions.h"

int main(void) {
    const size_t vec_size = 10;
    const int lim_inf = 0, lim_sup = 100;
    int vec[vec_size], may_num = INT_MIN, men_num = INT_MAX;
    int prim_pos_may = 0, prim_pos_men = 0;
    double prom = 0;

    cargar_vector_enteros_aleatorios(vec, vec_size, lim_inf, lim_sup);
    printf("Valores del arreglo: \n");
    mostrar_vector_enteros(vec, vec_size);
    printf("\n");

    for (size_t i = 0; i < vec_size; i++) {
        prom += vec[i];

        if (vec[i] > may_num) {
            may_num = vec[i];
            prim_pos_may = i;
        }

        if (vec[i] < men_num) {
            men_num = vec[i];
            prim_pos_men = i;
        }
    }

    prom = prom / 10.0;
    printf("El número más grande en el arreglo es: %d\n", may_num);
    printf("El número más pequeño en el arreglo es: %d\n", men_num);
    printf("El promedio de los números en el arreglo es: %.2f\n", prom);
    printf("\n");
    printf(
        "El número más grande del arreglo se encuentra por primera vez en la "
        "posición %d.\n",
        prim_pos_may);
    printf(
        "El número más pequeño del arreglo se encuentra por primera vez en la "
        "posición %d.\n",
        prim_pos_men);

    return 0;
}
