#ifndef STACK_H
#define STACK_H

/*
Stack.h
IE-0117 Laboratorio 05

Archivo de encabezado para la implementación del Stack.
*/

// Estructura del Stack
typedef struct {
    int *datos;
    int tope;
    int capacidad;
} Stack;

// Prototipos de funciones
void inicializarStack(Stack *stack, int capacidad);
void push(Stack *stack, int valor);
int pop(Stack *stack);
int peek(Stack *stack);
int isEmpty(Stack *stack);
void liberarStack(Stack *stack);

#endif
