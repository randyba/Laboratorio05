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

// Insertar en una posición especifica
void insertarPosicionDoble(NodoDoble **cabeza, int dato, int posicion) {// pasamos como parametros el head, el dato y la posicion especifica

    if (posicion == 0) {// verificamos, en este caso es para insertar al inicio.
        insertarInicioDoble(cabeza, dato);// este es un ejemplo de callback, para insertar al inicio.
        return;
    }

    NodoDoble* actual = *cabeza;// buscamos la cabeza para luego recorrer.

    for (int i = 0; i < posicion - 1 && actual != NULL; i++) {// recorremos hasta encontar.
        actual = actual->siguiente;// cuando encuentra, se le asigna al siguinete.
    }

    if (actual == NULL) {//verificmps que no sea nulo el actual.
        printf("Posición fuera de rango.\n");
        return;
    }

    NodoDoble* nuevo = crearNodoDoble(dato);//entonces creamos el nodo con el dato.

    nuevo->siguiente = actual->siguiente;
    nuevo->anterior = actual;//le asignamos el nodo anterior al actual.

    if (actual->siguiente != NULL)// si no es nulo, asigna el nodo anterior al nuevo.
        actual->siguiente->anterior = nuevo;

    actual->siguiente = nuevo;// asignamos el nodo siguiente al nuevo.

}

//eliminar un elemento basado en la data
void eliminarDatoDoble(NodoDoble **cabeza, int dato) {
    NodoDoble* actual = *cabeza;

    while (actual != NULL && actual->dato != dato) {// recorremos la lista hasta encontrar el dato.
        actual = actual->siguiente;
    }

    if (actual == NULL) {// verificafr que se encuentea.
        printf("Dato no encontrado.\n");
        return;
    }

    if (actual->anterior != NULL)
        actual->anterior->siguiente = actual->siguiente;//asignamos el nodo siguiente al nodo anterior del actual.
    else
        *cabeza = actual->siguiente;//sino, asignamos el nodo siguiente al nodo head

    if (actual->siguiente != NULL)
        actual->siguiente->anterior = actual->anterior;//asignamos el nodo anterior al nodo siguiente del actual.

    free(actual);
}

//buscar un elemento
int buscarDatoDoble(NodoDoble *cabeza, int dato) {
    NodoDoble* actual = cabeza;// buscamos el head
    int posicion = 0;// deffinimos una variable para gguardar la posicion.

    while (actual != NULL) {// mientras sea valido.
        if (actual->dato == dato)//comenzamos a buscar la coincidencia.
            return posicion;// una ez enconada, retorna.

        actual = actual->siguiente;// y definimos que el nodo actual sea el siguiente.
        posicion++;// le sumamos uno a la posicion, para ir avanzando en la lista.
    }

    return -1; // No encontrado
}