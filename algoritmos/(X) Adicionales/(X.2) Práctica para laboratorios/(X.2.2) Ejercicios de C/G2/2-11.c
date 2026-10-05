/* Escribir un algoritmo que cargue un arreglo de 100 elementos aleatoriamente,
lo ordene de menor a mayor y muestre por pantalla el arreglo ordenado. */

#include <stdio.h>

#include "../functions.h"

int main(void) {
    const size_t arr_size = 100;
    const int low_lim = -100, upp_lim = 100;
    int arr[arr_size];

    cargar_vector_enteros_aleatorios(arr, arr_size, low_lim, upp_lim);
    printf("Valores del arreglo: \n");
    mostrar_vector_enteros(arr, arr_size);
    printf("\n");

    ordenar_vector_enteros(arr, arr_size);
    printf("Valores del arreglo ordenado: \n");
    mostrar_vector_enteros(arr, arr_size);
    printf("\n");

    return 0;
}
