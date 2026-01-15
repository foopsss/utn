// Este algoritmo presenta una función recursiva que, dado un código binario,
// permite calcular si se cumple el patrón de que el número esté compuesto por
// una cantidad impar de 1.

#include <stdbool.h>
#include <stdio.h>

bool cumple_patron(long int entrada, int cant_uno) {
    // Descomentar esto si se quiere ver
    // qué hace la función.
    // printf("Entrada: %ld\n", entrada);
    // printf("cant_uno: %d\n", cant_uno);

    if (entrada % 10 == entrada) {
        if (entrada == 1) {
            cant_uno += 1;
        }

        if (cant_uno % 2 == 0) {
            return false;
        } else {
            return true;
        }
    } else {
        if (entrada % 10 == 1) {
            cumple_patron(entrada / 10, cant_uno + 1);
        } else {
            cumple_patron(entrada / 10, cant_uno);
        }
    }
}

int main() {
    long int binario;

    printf("Introduzca un código binario: ");
    scanf("%ld", &binario);

    if (cumple_patron(binario, 0)) {
        printf("El número cumple con el patrón.\n");
    } else {
        printf("El número NO cumple con el patrón.\n");
    }

    return 0;
}
