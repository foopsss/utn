/* Escribir un algoritmo que, dado un arreglo de 100 posiciones cargado con
números aleatorios, muestre por pantalla los 5 números más pequeños. */

#include "../functions.h"

int main(void) {
    const char line_symbol = '=';
    const size_t vec_size = 100;
    const int lim_inf = -100, lim_sup = 100;
    int vec[vec_size];

    imprimir_string_subrayado(line_symbol, "Arreglo de enteros cargado");
    cargar_vector_enteros_aleatorios(vec, vec_size, lim_inf, lim_sup);
    mostrar_vector_enteros(vec, vec_size);
    ordenar_vector_enteros(vec, vec_size);

    printf("\n");
    imprimir_string_subrayado(line_symbol, "Cinco valores más pequeños");
    for (size_t i = 0; i < 5; i++) {
        printf("%d\n", vec[i]);
    }

    return 0;
}
