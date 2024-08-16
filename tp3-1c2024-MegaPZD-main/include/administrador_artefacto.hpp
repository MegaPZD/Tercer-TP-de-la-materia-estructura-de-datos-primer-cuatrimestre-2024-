#ifndef __ADMINISTRADOR__ARTEFACTOS__
#define __ADMINISTRADOR__ARTEFACTOS__

#include "menu.hpp"
#include "armamento_artefactos.hpp"

const size_t AGREGAR = 1;
const size_t MOSTRAR = 2;
const size_t ACTUAL = 3;
const size_t SIGUIENTE = 4;
const size_t ANTERIOR = 5;
const size_t BORRAR = 6;
const size_t EXPORTAR = 7;

class administrador_artefactos{
public:

    // Pre: Se debe ingresar: TIPO (1 A 6 inclusive) y RAREZA (3 A 5 inclusive).
    // Post: Agrega el dato en la posición actual (cursor).
    // Solo agregará correctamente sí ID unico y  menos de 6 artefactos, sino
    // se le hará saber al usuario.
    static void administrar_agregar_artefacto(armamento_artefactos* armamento);

    // Pre: -
    // Post: Imprime el dato actual (cursor). Sí la lista de armamento
    // esta vacia no hace nada.
    static void administrar_mostrar_artefacto_actual(armamento_artefactos* armamento);

    // Pre: -
    // Post: Imprime el dato siguiente (siguiente al cursor) y avanza en uno
    // la lista. Sí la lista de armamento esta vacia no hace nada.
    static void administrar_mostrar_actefacto_siguiente(armamento_artefactos* armamento);

    // Pre: -
    // Post: Imprime el dato anterior (anterior al cursor) y retrocede en uno
    // la lista. Sí la lista de armamento esta vacia no hace nada.
    static void administrar_mostrar_artefacto_anterior(armamento_artefactos* armamento);

    // Pre: -
    // Post: Imprime todos los datos de la lista, desde el cursor hasta el
    // el anterior de este. Sí la lista de armamento esta vacia no hace nada.
    static void administrar_mostrar_artefactos(armamento_artefactos* armamento);

    // Pre: -
    // Post: Elimina el artefacto actual (cursor). Sí la lista de armamento
    // esta vacia no hace nada.
    static void administrar_quitar_artefacto(armamento_artefactos* armamento);

    // Pre: -
    // Post: Este metodo guardará el armamento actual, con formato:
    // ID,SET,TIPO,NIVEL,RAREZA, en un archivo de nombre elegido por el
    // usuario. Sí la lista de armamento esta vacia no hace nada.
    static void administrar_exportar(armamento_artefactos* armamento);

    // Pre: La respuesta debe ser un numero del 1 al 7 (inclusive).
    // Post: Modifica el armamento recibido segun la respuesta recibida utilizando
    // un metodo de la serie de metodos ad, utilizando estas los metodos
    // de armamento_artefactos.hpp
    static void gestor_opcion_artefacto(armamento_artefactos* armamento, size_t respuesta);

    friend class menu;
};

#endif