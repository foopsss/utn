/* Escribir un algoritmo que permita al usuario ingresar una cantidad indeter-
minada de números enteros (la condición de fin es que el número ingresado sea
0 o un número menor a 0) y, al finalizar, muestre por pantalla los 5 números
más grandes que ingresó el usuario. */

#include <stdio.h>
#include <stdlib.h>

#include "../functions.h"

typedef struct Nodo {
    int num;
    struct Nodo* ant;
    struct Nodo* prox;
} Nodo;

Nodo* crear_nodo(const int num) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));

    if (nuevo == NULL) {
        fprintf(stderr, "No se pudo reservar memoria para un nodo.\n");
        exit(EXIT_FAILURE);
    }

    nuevo->num = num;
    nuevo->ant = NULL;
    nuevo->prox = NULL;
    return nuevo;
}

void limpiar_lista(Nodo* prim) {
    Nodo* aux = NULL;
    while (prim != NULL) {
        aux = prim;
        prim = prim->prox;
        free(aux);
    }
}

int main(void) {
    const char line_symbol = '=';
    Nodo* prim = NULL;
    Nodo* ult = NULL;
    Nodo* ventana = NULL;
    Nodo* nuevo = NULL;
    size_t long_lista = 0, pos_a_imp;
    unsigned int cant_val_a_imp;

    printf("Introduzca un número por favor.\n");
    printf("Para salir, introduzca 0, o un número menor.\n");
    printf("\n");
    printf("Número: ");
    int num_us = obtener_entero_usuario();

    if (num_us <= 0) {
        printf(
            "La ejecución del programa ha sido abortada sin introducir "
            "números.");
        return 1;
    }

    while (num_us > 0) {
        nuevo = crear_nodo(num_us);
        ventana = prim;

        if (ventana == NULL) {
            prim = nuevo;
            ult = nuevo;
        } else {
            while (ventana != NULL && ventana->num < num_us) {
                ventana = ventana->prox;
            }

            if (ventana == prim) {
                // Inserción previa al primer elemento.
                nuevo->prox = ventana;
                ventana->ant = nuevo;
                prim = nuevo;
            } else if (ventana == NULL) {
                // Inserción posterior al último elemento.
                nuevo->ant = ult;
                ult->prox = nuevo;
                ult = nuevo;
            } else {
                // Inserción intermedia.
                nuevo->prox = ventana;
                nuevo->ant = ventana->ant;
                ventana->ant->prox = nuevo;
                ventana->ant = nuevo;
            }
        }

        long_lista++;
        printf("Introduzca otro número: ");
        num_us = obtener_entero_usuario();
    }

    if (long_lista < 5) {
        cant_val_a_imp = (unsigned int)long_lista;
    } else {
        cant_val_a_imp = 5;
    }

    printf("\n");
    imprimir_string_subrayado(line_symbol, "%u valores más grandes",
                              cant_val_a_imp);

    ventana = ult;
    for (size_t i = 0; i < cant_val_a_imp; i++) {
        pos_a_imp = long_lista - i;
        printf("Valor: %d en posición %zu.\n", ventana->num, pos_a_imp);
        ventana = ventana->ant;
    }

    limpiar_lista(prim);

    return 0;
}
