/* Realice un algoritmo que tome como entrada un número entero mayor o igual a
100 y menor que 1000, y muestre por pantalla su composición en términos de
unidades, decenas y centenas. */

#include <stdio.h>

#include "../functions.h"

int main(void) {
    int num_us, unidades, decenas, centenas;

    printf("Introduzca un número mayor o igual a 100 y menor a 1000: ");
    num_us = obtener_entero_usuario();

    if (num_us >= 100 && num_us < 1000) {
        unidades = num_us % 10;
        decenas = (num_us / 10) % 10;
        centenas = (num_us / 100) % 10;
        printf("El número cuenta con: \n");
        printf("%d unidades.\n", unidades);
        printf("%d decenas.\n", decenas);
        printf("%d centenas.\n", centenas);
    } else {
        printf("Introduzca un número mayor o igual a 100 y menor a 1000.\n");
    }

    return 0;
}
