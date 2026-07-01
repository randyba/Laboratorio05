#include <stdio.h>
#include <stdlib.h>
#include "ListaDoblementeEnlazada.h"

// Crear un nuevo nodo doble

NodoDoble* crearNodoDoble(int dato) {
    NodoDoble* nuevo = (NodoDoble*)malloc(sizeof(NodoDoble));//reserva de la memoria

    if (nuevo == NULL) {//verificacion de la memoria, que tenga sentido
        printf("Error al reservar memoria.\n");
        return NULL;
    }

    nuevo->dato = dato;//el dato que guarde en el nodo
    nuevo->siguiente = NULL;// dejamos previsto que el siguiente nodo sea nulo
    nuevo->anterior = NULL;// de igual manera el nodo anterior sea nulo

    return nuevo;
}

// Insertar al inicio
void insertarInicioDoble(NodoDoble **cabeza, int dato) {
    NodoDoble* nuevo = crearNodoDoble(dato);

    if (nuevo == NULL)
        return;

    nuevo->siguiente = *cabeza;

    if (*cabeza != NULL)
        (*cabeza)->anterior = nuevo;

    *cabeza = nuevo;
}

// Insertar al final
void insertarFinalDoble(NodoDoble **cabeza, int dato) {

    NodoDoble* nuevo = crearNodoDoble(dato);// se crea un nuevo nodo doble

    if (nuevo == NULL)//verifica que este nodo no sea nulo
        return;

    if (*cabeza == NULL) {//verifica si el nodo cabeza es nulo, si es asi se le asigna el nuevo 
        *cabeza = nuevo;
        return;
    }

    NodoDoble* actual = *cabeza;//se crea un nodo actual que apunta al nodo cabeza

    while (actual->siguiente != NULL) {//verifica que el siguiente tenga donde apuntar.
        actual = actual->siguiente;
    }

    actual->siguiente = nuevo;
    nuevo->anterior = actual;
}