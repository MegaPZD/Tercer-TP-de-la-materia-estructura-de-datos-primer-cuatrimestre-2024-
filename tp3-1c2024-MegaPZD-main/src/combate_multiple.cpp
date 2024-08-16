#include "combate_multiple.hpp"
#include <iostream>
using namespace std;

combate_multiple::combate_multiple() : combates(){
    combates_realizados = 0;
}

void combate_multiple::agregar_combate(combate combate_recibido){
    if(combates_realizados < TOPE_COMBATES){
        cout << "Se va a agregar el combate numero: " << (combates_realizados+1) << endl;
        combates.alta(combate_recibido); // los combates realizados van del 0 al 5
        combates_realizados++;
    } else{
        cout << "No se pueden agregar más de 6 combates, resuelva (pelear()) los combates para agregar más" << endl;
    }
    

}

size_t combate_multiple::combate_recursivo(size_t cantidad_resina_gastada){
    if(combates.vacio()){
        return cantidad_resina_gastada;
    } else{
        combate combate_actual = combates.primero();
        cantidad_resina_gastada += combate_actual.obtener_poder_gastado();
        cout << "Se realiza el combate: piu piu, bang bang, elemental, ulti... ¡ganaste!" << endl;
        combates.baja();
    }
    return combate_recursivo(cantidad_resina_gastada);
    

}

size_t combate_multiple::pelear(){
    size_t cantidad_resina_gastada = combate_recursivo(0);
    
    combates_realizados = 0;

    return cantidad_resina_gastada;

}