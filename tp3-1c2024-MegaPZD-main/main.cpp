#include <iostream>
#include "cola.hpp"
#include "lista_circular.hpp"
#include "combate_multiple.hpp"
#include "combate.hpp"
#include "armamento_artefactos.hpp"
#include "menu.hpp"
#include "transformador_texto.hpp"
#include <string>

int main() {

    char respuesta;
    std::cout << "¿Tiene artefactos exportados a un archivo? S o N (si no se elige correctamente no se hará nada...): ";
    std::cin >> respuesta;
    std::cout << std::endl;

    if(respuesta == 'S'){
        std::string nombre_archivo = "\0";
        std::cout << "Ingrese el nombre y extención de ese archivo (archivo.extención): ";
        std::cin >> nombre_archivo;
        std::cout << std::endl;
        menu menu(nombre_archivo);
        menu.menu_general();
    } else if(respuesta == 'N'){
        std::string id_usuario;
        std::string nombre_armamento;
        cout << "ingrese su UUID (Numero entero positivo de 8 digitos): ";
        cin >> id_usuario;
        cout << endl;
        cin.ignore();
        cout << "ingrese el nombre del armamento que quiere crear: ";
        getline(cin, nombre_armamento);
        cout << endl;
        menu menu(id_usuario, transformador_texto::transformador_minuscula_mayuscula(nombre_armamento));
        menu.menu_general();
    }

    return 0;
}