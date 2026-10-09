// Material para esta librería:
// https://stackoverflow.com/questions/822323/how-to-generate-a-random-int-in-c
// https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)Randomization.html
// https://stackoverflow.com/questions/54202670
// https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/rand-s?view=msvc-170
// https://man7.org/linux/man-pages/man2/getrandom.2.html

#ifndef FUNCTIONS_PRIV_H
#define FUNCTIONS_PRIV_H

// clang-format off
#ifdef _WIN32
    // Macro específico de Windows que debe ser definido
    // antes de importar la librería "stdlib" para generar
    // números al azar.
    #define _CRT_RAND_S
#endif

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __linux__
    #include <sys/random.h>
#elif !defined(_WIN32)
    #include <time.h>
#endif
// clang-format on

static inline int _obtener_num_positivo_aleatorio() {
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

    if (num < 0) {
        // En caso de que se obtenga un número negativo
        // se aplica una máscara binaria para obtener el
        // valor absoluto del número.
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

static inline void _imprimir_string_subrayado(const char* string, ...) {
    va_list str_args;
    int null_buffer_size = 0;

    va_start(str_args, string);
    // Se escribe al búfer NULL para poder medir
    // primero la longitud del string de entrada.
    int str_len = vsnprintf(NULL, null_buffer_size, string, str_args);
    va_end(str_args);

    char buffer_a_imprimir[str_len + 1];
    va_start(str_args, string);
    vsnprintf(buffer_a_imprimir, str_len + 1, string, str_args);
    va_end(str_args);

    // Si el último carácter del string es un salto
    // de línea, no se lo debe imprimir. Es mejor
    // poner uno manualmente para evitar
    // inconsistencias.
    if (buffer_a_imprimir[str_len - 1] == '\n') {
        buffer_a_imprimir[str_len - 1] = '\0';
        str_len--;
    }

    printf("%s", buffer_a_imprimir);
    putchar('\n');

    for (int i = 0; i < str_len; i++) {
        putchar('-');
    }
    putchar('\n');
}

static inline int _obtener_valor_aleatorio_arreglo(const int lim_inf,
                                                   const int lim_sup) {
    // Explicación de la fórmula utilizada:
    // 1. (lim_sup - lim_inf + 1) determina la cantidad de números
    //    al azar que se pueden obtener.
    // 2. _obtener_num_aleatorio() % (cant. posibles números) permite
    //    obtener un número entre 0 y la cantidad de posibles números
    //    a obtener.
    // 3. Al resultado del módulo se le suma el valor del límite
    //    inferior para que por lo menos sea igual a dicho número.
    return (_obtener_num_positivo_aleatorio() % (lim_sup - lim_inf + 1)) +
           lim_inf;
}

static inline void _verificar_tamanio_vector(const size_t vec_size) {
    assert(vec_size >= 1);
}

static inline void _verificar_limites_carga(const int lim_inf,
                                            const int lim_sup) {
    assert(lim_sup > lim_inf);
}

#endif
