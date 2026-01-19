/* A partir del ejercicio anterior, realizar una función para cargar el arreglo
y otra para mostrarlo por pantalla. */

#include <stdio.h>

void cargar_arreglo(int* arr, size_t arr_size) {
    for (size_t i = 0; i < arr_size; i++) {
        printf("Introduzca un número para la posición %zu del arreglo: ", i);
        scanf("%d", &arr[i]);
    }
}

void mostrar_arreglo(int* arr, size_t arr_size) {
    printf("\n");
    printf("Valores cargados\n");
    printf("================\n");

    for (size_t i = 0; i < arr_size; i++) {
        printf("Valor de la posición %zu del arreglo: %d\n", i, arr[i]);
    }
}

int main(void) {
    const size_t arr_size = 10;
    int arr_ent[arr_size];

    cargar_arreglo(arr_ent, arr_size);
    mostrar_arreglo(arr_ent, arr_size);
    return 0;
}
