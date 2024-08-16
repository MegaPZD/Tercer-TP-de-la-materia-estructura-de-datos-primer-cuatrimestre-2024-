#ifndef __ADMINISTRADOR__COMBATE__
#define __ADMINISTRADOR__COMBATE__

#include "menu.hpp"
#include "combate_multiple.hpp"

const size_t AGREGAR_COMBATE = 1;
const size_t PELEAR = 2;

class administrador_combate{
public:

    /*
    Pre: Para la creación de combate se debe ingresar: DESCRIPCIÓN(string),
    // ENEMIGOS(size_t), CANTIDAD_PODER_GASTADO(size_t)
    Post: Agrega un combate a la cola de combate_menu.
    No se pueden agregar más de 6 combates.
    */
    static void administrar_agregar_combate(combate_multiple* combate_menu);

    /*
    Pre: -
    Post: Imprime el numero de Poder de Trazacamino gastado en el/los combates.
    Si no hay ningun combate retornará 0.
    */
    static size_t administrar_pelear(combate_multiple* combate_menu);

    // Pre: La respuesta debe ser un numero del 1 al 2 (inclusive).
    // Post: Modifica el combate_menu recibido segun la respuesta recibida utilizando
    // un metodo de la serie de metodos ad, utilizando estas los metodos
    // de combate_multiple.hpp
    static void gestor_opcion_combate(combate_multiple* combate_menu, size_t respuesta);

    friend class menu;


};

#endif