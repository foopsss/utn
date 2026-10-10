/* Escribir un algoritmo que ponga en cero todos los elementos de una matriz
5x5 y la muestre por pantalla. */

#include "../functions.h"

void cargar_matriz_ceros(const size_t hor_size, const size_t ver_size,
                         int mat[hor_size][ver_size]) {
    for (size_t i = 0; i < hor_size; i++) {
        for (size_t j = 0; j < ver_size; j++) {
            mat[i][j] = 0;
        }
    }
}

int main(void) {
    const size_t hor_size = 5, ver_size = 5;
    int mat[hor_size][ver_size];

    cargar_matriz_ceros(hor_size, ver_size, mat);
    mostrar_matriz_enteros(hor_size, ver_size, mat);

    return 0;
}
