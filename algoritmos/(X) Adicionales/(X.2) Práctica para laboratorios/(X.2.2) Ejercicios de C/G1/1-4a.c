/* Realizar un algoritmo que verifique si un número es par o impar. */

#include <stdio.h>

#include "../functions.h"

int main(void) {
    int num_us;

    printf("Introduzca un número: ");
    num_us = obtener_entero_usuario();

    if (num_us % 2 == 0) {
        printf("El número es par.\n");
    } else {
        printf("El número NO es par.\n");
    }

    return 0;
}
