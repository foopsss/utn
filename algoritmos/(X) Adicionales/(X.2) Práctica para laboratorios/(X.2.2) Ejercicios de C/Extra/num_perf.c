// Este algoritmo presenta una función recursiva que permite verificar si un
// número es perfecto. Es decir, si la suma de sus divisores, sin contar a sí
// mismo, es igual al número en cuestión.

#include <stdbool.h>
#include <stdio.h>

bool es_perfecto(int num, int divisor, int suma_div) {
    if (divisor != 0) {
        if (num % divisor == 0) {
            es_perfecto(num, divisor - 1, suma_div + divisor);
        } else {
            es_perfecto(num, divisor - 1, suma_div);
        }
    } else {
        // Descomentar esto si se quiere ver
        // qué hace la función.
        // printf("suma_div: %d\n", suma_div);

        if (suma_div % num == 0) {
            return true;
        } else {
            return false;
        }
    }
}

int main() {
    int num_us;

    printf("Introduzca un número: ");
    scanf("%d", &num_us);

    if (es_perfecto(num_us, num_us - 1, 0)) {
        printf("¡El número es perfecto!\n");
    } else {
        printf("¡El número NO es perfecto!\n");
    }

    return 0;
}
