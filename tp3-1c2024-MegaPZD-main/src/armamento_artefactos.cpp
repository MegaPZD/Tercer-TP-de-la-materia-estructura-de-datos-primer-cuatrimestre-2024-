#include "armamento_artefactos.hpp"

armamento_artefactos::armamento_artefactos(std::string id_usuario, std::string nombre_armamento) : recorrido_artefactos(){

    UUID = id_usuario;
    this->nombre_armamento = nombre_armamento;
    numero_artefactos = 0;
}

armamento_artefactos::armamento_artefactos(std::string path_archivo) : recorrido_artefactos(){
    
    nombre_archivo_a_UUID_y_nombre(path_archivo);
    numero_artefactos = 0;
    
    ifstream archivo(path_archivo);
    if(!(archivo.is_open())){
        throw std::invalid_argument("No existe archivo");
    } else{
        string linea = "\0";
        int id{};
        string set;
        tipo tipo1{};
        int nivel{};
        rareza rareza1{};

        while (getline(archivo, linea, ','))
        {
            id = stoi(linea);
            getline(archivo, linea, ',');
            set = linea;
            getline(archivo, linea, ',');
            tipo1 = string_a_tipo(linea);
            getline(archivo, linea, ',');
            nivel = stoi(linea);
            getline(archivo, linea, '\n');
            rareza1 = string_rareza(linea);

            artefacto artefacto_aux(id, set, tipo1, nivel, rareza1);
            recorrido_artefactos.alta(artefacto_aux);
            numero_artefactos = recorrido_artefactos.tamanio();
        }
        archivo.close();
    }
}

tipo armamento_artefactos::string_a_tipo(const std::string& str) {
    if (str == "1") {
        return tipo::CABEZA;
    } else if (str == "2") {
        return tipo::MANOS;
    } else if (str == "3") {
        return tipo::TORSO;
    } else if (str == "4") {
        return tipo::PIERNAS;
    } else if (str == "5") {
        return tipo::ESFERA_PLANAR;
    } else if (str == "6") {
        return tipo::PISTA_DE_LUZ;
    } else {
        throw std::invalid_argument("Cadena no válida para el enum Tipo");
    }
}

rareza armamento_artefactos::string_rareza(const std::string& str) {
    if (str == "3") {
        return rareza::TRES_ESTRELLAS;
    } else if (str == "4") {
        return rareza::CUATRO_ESTRELLAS;
    } else if (str == "5") {
        return rareza::CINCO_ESTRELLAS;
    } else {
        throw std::invalid_argument("Cadena no válida para el enum Tipo");
    }
}

void armamento_artefactos::nombre_archivo_a_UUID_y_nombre(std::string path_archivo){

    size_t posicion_guion = path_archivo.find('-');
    size_t posicion_punto = path_archivo.find('.');
    UUID = path_archivo.substr(0, posicion_guion);
    nombre_armamento = path_archivo.substr(posicion_guion+1, posicion_punto - posicion_guion - 1);

}

bool armamento_artefactos::existe_repeticion_id(artefacto artefacto1){

    bool se_repitio = false;
    size_t contador = 0;
    while (se_repitio != true && contador < numero_artefactos)
    {
        if(artefacto1 == recorrido_artefactos.actual()){
            se_repitio = true;
        }
        recorrido_artefactos.avanzar();
        contador++;
    }
    
    return se_repitio;

}

void armamento_artefactos::agregar_artefacto(artefacto artefacto_a_agregar){
    if(numero_artefactos < TOPE_ARTEFACTOS){
        if(!existe_repeticion_id(artefacto_a_agregar)){
            recorrido_artefactos.alta(artefacto_a_agregar);
            numero_artefactos = recorrido_artefactos.tamanio();
        } else{
            cout << "ERROR: Se esta intentando agregar un artefacto con un ID repetido, intentelo de nuevo...\n" << endl;
        }
        
    } else{
        cout << "ERROR: No se pueden agregar más de 6 artefactos, elimine uno para agregar correctamente\n" << endl;
    }
}

void armamento_artefactos::mostrar_artefacto_actual(){
    if(!(recorrido_artefactos.vacio())){
        cout << recorrido_artefactos.actual() << endl;
    }
}
void armamento_artefactos::mostrar_actefacto_siguiente(){
    if(!(recorrido_artefactos.vacio())){
        recorrido_artefactos.avanzar();
        cout << recorrido_artefactos.actual() << endl;
    }
}
void armamento_artefactos::mostrar_artefacto_anterior(){
    if(!(recorrido_artefactos.vacio())){
        recorrido_artefactos.retroceder();
        cout << recorrido_artefactos.actual() << endl;
    }
    
}
void armamento_artefactos::mostrar_artefactos(){
    if(!(recorrido_artefactos.vacio())){
        mostrar_artefacto_actual();
        for(size_t i = 0; i < numero_artefactos-1; i++){
            mostrar_actefacto_siguiente();
        }
    }
    
}
void armamento_artefactos::quitar_artefacto(){
    if(!(recorrido_artefactos.vacio())){
        recorrido_artefactos.baja();
        numero_artefactos--;
    }
}
void armamento_artefactos::exportar_armamento(){
    if (!(recorrido_artefactos.vacio())) {
        string nombre_archivo = UUID + "-" + nombre_armamento + ".csv";
        
        ofstream archivo(nombre_archivo);
        if (!archivo) {
            cout << "Por algun motivo no se pudo crear el archivo necesario para la ejecución de este metodo.\nAlgunos motivos podrian ser:\n\tSe haya borrado el archivo en medio de la ejecución\n\tNo se tienen los permisos para modificar la carpeta donde se ejecuta ese programa\n\tNo hay espacio suficiente en memoria para agregar este archivo\n";
        } else{
            for(size_t i = 0; i < numero_artefactos; i++){
                archivo << recorrido_artefactos.actual() << endl;
                recorrido_artefactos.avanzar();
            }
        }

        archivo.close();
    }
}