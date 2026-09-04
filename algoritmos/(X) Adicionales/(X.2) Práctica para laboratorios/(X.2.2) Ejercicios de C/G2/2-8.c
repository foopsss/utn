/* Crear una función que, dado un arreglo A de enteros de 20 posiciones y otro
arreglo B de enteros de 5 posiciones, devuelva en que posición del arreglo A se
encuentra el arreglo B. En caso de que el arreglo A no se encuentre dentro de B
devolver -1. */

#include <stdio.h>

#include "../functions.h"

void cargar_arreglo_secuencial(int* arr, size_t arr_size, int start_value) {
    for (size_t i = 0; i < arr_size; i++) {
        arr[i] = start_value + i;
    }
}

int controlar_presencia_arreglo(int* large_arr, size_t large_arr_size,
                                int* short_arr, size_t short_arr_size) {
    size_t j;

    // Únicamente se revisa hasta la posición (A - B), porque si ya
    // no coinciden ahí los arreglos, luego no alcanzan los espacios
    // para que coincidan por completo.
    for (size_t i = 0; i <= (large_arr_size - short_arr_size); i++) {
        for (j = 0; j < short_arr_size; j++) {
            if (short_arr[j] != large_arr[i + j]) {
                break;
            }
        }

        if (j == short_arr_size) {
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
    const size_t arrA_size = 20, arrB_size = 5;
    const int start_valueA = 0, start_valueB = 9;
    int arrA[arrA_size], arrB[arrB_size];

    cargar_arreglo_secuencial(arrA, arrA_size, start_valueA);
    cargar_arreglo_secuencial(arrB, arrB_size, start_valueB);

    printf("Primer arreglo: \n");
    mostrar_arreglo_enteros(arrA, arrA_size);
    printf("\n");
    printf("Segundo arreglo: \n");
    mostrar_arreglo_enteros(arrB, arrB_size);
    printf("\n");

    int result = controlar_presencia_arreglo(arrA, arrA_size, arrB, arrB_size);
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
