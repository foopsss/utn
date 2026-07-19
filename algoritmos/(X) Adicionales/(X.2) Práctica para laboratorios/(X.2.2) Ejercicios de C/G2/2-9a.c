/* Crear una función que, dado un arreglo de enteros de 10 posiciones, escriba
por pantalla cual es el mayor número, cual es el menor y cual es el promedio.
*/

#include <limits.h>
#include <stdio.h>

#include "../functions.h"

int main(void) {
    const size_t arr_size = 10;
    const int low_lim = 0, upp_lim = 100;
    int arr[arr_size], may_num = INT_MIN, men_num = INT_MAX;
    double prom = 0;

    cargar_arreglo_enteros(arr, arr_size, low_lim, upp_lim);
    printf("Valores del arreglo: \n");
    mostrar_arreglo_enteros(arr, arr_size);
    printf("\n");

    for (size_t i = 0; i < arr_size; i++) {
        prom += arr[i];

        if (arr[i] > may_num) {
            may_num = arr[i];
        }

        if (arr[i] < men_num) {
            men_num = arr[i];
        }
    }

    prom = prom / 10.0;
    printf("El número más grande en el arreglo es: %d\n", may_num);
    printf("El número más pequeño en el arreglo es: %d\n", men_num);
    printf("El promedio de los números en el arreglo es: %.2f\n", prom);

    return 0;
}
