// Material para esta librería:
// https://bumbershootsoft.wordpress.com/2022/07/24/custom-printf-wrapping-variadic-functions-in-c/
// https://www.zetcode.com/clang/vsnprintf/
// https://www.cprogramming.com/tutorial/c/lesson17.html

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

#include "functions_priv.h"

// IO.
static inline int obtener_entero_usuario() {
    int output, ret_val = scanf("%d", &output);

    if (ret_val != 1) {
        fprintf(stderr,
                "Se produjo un error al recibir el entero solicitado al "
                "usuario.\n");
        exit(EXIT_FAILURE);
    }

    return output;
}

static inline void imprimir_string_subrayado(const char* string, ...) {
    va_list str_args;
    int str_len = 0, str_alloc_res = 0, fixed_str_len, i;
    size_t null_buffer_size = 0;

    // Se escribe al búfer NULL para poder medir
    // primero la longitud del string de entrada.
    va_start(str_args, string);
    str_len = vsnprintf(NULL, null_buffer_size, string, str_args);
    va_end(str_args);

    if (str_len < 1) {
        if (str_len < 0) {
            fprintf(stderr,
                    "No se pudo obtener la longitud del string a imprimir.");
        }
        return;
    }

    // Búfer real.
    char buffer_a_imprimir[str_len + 1];
    va_start(str_args, string);
    str_alloc_res =
        vsnprintf(buffer_a_imprimir, (size_t)(str_len + 1), string, str_args);
    va_end(str_args);

    if (str_alloc_res < 0) {
        fprintf(stderr, "No se pudo formatear el string a imprimir");
        return;
    }

    // Si el último carácter del string es un salto
    // de línea, no se lo debe imprimir. Es mejor
    // poner uno manualmente para evitar
    // inconsistencias.
    if (buffer_a_imprimir[str_len - 1] == '\n') {
        buffer_a_imprimir[str_len - 1] = '\0';
        str_len--;
    }

    // La codificación UTF-8 hace que las letras
    // acentuadas (y otros caracteres) tengan más
    // de un byte de longitud.
    //
    // Si una posición del búfer de salida es un
    // byte de continuación, no se la debe considerar
    // en la longitud de la línea a imprimir.
    fixed_str_len = str_len;
    for (i = 0; i < str_len; i++) {
        int bits_pos_inv = buffer_a_imprimir[i] & 0xC0;
        if (bits_pos_inv == 0x80) {
            fixed_str_len--;
        }
    }

    printf("%s", buffer_a_imprimir);
    putchar('\n');

    for (i = 0; i < fixed_str_len; i++) {
        putchar('-');
    }

    putchar('\n');
}

// Tratamiento de arreglos.
static inline void cargar_vector_enteros_aleatorios(int* vec,
                                                    const size_t vec_size,
                                                    const int lim_inf,
                                                    const int lim_sup) {
    _verificar_tamanio_vector(vec_size);
    _verificar_limites_carga(lim_inf, lim_sup);

    for (size_t i = 0; i < vec_size; i++) {
        vec[i] = _obtener_valor_aleatorio_arreglo(lim_inf, lim_sup);
    }
}

static inline void cargar_vector_enteros_usuario(int* vec,
                                                 const size_t vec_size) {
    _verificar_tamanio_vector(vec_size);
    for (size_t i = 0; i < vec_size; i++) {
        printf("Introduzca un número para la posición %zu del arreglo: ", i);
        vec[i] = obtener_entero_usuario();
    }
}

static inline void ordenar_vector_enteros(int* vec, const size_t vec_size) {
    if (vec_size < 2) {
        return;
    }

    for (size_t i = 1; i < vec_size; i++) {
        size_t ind_act = i;
        int resguardo = vec[ind_act];

        while (ind_act > 0 && vec[ind_act - 1] > resguardo) {
            vec[ind_act] = vec[ind_act - 1];
            ind_act--;
        }

        vec[ind_act] = resguardo;
    }
}

static inline void mostrar_vector_enteros(const int* vec,
                                          const size_t vec_size) {
    for (size_t i = 0; i < vec_size; i++) {
        printf("Valor de la posición %zu del arreglo: %d\n", i, vec[i]);
    }
}

static inline void cargar_matriz_enteros_aleatorios(
    const size_t hor_size, const size_t ver_size, int mat[hor_size][ver_size],
    const int lim_inf, const int lim_sup) {
    assert(hor_size > 1);
    assert(ver_size >= 1);
    _verificar_limites_carga(lim_inf, lim_sup);

    for (size_t i = 0; i < hor_size; i++) {
        for (size_t j = 0; j < ver_size; j++) {
            mat[i][j] = _obtener_valor_aleatorio_arreglo(lim_inf, lim_sup);
        }
    }
}

static inline void mostrar_matriz_enteros(const size_t hor_size,
                                          const size_t ver_size,
                                          int mat[hor_size][ver_size]) {
    for (size_t i = 0; i < hor_size; i++) {
        imprimir_string_subrayado("Fila %zu\n", i);

        for (size_t j = 0; j < ver_size; j++) {
            printf("Valor de la columna %zu: %d\n", j, mat[i][j]);
        }

        printf("\n");
    }
}

#endif
