// Material para esta librería:
// https://stackoverflow.com/questions/822323/how-to-generate-a-random-int-in-c
// https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)Randomization.html
// https://stackoverflow.com/questions/54202670
// https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/rand-s?view=msvc-170
// https://man7.org/linux/man-pages/man2/getrandom.2.html

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// clang-format off
#ifdef _WIN32
    // Macro específico de Windows que debe ser definido
    // antes de importar la librería "stdlib".
    #define _CRT_RAND_S
#endif

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef __linux__
    #include <sys/random.h>
#elif !defined(_WIN32)
    #include <time.h>
#endif
// clang-format on

int get_random_number(bool get_negative_num) {
    int num;

    // clang-format off
    #ifdef _WIN32
        rand_s(&num);
    #elif __linux__
        getrandom(&num, sizeof(num), 0);
    #else
        srand(time(NULL));
        num = rand();
    #endif
    // clang-format on

    if (!get_negative_num && num < 0) {
        // En caso de que se obtenga un número negativo pero
        // no se pueda trabajar con números negativos se aplica
        // una máscara binaria para obtener el valor absoluto
        // del número.
        //
        // La conversión se realiza de esta manera y no con
        // la función abs() de "stdlib.h" porque abs() no es
        // capaz de devolver correctamente el valor absoluto
        // de INT_MIN (-2.147.483.648), que es uno de los
        // valores que se podrían obtener tratando de llenar
        // 32 bits de espacio con valores al azar.
        //
        // Dicha operación resulta exactamente en el mismo
        // valor o en conducta indefinida, dependiendo del
        // compilador utilizado, porque los 32 bits del
        // tipo "int" no alcanzan para representar una
        // versión positiva del valor INT_MIN.
        //
        // Esta máscara es un valor en hexadecimal donde
        // todos los bits, salvo el más significativo,
        // tienen valor 1, de manera que se conserva el
        // valor de todos los bits correspondientes al
        // valor de la variable "num", salvo el del bit
        // del signo.
        num = num & 0x7FFFFFFF;
    }

    return num;
}

void cargar_arreglo_enteros(int* arr, size_t arr_size, int low_lim,
                            int upp_lim) {
    assert(low_lim != upp_lim);
    bool allow_negative_values = false;

    for (size_t i = 0; i < arr_size; i++) {
        // Explicación de la fórmula utilizada:
        // 1. (upp_lim - low_lim + 1) determina la cantidad de números
        //    al azar que se pueden obtener.
        // 2. get_random_number() % (cant. posibles números) permite obtener
        //    un número entre 0 y la cantidad de posibles números a obtener.
        // 3. Al resultado del módulo se le suma el valor del límite
        //    inferior para que por lo menos sea igual a dicho número.
        if (low_lim < 0) {
            allow_negative_values = true;
        }

        arr[i] = (get_random_number(allow_negative_values) %
                  (upp_lim - low_lim + 1)) +
                 low_lim;
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
