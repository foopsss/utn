/* Realizar una función que tome dos arreglos y cargue los contenidos de uno en
el otro. */

#include <stdio.h>

#include "../functions.h"

void copiar_arreglo(int* empty_array, int* array_with_contents,
                    size_t shared_arr_size) {
    for (size_t i = 0; i < shared_arr_size; i++) {
        empty_array[i] = array_with_contents[i];
    }
}

int main(void) {
    const size_t arr_size = 10;
    const int low_lim = 0, upp_lim = 10;
    int arr_a[arr_size], arr_b[arr_size];

    cargar_arreglo_enteros(arr_a, arr_size, low_lim, upp_lim);
    copiar_arreglo(arr_b, arr_a, arr_size);

    printf("Valores del arreglo A (cargado por defecto):\n");
    mostrar_arreglo_enteros(arr_a, arr_size);
    printf("\n");
    printf("Valores del arreglo B (rellenado con los valores de A):\n");
    mostrar_arreglo_enteros(arr_b, arr_size);

    return 0;
}
