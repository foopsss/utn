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
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef __linux__
    #include <sys/random.h>
#elif !defined(_WIN32)
    #include <time.h>
#endif
// clang-format on

static inline unsigned int _obtener_num_positivo_aleatorio(void) {
    unsigned int num = 0;

    // clang-format off
    #ifdef _WIN32
        errno_t ret_val = rand_s(&num);

        if (ret_val != 0) {
            errno = ret_val;
            perror("Error generando número aleatorio en Windows");
            exit(EXIT_FAILURE);
        }
    #elif __linux__
        ssize_t ret_val = getrandom(&num, sizeof(num), 0);

        if (ret_val < 0) {
            perror("Error generando número aleatorio en Linux");
            exit(EXIT_FAILURE);
        }

        if ((size_t)ret_val < sizeof(num)) {
            fprintf(stderr, "getrandom() no llenó el buffer de entrada.\n");
            exit(EXIT_FAILURE);
        }
    #else
        static bool seeded = false;

        if (!seeded) { 
            srand(time(NULL));
            seeded = true;
        }

        num = rand();
    #endif
    // clang-format on

    return num;
}

static inline int _obtener_valor_aleatorio_arreglo(const int lim_inf,
                                                   const int lim_sup) {
    int num_pos = (int)_obtener_num_positivo_aleatorio();

    // El cambio de tipo de num_pos a int puede hacer que se
    // convierta en un número negativo si su bit más significativo
    // es 1. Es necesario evitarlo para que luego la aplicación
    // de la fórmula siguiente no genere valores que excedan el
    // rango indicado en los parámetros.
    if (num_pos < 0) {
        num_pos = num_pos & 0x7FFFFFFF;
    }

    // Explicación de la fórmula utilizada:
    // 1. (lim_sup - lim_inf + 1) determina la cantidad de números
    //    al azar que se pueden obtener.
    // 2. num_pos % (cant. posibles números) permite obtener un
    //    número entre 0 y la cantidad de posibles números a obtener.
    // 3. Al resultado del módulo se le suma el valor del límite
    //    inferior para que por lo menos sea igual a dicho número.
    return (num_pos % (lim_sup - lim_inf + 1)) + lim_inf;
}

static inline void _verificar_tamanio_vector(const size_t vec_size) {
    assert(vec_size >= 1);
}

static inline void _verificar_limites_carga(const int lim_inf,
                                            const int lim_sup) {
    assert(lim_sup > lim_inf);
}

#endif
