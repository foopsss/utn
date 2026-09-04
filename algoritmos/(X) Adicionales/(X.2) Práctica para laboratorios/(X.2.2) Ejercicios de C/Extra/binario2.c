// Este algoritmo presenta una función recursiva que, dado un código binario,
// permite calcular si se cumple el patrón de que el número esté compuesto por
// una cantidad de 0 que sea múltiplo de 3.

#include <stdbool.h>
#include <stdio.h>

bool cumple_patron(long int entrada, int cant_cero) {
    // Descomentar esto si se quiere ver
    // qué hace la función.
    // printf("Entrada: %ld\n", entrada);
    // printf("cant_cero: %d\n", cant_cero);

    if (entrada / 10 == 0) {
        if (entrada % 10 == 0) {
            cant_cero += 1;
        }

        if (cant_cero % 3 == 0) {
            return true;
        } else {
            return false;
        }
    } else {
        if (entrada % 10 == 0) {
            cumple_patron(entrada / 10, cant_cero + 1);
        } else {
            cumple_patron(entrada / 10, cant_cero);
        }
    }
}

int main() {
    long int numero = 10101010;
    long int numero2 = 1011011100;

    if (cumple_patron(numero, 0)) {
        printf(
            "El número %ld tiene una cantidad de 0s que es múltiplo de 3.\n",
            numero);
    } else {
        printf(
            "El número %ld tiene una cantidad de 0s que NO es múltiplo de "
            "3.\n",
            numero);
    }

    printf("--------------------------------------------------\n");

    if (cumple_patron(numero2, 0)) {
        printf(
            "El número %ld tiene una cantidad de 0s que es múltiplo de 3.\n",
            numero2);
    } else {
        printf(
            "El número %ld tiene una cantidad de 0s que NO es múltiplo de "
            "3.\n",
            numero2);
    }

    return 0;
}
