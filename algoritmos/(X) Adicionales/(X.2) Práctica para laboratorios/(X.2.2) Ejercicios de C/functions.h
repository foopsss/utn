#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <assert.h>
#include <stdio.h>

#include "functions_priv.h"

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
        scanf("%d", &vec[i]);
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
        _imprimir_string_subrayado("Fila %zu\n", i);

        for (size_t j = 0; j < ver_size; j++) {
            printf("Valor de la columna %zu: %d\n", j, mat[i][j]);
        }

        printf("\n");
    }
}

#endif
