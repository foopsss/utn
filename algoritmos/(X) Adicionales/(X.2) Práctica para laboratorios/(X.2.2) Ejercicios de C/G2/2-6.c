/* Crear una función que verifique si un arreglo de 10 posiciones se encuentra
ordenado de forma ascendente o no, la cual debe devolver 1 (verdadero) si el
arreglo está ordenado y 0 (falso) en caso de no estarlo. */

#include <stdio.h>

#include "../functions.h"

int verificar_orden_arreglo(int* arr, size_t arr_size) {
    for (size_t i = 1; i < arr_size; i++) {
        if (arr[i] < arr[i - 1]) {
            return 0;
        }
    }
    return 1;
}

void evaluar_resultado(int result) {
    if (result == 1) {
        printf("(el arreglo está ordenado)\n");
    } else {
        printf("(el arreglo está desordenado)\n");
    }
}

int main(void) {
    const size_t arr_size = 10;
    const int low_lim = 0;
    const int upp_lim = 100;
    int arr_ent[arr_size], result;

    cargar_arreglo_enteros(arr_ent, arr_size, low_lim, upp_lim);
    printf("Arreglo generado por la computadora: \n");
    mostrar_arreglo_enteros(arr_ent, arr_size);

    result = verificar_orden_arreglo(arr_ent, arr_size);
    printf("\nEl resultado del análisis es: %d ", result);
    evaluar_resultado(result);

    ordenar_arreglo_enteros(arr_ent, arr_size);
    result = verificar_orden_arreglo(arr_ent, arr_size);
    printf("\n");
    printf("Arreglo reordenado: \n");
    mostrar_arreglo_enteros(arr_ent, arr_size);
    printf("\nEl resultado del análisis es: %d ", result);
    evaluar_resultado(result);

    return 0;
}
