#include "administrador_artefacto.hpp"
#include <fstream>
#include "artefacto.hpp"
void administrador_artefactos::administrar_agregar_artefacto(armamento_artefactos* armamento){

    int id{};
    string set;
    string tipo1;
    int nivel{};
    string rareza1{};
    std::cout << "Creación de artefacto (ID,SET(string), TIPO(1 A 6), NIVEL(Int),RAREZA(3 A 5)) \n";
    std::cout << "ID: ";
    std:: cin >> id;
    std::cout << "\n";
    std::cin.ignore();
    std::cout << "SET: ";
    getline(std::cin, set);
    std::cout << "\n";
    std::cout << "TIPO: ";
    std:: cin >> tipo1;
    std::cout << "\n";
    std::cin.ignore();
    std::cout << "NIVEL: ";
    std:: cin >> nivel;
    std::cout << "\n";
    std::cin.ignore();
    std::cout << "RAREZA: ";
    std:: cin >> rareza1;
    std::cout << "\n";

    artefacto aux_artefacto(id,set,armamento_artefactos::string_a_tipo(tipo1), nivel, armamento_artefactos::string_rareza(rareza1));
    armamento->agregar_artefacto(aux_artefacto);
}

void administrador_artefactos::administrar_mostrar_artefactos(armamento_artefactos* armamento){
    armamento->mostrar_artefactos();
    std::cout << std::endl;
}

void administrador_artefactos::administrar_mostrar_artefacto_actual(armamento_artefactos* armamento){
    armamento->mostrar_artefacto_actual();
    std::cout << std::endl;
}

void administrador_artefactos::administrar_mostrar_actefacto_siguiente(armamento_artefactos* armamento){
    armamento->mostrar_actefacto_siguiente();
    std::cout << std::endl;
}

void administrador_artefactos::administrar_mostrar_artefacto_anterior(armamento_artefactos* armamento){
    armamento->mostrar_artefacto_anterior();
    std::cout << std::endl;
}

void administrador_artefactos::administrar_quitar_artefacto(armamento_artefactos* armamento){
    armamento->quitar_artefacto();
    std::cout << std::endl;
}

void administrador_artefactos::administrar_exportar(armamento_artefactos* armamento){
    armamento->exportar_armamento();
    std::cout << std::endl;
}

void administrador_artefactos::gestor_opcion_artefacto(armamento_artefactos* armamento, size_t respuesta){

    if(respuesta == AGREGAR){
        administrar_agregar_artefacto(armamento);
    } else if(respuesta == MOSTRAR){
        administrar_mostrar_artefactos(armamento);
    } else if(respuesta == ACTUAL){
        administrar_mostrar_artefacto_actual(armamento);
    } else if(respuesta == SIGUIENTE){
        administrar_mostrar_actefacto_siguiente(armamento);
    } else if(respuesta == ANTERIOR){
        administrar_mostrar_artefacto_anterior(armamento);
    } else if(respuesta == BORRAR){
        administrar_quitar_artefacto(armamento);
    } else if(respuesta == EXPORTAR){
        administrar_exportar(armamento);
    }
}