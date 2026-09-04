/* Escribir un algoritmo que, dado un arreglo ordenado de menor a mayor de
cien enteros, realice una búsqueda binaria para encontrar un valor ingresado
por el usuario. */

#include <stdio.h>

#include "../functions.h"

void busqueda_binaria(int* arr, size_t arr_size, int val_us) {
    // No olvidarse de que las posiciones de arreglos empiezan
    // con 0 acá, por eso la resta en la asignación inicial de
    // "der".
    int izq = 0, der = (arr_size - 1), centro = (izq + der) / 2;

    while (izq < der && arr[centro] != val_us) {
        if (arr[centro] > val_us) {
            der = centro - 1;
        } else {
            izq = centro + 1;
        }
        centro = (izq + der) / 2;
    }

    if (arr[centro] == val_us) {
        printf("Se encontró el elemento buscado en la posición %d.\n", centro);
    } else {
        printf("No se pudo encontrar el elemento buscado.\n");
    }
}

int main(void) {
    const size_t arr_size = 100;
    const int low_lim = -100, upp_lim = 100;
    int arr[arr_size], val_us;

    printf("Arreglo original: \n");
    cargar_arreglo_enteros(arr, arr_size, low_lim, upp_lim);
    mostrar_arreglo_enteros(arr, arr_size);
    printf("\n");

    printf("Arreglo ordenado: \n");
    ordenar_arreglo_enteros(arr, arr_size);
    mostrar_arreglo_enteros(arr, arr_size);
    printf("\n");

    printf("Introduzca el valor que se desea encontrar: ");
    scanf("%d", &val_us);
    busqueda_binaria(arr, arr_size, val_us);

    return 0;
}
