/* Realizar una función que tome dos arreglos y cargue los contenidos de uno en
el otro. */

#include <stdio.h>

#include "../functions.h"

void copiar_arreglo(int* empty_vec, const int* vec_with_contents,
                    const size_t shared_vec_size) {
    for (size_t i = 0; i < shared_vec_size; i++) {
        empty_vec[i] = vec_with_contents[i];
    }
}

int main(void) {
    const size_t vec_size = 10;
    const int lim_inf = 0, lim_sup = 10;
    int vec_a[vec_size], vec_b[vec_size];

    cargar_vector_enteros_aleatorios(vec_a, vec_size, lim_inf, lim_sup);
    copiar_arreglo(vec_b, vec_a, vec_size);

    printf("Valores del arreglo A (cargado por defecto):\n");
    mostrar_vector_enteros(vec_a, vec_size);
    printf("\n");
    printf("Valores del arreglo B (rellenado con los valores de A):\n");
    mostrar_vector_enteros(vec_b, vec_size);

    return 0;
}
