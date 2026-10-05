/* Generar un algoritmo que encuentre los primeros 50 números que sean primos.
 */

#include <stdbool.h>
#include <stdio.h>

bool verificar_primo(int var_num) {
    bool es_primo = true;

    for (int i = 2; i <= (var_num - 1); i++) {
        if (var_num % i == 0) {
            es_primo = false;
            break;
        }
    }

    if (es_primo) {
        return true;
    } else {
        return false;
    }
}

int main(void) {
    int num = 1, cant_primos = 0;

    while (cant_primos != 50) {
        if (verificar_primo(num)) {
            printf("Número primo encontrado: %d\n", num);
            cant_primos += 1;
        }
        num += 1;
    }

    return 0;
}
