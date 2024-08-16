#include "menu.hpp"

menu::menu(std::string id_usuario, std::string nombre_armamento) : armamento(id_usuario, nombre_armamento), combate_menu(){
    // Constructor por defecto, inicializado así para que el constructor
    // armamento no se ejecute 2 veces (se inicializa como atributo en la clase).
}

menu::menu(std::string nombre_archivo) : armamento(nombre_archivo), combate_menu() {
    // Constructor con el nombre de archivo, inicializado así para que el constructor
    // armamento no se ejecute 2 veces (se inicializa como atributo en la clase).
}

void menu::menu_combates(){
    size_t eleccion = 0;
    std::cout << "MENU COMBATE:\nAgregar combate uno (1)\nPelear dos (2)\nSALIR (3)\n";
    do{
        std::cout << "Usted elige: ";
        std:: cin >> eleccion;
        std::cout << "\n";
        if(eleccion > FIN_COMBATE){
            std::cout << "Opción no valida, vuelva a elegir...\n";
        }
    }while(eleccion > FIN_COMBATE);
    system("clear");
    if(eleccion != FIN_COMBATE){
        administrador_combate::gestor_opcion_combate(&combate_menu, eleccion);
    }
}

void menu::menu_artefactos(){
    size_t eleccion = 0;
    std::cout << "MENU ARTEFACTOS:\nSí quiere agregar un artefacto manualmente ingrese uno (1)\nMostrar todos los artefactos dos (2)\nMostrar artefacto actual tres (3)\nMostrar artefacto siguiente cuatro(4)\nMostrar artefacto anterior cinco (5)\nBorrar artefacto actual seis (6)\nExportar artefactos a un archivo siete (7)\nSALIR ocho (8)\nNota: sí se 4 y 5 actual pasará a ser su siguiente o su anterior respectivamente.\n";
    do{
    std::cout << "Usted elige: ";
    std:: cin >> eleccion;
    std::cout << "\n";
    if(eleccion > FIN_ARTEFACTOS){
        std::cout << "Opción no valida, vuelva a elegir...\n";
    }
    }while(eleccion > FIN_ARTEFACTOS);
    system("clear");
    if(eleccion != FIN_ARTEFACTOS){
        administrador_artefactos::gestor_opcion_artefacto(&armamento,eleccion);
    }
    
}

void menu::menu_general(){
    size_t eleccion = 0;
    while(eleccion != FIN_GENERAL){
        
        std::cout << "Menu debug!! Este menu conecta 2 mecanicas que usted debe probar:\nCreación de artefactos y combate.\nSe le permitirá crearlos y gestionarlos de manera simple.\n";
        do{
        std::cout << "Opción 1: Artefactos\nOpción 2: combate\nOpción 3: SALIR\nUsted elige (uno (1), dos (2) o tres (3)): ";
        std:: cin >> eleccion;
        std::cout << "\n";
        if(eleccion > FIN_GENERAL){
            std::cout << "Opción no valida, vuelva a elegir...\n";
        }
        }while(eleccion > FIN_GENERAL);
        system("clear");
        if(eleccion == ARTEFACTO){
            menu_artefactos();
        } else if (eleccion == COMBATE)
        {
            menu_combates();
        }
    }
    
    
}