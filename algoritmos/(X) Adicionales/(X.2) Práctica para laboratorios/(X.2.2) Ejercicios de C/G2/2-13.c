/* Escribir un algoritmo que ponga en cero todos los elementos de una matriz
5x5 y la muestre por pantalla. */

#include <stdio.h>

void cargar_matriz_ceros(size_t hor_size, size_t ver_size,
                         int arr[hor_size][ver_size]) {
    for (size_t i = 0; i < hor_size; i++) {
        for (size_t j = 0; j < ver_size; j++) {
            arr[i][j] = 0;
        }
    }
}

void mostrar_matriz(size_t hor_size, size_t ver_size,
                    int arr[hor_size][ver_size]) {
    for (size_t i = 0; i < hor_size; i++) {
        for (size_t j = 0; j < ver_size; j++) {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    const size_t hor_size = 5, ver_size = 5;
    int arr[hor_size][ver_size];

    cargar_matriz_ceros(hor_size, ver_size, arr);
    mostrar_matriz(hor_size, ver_size, arr);
    return 0;
}
