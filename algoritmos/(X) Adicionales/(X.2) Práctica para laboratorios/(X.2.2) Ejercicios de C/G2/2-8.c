/* Crear una función que, dado un arreglo A de enteros de 20 posiciones y otro
arreglo B de enteros de 5 posiciones, devuelva en que posición del arreglo A se
encuentra el arreglo B. En caso de que el arreglo A no se encuentre dentro de B
devolver -1. */

#include <stdio.h>

#include "../functions.h"

void cargar_vector_secuencial(int* vec, const size_t vec_size,
                               const int start_value) {
    for (size_t i = 0; i < vec_size; i++) {
        vec[i] = start_value + i;
    }
}

int controlar_presencia_vector(const int* large_vec,
                                const size_t large_vec_size,
                                const int* short_vec,
                                const size_t short_vec_size) {
    size_t j;

    // Únicamente se revisa hasta la posición (A - B), porque si ya
    // no coinciden ahí los arreglos, luego no alcanzan los espacios
    // para que coincidan por completo.
    for (size_t i = 0; i <= (large_vec_size - short_vec_size); i++) {
        for (j = 0; j < short_vec_size; j++) {
            if (short_vec[j] != large_vec[i + j]) {
                break;
            }
        }

        if (j == short_vec_size) {
            // Type cast para ser coherente con los valores que se
            // trabajan y devuelven. "size_t" es un "unsigned int"
            // utilizado para trabajar con índices, mientras que
            // "int" tiene signo.
            //
            // Si bien el compilador realiza una conversión de
            // tipos automática, es preferible ser explícito
            // sobre lo que está sucediendo acá.
            return (int)i;
        }
    }

    return -1;
}

int main(void) {
    const size_t vecA_size = 20, vecB_size = 5;
    const int start_valueA = 0, start_valueB = 9;
    int vecA[vecA_size], vecB[vecB_size];

    cargar_vector_secuencial(vecA, vecA_size, start_valueA);
    cargar_vector_secuencial(vecB, vecB_size, start_valueB);

    printf("Primer arreglo: \n");
    mostrar_vector_enteros(vecA, vecA_size);
    printf("\n");
    printf("Segundo arreglo: \n");
    mostrar_vector_enteros(vecB, vecB_size);
    printf("\n");

    int result = controlar_presencia_vector(vecA, vecA_size, vecB, vecB_size);
    if (result == -1) {
        printf("El segundo arreglo no se encuentra dentro del primero.");
    } else {
        printf(
            "El segundo arreglo se encuentra dentro del primero a partir de "
            "la posición %d.\n",
            result);
    }

    return 0;
}
