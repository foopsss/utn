/* Genere un algoritmo que calcule el producto de dos números enteros A y B
utilizando únicamente la operación suma. */

#include <stdio.h>

int main(void) {
    int num_a, num_b, prod = 0;

    printf("Introduzca un número A: ");
    scanf("%d", &num_a);

    printf("Introduzca un número B: ");
    scanf("%d", &num_b);

    for (int i = 0; i < num_b; i++) {
        prod += num_a;
    }

    printf("Resultado del producto: %d\n", prod);

    return 0;
}
