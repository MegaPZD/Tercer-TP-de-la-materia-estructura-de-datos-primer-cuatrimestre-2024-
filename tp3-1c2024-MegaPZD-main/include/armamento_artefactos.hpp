#ifndef AYED_TP3_1C2024_ARMAMENTO_ARTEFACTOS_HPP
#define AYED_TP3_1C2024_ARMAMENTO_ARTEFACTOS_HPP
#include "artefacto.hpp"
#include "lista_circular.hpp"
#include <string>
#include <fstream>
#include <iostream>

const int TOPE_ARTEFACTOS = 6;
using namespace std;

class armamento_artefactos {
private:
    lista_circular<artefacto> recorrido_artefactos;
    size_t numero_artefactos;
    string UUID;
    string nombre_armamento;

    // Pre: Por enunciado el archivo respetará el formato pero para esta función
    // se requiere que el nombre sea UUID-nombre_armamento.extención.
    // Post: Incializa UUID y nombre_archivo con el path_archivo recibido en el
    // constructor(string).
    void nombre_archivo_a_UUID_y_nombre(string path_archivo);

    // Pre: -
    // Post: Sí artefacto1 tiene un ID igual a alguno de los artefactos de 
    // recorrido_artefactos retornará true, sino false.
    bool existe_repeticion_id(artefacto artefacto1);
public:
    //constructor
    armamento_artefactos(std::string id_usuario, std::string nombre_armamento);
    //constructor(string) recibe hasta 6 artefactos de un archivo.
    //Por convención de este TP, se asume que los archivos SIEMPRE
    //tendran el formato correcto (ID unico, 6 o menos artefactos,
    //orden del csv).
    armamento_artefactos(std::string path_archivo);

    // Pre: -
    // Post: Agrega el dato en la posición actual (cursor).
    // Solo agregará correctamente sí ID unico y menos de 6 artefactos, sino
    // se le hará saber al usuario.
    void agregar_artefacto(artefacto artefacto_a_agregar);

    // Pre: -
    // Post: Imprime el dato actual (cursor). Sí recorrido_artefactos esta
    // vacio no hace nada.
    void mostrar_artefacto_actual();

    // Pre: -
    // Post: Imprime el dato siguiente (siguiente al cursor) y avanza en uno
    // recorrido_artefactos, sí este esta vacio no hace nada.
    void mostrar_actefacto_siguiente();

    // Pre: -
    // Post: Imprime el dato anterior (anterior al cursor) y retrocede en uno
    // recorrido_artefactos, sí este vacio no hace nada.
    void mostrar_artefacto_anterior();

    // Pre: -
    // Post: Imprime todos los datos de la lista, desde el cursor hasta el
    // anterior de este. Sí recorrido_artefactos esta vacio no hace nada.
    void mostrar_artefactos();

    // Pre: -
    // Post: Elimina el artefacto actual (cursor). Sí recorrido_artefactos esta
    // vacio no hace nada.
    void quitar_artefacto();

    // Pre: -
    // Post: Este metodo guardará el armamento actual, con formato:
    // ID,SET,TIPO,NIVEL,RAREZA, en un archivo con formato UUID-nombre_armamento.csv.
    // Sí recorrido_artefactos esta vacio no hace nada.
    void exportar_armamento();

    // Pre: -
    // Post: Hace la converción de un string a tipo.
    // Sí str no es compatible con un enum valido, throw exception.
    // Nota: en el contexto del TP es imposible que se llegue a la throw exception
    // dado que esta función se utiliza en funciones donde como pre condición
    // se escoge un tipo correcto o en el constructor(string) donde por enunciado
    // siempre se respeta el formato.
    static tipo string_a_tipo(const std::string& str);

    // Pre: -
    // Post: Hace la converción de un string a rareza.
    // Sí str no es compatible con un enum valido, throw exception.
    // Nota: en el contexto del TP es imposible que se llegue a la throw exception
    // dado que esta función se utiliza en funciones donde como pre condición
    // se escoge una rareza correcta o en el constructor(string) donde por enunciado
    // siempre se respeta el formato.
    static rareza string_rareza(const std::string& str);

};

#endif