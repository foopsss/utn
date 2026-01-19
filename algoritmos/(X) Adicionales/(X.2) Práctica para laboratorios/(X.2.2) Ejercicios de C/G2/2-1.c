/* Realizar un algoritmo que cargue un arreglo de 10 enteros y lo muestre por
pantalla. */

#include <stdio.h>

int main(void) {
    const size_t arr_size = 10;
    size_t i;
    int arr_ent[arr_size];

    for (i = 0; i < arr_size; i++) {
        printf("Introduzca un número para la posición %zu del arreglo: ", i);
        scanf("%d", &arr_ent[i]);
    }

    printf("\n");
    printf("Valores cargados\n");
    printf("================\n");

    for (i = 0; i < arr_size; i++) {
        printf("Valor de la posición %zu del arreglo: %d\n", i, arr_ent[i]);
    }

    return 0;
}
