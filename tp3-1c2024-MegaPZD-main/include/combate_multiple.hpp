#ifndef AYED_TP3_1C2024_COMBATE_MULTIPLE_HPP
#define AYED_TP3_1C2024_COMBATE_MULTIPLE_HPP

#include "combate.hpp"
#include "cola.hpp"

const int TOPE_COMBATES = 6;

class combate_multiple {
private:
    size_t combates_realizados;
    cola<combate> combates;

    // función recursiva de pelear()
    // recursión de cola, directa, simple y con optimización TCO.
    // Pre: -
    // Post: Retorna el numero de Poder de Trazacamino gastado en el/los combates.
    size_t combate_recursivo(size_t cantidad_resina_gastada);
    
public:

    //constructor
    combate_multiple();

    /*
    Pre: No se pueden agregar más de 6 combates. 
    Post: agrega un combate a la cola combates.
    */
    void agregar_combate(combate combate_recibido);

    /*

    Pre: -
    Post: Retorna el numero de Poder de Trazacamino gastado en el/los combates.
    // Si no hay ningun combate retornará 0.
    La recursividad se hace de forma indirecta en combate_recursivo.
    */
    size_t pelear();
};

#endif