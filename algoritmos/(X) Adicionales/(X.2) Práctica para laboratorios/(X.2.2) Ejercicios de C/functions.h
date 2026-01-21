// Material para esta librería:
// https://stackoverflow.com/questions/822323/how-to-generate-a-random-int-in-c
// https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)Randomization.html
// https://stackoverflow.com/questions/54202670

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargar_arreglo_enteros(int* arr, size_t arr_size, int low_lim,
                            int upp_lim) {
    assert(low_lim != upp_lim);

    // Preparación (seeding) del generador de números aleatorios.
    srand(time(NULL));

    for (size_t i = 0; i < arr_size; i++) {
        // Explicación de la fórmula utilizada:
        // 1. (upp_lim - low_lim + 1) determina la cantidad de números
        //    al azar que se pueden obtener.
        // 2. rand() % (cant. posibles números) permite obtener un número
        //    entre 0 y la cantidad de posibles números a obtener.
        // 3. Al resultado del módulo se le suma el valor del límite
        //    inferior para que por lo menos sea igual a dicho número.
        arr[i] = (rand() % (upp_lim - low_lim + 1)) + low_lim;
    }
}

void ordenar_arreglo_enteros(int* arr, size_t arr_size) {
    if (arr_size < 2) {
        // Los arreglos vacíos o de un elemento no
        // necesitan ser ordenados.
        return;
    }

    for (size_t i = 1; i < arr_size; i++) {
        size_t ind_act = i;
        int resguardo = arr[ind_act];

        while (ind_act > 0 && arr[ind_act - 1] > resguardo) {
            arr[ind_act] = arr[ind_act - 1];
            ind_act--;
        }

        arr[ind_act] = resguardo;
    }
}

void mostrar_arreglo_enteros(int* arr, size_t arr_size) {
    for (size_t i = 0; i < arr_size; i++) {
        printf("Valor de la posición %zu del arreglo: %d\n", i, arr[i]);
    }
}

#endif
