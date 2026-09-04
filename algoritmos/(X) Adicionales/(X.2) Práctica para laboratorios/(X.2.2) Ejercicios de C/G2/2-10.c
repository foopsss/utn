/* Escribir un algoritmo donde se cargue un arreglo de enteros de diez
posiciones con números aleatorios y se solicite un entero al usuario,
devolviendo todas las posiciones donde se encuentra el valor ingresado
en el arreglo. */

#include <stdio.h>

#include "../functions.h"

int main(void) {
    const size_t arr_size = 10;
    const int low_lim = -100, upp_lim = 100;
    int arr[arr_size], num_us, cant_coincidencias = 0;

    printf("Introduzca un número a buscar en el arreglo: ");
    scanf("%d", &num_us);
    printf("\n");

    cargar_arreglo_enteros(arr, arr_size, low_lim, upp_lim);
    printf("Valores del arreglo: \n");
    mostrar_arreglo_enteros(arr, arr_size);
    printf("\n");

    for (size_t i = 0; i < arr_size; i++) {
        if (arr[i] == num_us) {
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
