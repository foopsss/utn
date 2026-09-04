/* Crear una función que sume los elementos de un arreglo de enteros de 10
posiciones y devuelva el resultado. */

#include <stdio.h>

#include "../functions.h"

int sumar_elementos(int* arr, size_t arr_size) {
    int suma = 0;
    for (size_t i = 0; i < arr_size; i++) {
        printf("Posición del arreglo: %zu|Número: %d\n", i, arr[i]);
        suma += arr[i];
    }
    return suma;
}

int main(void) {
    const size_t arr_size = 10;
    const int low_lim = 0, upp_lim = 100;
    int arr_ent[arr_size], suma_elem;

    cargar_arreglo_enteros(arr_ent, arr_size, low_lim, upp_lim);
    suma_elem = sumar_elementos(arr_ent, arr_size);
    printf("Valor de la suma de los elementos del arreglo: %d\n", suma_elem);
    return 0;
}
