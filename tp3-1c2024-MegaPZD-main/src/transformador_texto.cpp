#include "transformador_texto.hpp"

std::string transformador_texto::transformador_minuscula_mayuscula(std::string mensaje){

    int longitud = (int)mensaje.length();
    std::string aux_cadena = "";

    for(int i = 0; i < longitud; i++){
        if(mensaje[i] == ' '){
            aux_cadena += '_';
        } else{
            aux_cadena += (char)(std::toupper(mensaje[i]));
        }
    }

    mensaje = aux_cadena;

    return mensaje;

}