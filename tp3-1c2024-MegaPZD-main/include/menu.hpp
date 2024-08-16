#ifndef _MENU_
#define _MENU_

#include <iostream>
#include <cstdlib>
#include "combate_multiple.hpp"
#include "armamento_artefactos.hpp"
#include "administrador_artefacto.hpp"
#include "administrador_combate.hpp"

const size_t ARTEFACTO = 1;
const size_t COMBATE = 2;
const size_t FIN_GENERAL = 3;
const size_t FIN_ARTEFACTOS = 8;
const size_t FIN_COMBATE = 3;

class menu {
private:
    armamento_artefactos armamento;
    combate_multiple combate_menu;
public:
    //constructor
    menu(std::string id_usuario, std::string nombre_armamento);
    //constructor donde armamento_artefactos se inicializa con parametros
    //recibidos desde un archivo.
    menu(std::string nombre_archivo);

    //Pre: -
    //Post: Menu que le da a elegir al usuario que metodo de combate_multiple
    //(utilizadas por administrador_combate) que quiere realizar o salir.
    //Sí el usuario ingresa una opcion incorrecta se le volverá a pedir ingresar
    //los datos haciendole saber tambien que se equivoco al ingresar.
    void menu_combates();

    //Pre: -
    //Post: Menu que le da a elegir al usuario que metodo de armamento_artefacto
    //(utilizadas por administrador_artefacto) que quiere realizar o salir.
    //Sí el usuario ingresa una opcion incorrecta se le volverá a pedir ingresar
    //los datos haciendole saber tambien que se equivoco al ingresar.
    void menu_artefactos();
    
    //Pre: -
    //Post: Menu que le da a elegir al usuario si quiere trabajar con
    //los artefactos, combate o salir. Sí el usuario ingresa una opcion incorrecta
    //se le volverá a pedir ingresar los datos haciendole saber tambien que se
    //equivoco al ingresar.
    void menu_general();

    friend class administrador_artefactos;
    friend class administrador_combate;
};

#endif