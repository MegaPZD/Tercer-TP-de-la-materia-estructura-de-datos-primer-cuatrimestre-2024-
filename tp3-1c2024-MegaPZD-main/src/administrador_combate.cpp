#include "administrador_combate.hpp"

void administrador_combate::administrar_agregar_combate(combate_multiple* combate_menu){

    string descripcion;
    size_t enemigos;
    size_t poder_gastado;
    std::cout << "Creación de combate (DESCRIPCIÓN(string),ENEMIGOS(size_t),CANTIDAD_PODER_GASTADO(size_t))\n";
    std::cout << "DESCRIPCIÓN: ";
    std::cin.ignore();
    getline(std::cin, descripcion);
    std::cout << "\n";
    std::cout << "ENEMIGOS: ";
    std::cin >> enemigos;
    std::cout << "\n";
    std::cout << "PODER GASTADO: ";
    std::cin >> poder_gastado;
    std::cout << "\n";

    combate aux_combate(descripcion, enemigos, poder_gastado);
    combate_menu->agregar_combate(aux_combate);

}

size_t administrador_combate::administrar_pelear(combate_multiple* combate_menu){

    size_t poder_gastado = combate_menu->pelear();
    std::cout << std::endl;
    std::cout << "Se gasto: " << poder_gastado << " poder trazacaminos\n";
    std::cout << std::endl;
    return poder_gastado;

}

void administrador_combate::gestor_opcion_combate(combate_multiple* combate_menu, size_t respuesta){

    if(respuesta == AGREGAR_COMBATE){
        administrar_agregar_combate(combate_menu);
    } else if(respuesta == PELEAR){
        administrar_pelear(combate_menu);
    }

}
