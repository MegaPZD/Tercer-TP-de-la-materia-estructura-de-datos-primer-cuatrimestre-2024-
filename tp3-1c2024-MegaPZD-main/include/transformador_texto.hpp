#ifndef TP1_1C2024_TRANSFORMADOR_HPP
#define TP1_1C2024_TRANSFORMADOR_TEXTO_HPP

#include <string>

class transformador_texto {

public:

    /*
        - Tranforma cualquier texto (string) en uno completamente
        - escrito en mayusculas (independientemente de si este
        - tuviera ya algunas) y remplaza los 'space' por '_'.
    */
    static std::string transformador_minuscula_mayuscula(std::string);

};

#endif