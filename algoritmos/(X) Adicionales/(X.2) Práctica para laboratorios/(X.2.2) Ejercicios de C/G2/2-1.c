/* Realizar un algoritmo que cargue un arreglo de 10 enteros y lo muestre por
pantalla. */

#include <stdio.h>

#include "../functions.h"

int main(void) {
    const size_t vec_size = 10;
    int vec[vec_size];
    char line_symbol = '=';

    cargar_vector_enteros_usuario(vec, vec_size);
    printf("\n");
    imprimir_string_subrayado(line_symbol, "Valores del arreglo");
    mostrar_vector_enteros(vec, vec_size);

    return 0;
}
