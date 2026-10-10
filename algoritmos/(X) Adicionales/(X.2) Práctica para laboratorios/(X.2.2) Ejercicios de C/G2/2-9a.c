/* Crear una función que, dado un arreglo de enteros de 10 posiciones, escriba
por pantalla cual es el mayor número, cual es el menor y cual es el promedio.
*/

#include <limits.h>
#include <stdio.h>

#include "../functions.h"

int main(void) {
    const size_t vec_size = 10;
    const int lim_inf = 0, lim_sup = 100;
    int vec[vec_size], may_num = INT_MIN, men_num = INT_MAX;
    double prom = 0;

    cargar_vector_enteros_aleatorios(vec, vec_size, lim_inf, lim_sup);
    printf("Valores del arreglo: \n");
    mostrar_vector_enteros(vec, vec_size);
    printf("\n");

    for (size_t i = 0; i < vec_size; i++) {
        prom += vec[i];

        if (vec[i] > may_num) {
            may_num = vec[i];
        }

        if (vec[i] < men_num) {
            men_num = vec[i];
        }
    }

    prom = prom / 10.0;
    printf("El número más grande en el arreglo es: %d\n", may_num);
    printf("El número más pequeño en el arreglo es: %d\n", men_num);
    printf("El promedio de los números en el arreglo es: %.2f\n", prom);

    return 0;
}
