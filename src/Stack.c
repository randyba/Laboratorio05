/*
Stack.c
IE-0117 Laboratorio 05

Implementación de las funciones del Stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

// Inicializa el stack
void inicializarStack(Stack *stack, int capacidad) {
    stack->datos = (int *)malloc(capacidad * sizeof(int));

    if (stack->datos == NULL) {
        printf("Error al reservar memoria.\n");
        exit(1);
    }

    stack->tope = -1;
    stack->capacidad = capacidad;
}

// Agrega un elemento al stack
void push(Stack *stack, int valor) {

    if (stack->tope == stack->capacidad - 1) {
        printf("El stack esta lleno.\n");
        return;
    }

    stack->tope++;
    stack->datos[stack->tope] = valor;
}

// Elimina el elemento del tope
int pop(Stack *stack) {

    if (isEmpty(stack)) {
        printf("El stack esta vacio.\n");
        return -1;
    }

    return stack->datos[stack->tope--];
}

// Devuelve el elemento del tope
int peek(Stack *stack) {

    if (isEmpty(stack)) {
        printf("El stack esta vacio.\n");
        return -1;
    }

    return stack->datos[stack->tope];
}

// Verifica si el stack está vacío
int isEmpty(Stack *stack) {
    return stack->tope == -1;
}

// Libera la memoria del stack
void liberarStack(Stack *stack) {
    free(stack->datos);
}
