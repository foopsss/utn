/* Crear una función que sume los elementos de un arreglo de enteros de 10
posiciones y devuelva el resultado. */

#include <stdio.h>

#include "../functions.h"

int sumar_elementos(int* arr, const size_t vec_size) {
    int suma = 0;
    for (size_t i = 0; i < vec_size; i++) {
        suma += arr[i];
    }
    return suma;
}

int main(void) {
    const size_t vec_size = 10;
    const int lim_inf = 0, lim_sup = 100;
    int vec[vec_size], suma_elem;
    char line_symbol = '=';

    imprimir_string_subrayado(line_symbol, "Valores del arreglo generado");
    cargar_vector_enteros_aleatorios(vec, vec_size, lim_inf, lim_sup);
    mostrar_vector_enteros(vec, vec_size);

    suma_elem = sumar_elementos(vec, vec_size);
    printf("\n");
    printf("Valor de la suma de los elementos del arreglo: %d\n", suma_elem);

    return 0;
}
