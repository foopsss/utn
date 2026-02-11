// Material para esta librería:
// https://stackoverflow.com/questions/822323/how-to-generate-a-random-int-in-c
// https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)Randomization.html
// https://stackoverflow.com/questions/54202670
// https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/rand-s?view=msvc-170
// https://man7.org/linux/man-pages/man2/getrandom.2.html

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int get_random_number() {
    int num;

    // clang-format off
    #ifdef _WIN32
        #define _CRT_RAND_S
        rand_s(&num);
    #elif __linux__
        #include <sys/random.h>
        getrandom(&num, sizeof(num), 0);
    #else
        #include <time.h>
        srand(time(NULL));
        num = rand();
    #endif
    // clang-format on

    return num;
}

void cargar_arreglo_enteros(int* arr, size_t arr_size, int low_lim,
                            int upp_lim) {
    assert(low_lim != upp_lim);

    for (size_t i = 0; i < arr_size; i++) {
        // Explicación de la fórmula utilizada:
        // 1. (upp_lim - low_lim + 1) determina la cantidad de números
        //    al azar que se pueden obtener.
        // 2. get_random_number() % (cant. posibles números) permite obtener
        //    un número entre 0 y la cantidad de posibles números a obtener.
        // 3. Al resultado del módulo se le suma el valor del límite
        //    inferior para que por lo menos sea igual a dicho número.
        arr[i] = (get_random_number() % (upp_lim - low_lim + 1)) + low_lim;
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
