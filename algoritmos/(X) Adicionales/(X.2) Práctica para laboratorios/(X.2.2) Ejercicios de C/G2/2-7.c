/* Crear una función que compare dos arreglos de 10 posiciones y verifique si
ambos son iguales. Al igual que en el caso anterior, la función debe devolver
1 (verdadero) si los arreglos son iguales y 0 (falso) en caso de que no lo
sean. */

#include <stdio.h>

#include "../functions.h"

int verificar_igualdad_arreglos(int* prim_arr, int* seg_arr,
                                size_t shared_arr_size) {
    for (size_t i = 0; i < shared_arr_size; i++) {
        if (prim_arr[i] != seg_arr[i]) {
            return 0;
        }
    }
    return 1;
}

void evaluar_resultado(int result) {
    if (result == 1) {
        printf("(los arreglos son iguales)\n");
    } else {
        printf("(los arreglos son distintos)\n");
    }
}

int main(void) {
    const size_t arr_size = 10;
    const int low_lim = 0;
    // Uso rangos distintos para generar los contenidos de los arreglos porque
    // si utilizo el mismo rango para ambos obtengo exactamente los mismos
    // valores.
    // Probablemente tenga que ver con la manera en la que está implementada la
    // función cargar_arreglo_enteros(), específicamente con el seeding o
    // preparación del generador, algo que no es fácil de cambiar.
    const int prim_arr_upp_lim = 150;
    const int seg_arr_upp_lim = 200;
    int prim_arr[arr_size], seg_arr[arr_size], result;

    cargar_arreglo_enteros(prim_arr, arr_size, low_lim, prim_arr_upp_lim);
    cargar_arreglo_enteros(seg_arr, arr_size, low_lim, seg_arr_upp_lim);

    printf("Primer arreglo generado por la computadora: \n");
    mostrar_arreglo_enteros(prim_arr, arr_size);
    printf("\nSegundo arreglo generado por la computadora: \n");
    mostrar_arreglo_enteros(seg_arr, arr_size);

    result = verificar_igualdad_arreglos(prim_arr, seg_arr, arr_size);
    printf("\nEl resultado de la comparación es: %d ", result);
    evaluar_resultado(result);

    for (size_t i = 0; i < arr_size; i++) {
        seg_arr[i] = prim_arr[i];
    }

    printf("\nRedefinición del segundo arreglo: \n");
    mostrar_arreglo_enteros(seg_arr, arr_size);

    result = verificar_igualdad_arreglos(prim_arr, seg_arr, arr_size);
    printf("\nEl resultado de la comparación es: %d ", result);
    evaluar_resultado(result);

    return 0;
}
