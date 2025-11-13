#include "Betados.h"
#include <iostream>
#include <cstring>
using namespace std;

Vetados::Vetados() {
    IdVetados = 0;
}

void Vetados::setIdVetados(int id) {
  if(id > 0) {
        IdVetados = id;
    } else {
        cout << "ID inválido. Debe ser mayor que 0." << endl;
        IdVetados = 0;
    }
}


int Vetados::getIdVetados (){
    return IdVetados;
    }

