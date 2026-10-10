/* Escribir un programa que, dado un número entero, devuelva la suma de todos
sus dígitos. */

#include <stdio.h>

int main(void) {
    int num_us, suma_dig;

    suma_dig = 0;
    printf("Introduzca un número: ");
    scanf("%d", &num_us);

    while (num_us != 0) {
        suma_dig += num_us % 10;
        num_us = num_us / 10;
    }

    printf("Suma de los dígitos del número: %d\n", suma_dig);

    return 0;
}
