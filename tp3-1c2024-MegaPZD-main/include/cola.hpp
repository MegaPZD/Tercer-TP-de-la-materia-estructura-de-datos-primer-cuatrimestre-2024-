#ifndef AYED_TP3_1C2024_COLA_HPP
#define AYED_TP3_1C2024_COLA_HPP

#include <exception>
#include "nodo.hpp"

class cola_exception : public std::exception {
    // Excepción especifica y exclusiva para errores dentro de la cola.
    // Usar de la forma "throw cola_exception();" cuando una precondición no se cumple.

    // Ejemplo:
    //     if (condición_de_error) {
    //         throw cola_exception();
    //     }
};

template<typename T>
class cola {
private:
    nodo<T>* primer_nodo;
    nodo<T>* ultimo_nodo;
    size_t cantidad_datos;
public:
    // Constructor.
    cola();

    // Pre: -
    // Post: Agrega el dato al final de la cola.
    void alta(T dato);

    // Pre: La cola no puede estar vacía.
    // Post: Devuelve el primer dato de la cola.
    T primero();

    // Pre: La cola no puede estar vacía.
    // Post: Elimina y devuelve el primer dato de la cola.
    T baja();

    // Pre: -
    // Post: Devuelve la cantidad de datos de la cola.
    size_t tamanio();

    // Pre: -
    // Post: Devuelve true si la cola esta vacía.
    bool vacio();

    // El constructor de copia está deshabilitado.
    cola(const cola& c) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const cola& c) = delete;

    // Destructor.
    ~cola();
};

template<typename T>
cola<T>::cola() {
    primer_nodo = nullptr;
    ultimo_nodo = nullptr;
    cantidad_datos = 0;
}

template<typename T>
void cola<T>::alta(T dato) {
    nodo<T>* nodo_nuevo = new nodo<T>(dato);
    if(vacio()){
        primer_nodo = nodo_nuevo;
        ultimo_nodo = nodo_nuevo;
    } else {
        ultimo_nodo->siguiente = nodo_nuevo;
        nodo_nuevo->anterior = ultimo_nodo;
        ultimo_nodo = nodo_nuevo;
    }
    cantidad_datos++;
}

template<typename T>
T cola<T>::primero() {
    if(vacio()){
        throw cola_exception();
    } else {
        return primer_nodo->dato;
    }
}

template<typename T>
T cola<T>::baja() {
    if(vacio()){
        throw cola_exception();
    }else{
        nodo<T>* nodo_aux = primer_nodo;
        T dato_eliminado = nodo_aux->dato;
        primer_nodo = primer_nodo->siguiente;
        delete nodo_aux;
        if(primer_nodo != nullptr){
            primer_nodo->anterior = nullptr;
        }
        cantidad_datos--;
        return dato_eliminado;
    }
}

template<typename T>
size_t cola<T>::tamanio() {
    return cantidad_datos;
}

template<typename T>
bool cola<T>::vacio() {
    return cantidad_datos == 0;
}

template<typename T>
cola<T>::~cola() {
    while(!vacio()){
        baja();
    }
}

#endif