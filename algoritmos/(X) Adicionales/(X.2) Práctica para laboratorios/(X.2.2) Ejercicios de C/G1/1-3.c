/* Escribir un programa en C que, dado dos números enteros, realice la suma,
resta, multiplicación, división entera y resto de los mismos. Los números
deben ser ingresados por el usuario, así como la operación a realizar. */

#include <stdio.h>

void op_suma(int a, int b) {
    int suma = a + b;
    printf("Resultado de la suma: %d\n", suma);
}

void op_resta(int a, int b) {
    int resta = a - b;
    printf("Resultado de la resta: %d\n", resta);
}

void op_producto(int a, int b) {
    int mult = a * b;
    printf("Resultado de la multiplicación: %d\n", mult);
}

void op_divent(int a, int b) {
    int div_ent = a / b;
    printf("Resultado de la división entera: %d\n", div_ent);
}

void op_resto(int a, int b) {
    int resto = a % b;
    printf("Resultado del resto: %d\n", resto);
}

int main() {
    int eleccion, x, y;

    printf("Operaciones\n");
    printf("-----------\n");
    printf("1. Suma.\n");
    printf("2. Resta.\n");
    printf("3. Multiplicación.\n");
    printf("4. División entera.\n");
    printf("5. Resto.\n");

    printf("\n");
    printf("Introduzca su elección: ");
    scanf("%d", &eleccion);
    printf("Ingrese un valor para X: ");
    scanf("%d", &x);
    printf("Ingrese un valor para Y: ");
    scanf("%d", &y);

    printf("\n");
    switch (eleccion) {
        case 1:
            op_suma(x, y);
            break;
        case 2:
            op_resta(x, y);
            break;
        case 3:
            op_producto(x, y);
            break;
        case 4:
            op_divent(x, y);
            break;
        case 5:
            op_resto(x, y);
            break;
    }

    return 0;
}
