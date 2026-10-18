/* Crear una función que verifique si un arreglo de 10 posiciones se encuentra
ordenado de forma ascendente o no, la cual debe devolver 1 (verdadero) si el
arreglo está ordenado y 0 (falso) en caso de no estarlo. */

#include <stdio.h>

#include "../functions.h"

unsigned int verificar_orden_arreglo(const int* arr, const size_t vec_size) {
    for (size_t i = 1; i < vec_size; i++) {
        if (arr[i] < arr[i - 1]) {
            return 0;
        }
    }
    return 1;
}

void evaluar_resultado(const unsigned int result) {
    if (result == 1) {
        printf("(el arreglo está ordenado)\n");
    } else {
        printf("(el arreglo está desordenado)\n");
    }
}

int main(void) {
    const size_t vec_size = 10;
    const int lim_inf = 0, lim_sup = 100;
    int vec[vec_size];
    char line_symbol = '=';
    unsigned int result;

    imprimir_string_subrayado(line_symbol,
                              "Arreglo generado por la computadora");
    cargar_vector_enteros_aleatorios(vec, vec_size, lim_inf, lim_sup);
    mostrar_vector_enteros(vec, vec_size);

    result = verificar_orden_arreglo(vec, vec_size);
    printf("\nEl resultado del análisis es: %d ", result);
    evaluar_resultado(result);

    printf("\n");
    imprimir_string_subrayado(line_symbol, "Arreglo reordenado");
    ordenar_vector_enteros(vec, vec_size);
    mostrar_vector_enteros(vec, vec_size);

    result = verificar_orden_arreglo(vec, vec_size);
    printf("\nEl resultado del análisis es: %d ", result);
    evaluar_resultado(result);

    return 0;
}
