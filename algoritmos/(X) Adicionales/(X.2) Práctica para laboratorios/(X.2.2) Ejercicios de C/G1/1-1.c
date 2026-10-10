/* Escribir un programa en C que, dado dos números enteros, realice la suma,
resta, multiplicación, división entera y resto de los mismos. Los números
son: X = 132 e Y = 34. */

#include <stdio.h>

int main() {
    const int x = 132, y = 34;

    int suma = x + y;
    int resta = x - y;
    int mult = x * y;
    int div_ent = x / y;
    int resto = x % y;

    printf("Valor de X: %d\n", x);
    printf("Valor de Y: %d\n", y);

    printf("\n");
    printf("Resultado de la suma: %d\n", suma);
    printf("Resultado de la resta: %d\n", resta);
    printf("Resultado de la multiplicación: %d\n", mult);
    printf("Resultado de la división entera: %d\n", div_ent);
    printf("Resultado del resto: %d\n", resto);

    return 0;
}
