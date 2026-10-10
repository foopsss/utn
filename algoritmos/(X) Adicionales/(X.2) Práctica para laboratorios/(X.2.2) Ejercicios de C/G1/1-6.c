/* Escribir un programa que, dado un número entero, imprima el número por
pantalla, así como su inverso (es decir, con sus dígitos al revés). Por
ejemplo: 1234 imprime 4321. */

#include <stdio.h>

int main(void) {
    int num_us, inv = 0;

    printf("Introduzca un número: ");
    scanf("%d", &num_us);

    while (num_us != 0) {
        inv = inv * 10;
        inv = inv + num_us % 10;
        num_us = num_us / 10;
    }

    printf("Reverso del número: %d\n", inv);

    return 0;
}
