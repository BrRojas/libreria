#include "Beneficios.h"
#include <iostream>
#include <cstring>
using namespace std;

int BeneficiosManager::MaxPrestamosSegunCategoria(const char* categoria) {
    if (strcmp(categoria, "Platino") == 0) return 5; // hacemos una comparacion
    if (strcmp(categoria, "Oro") == 0) return 3;     // para saber la categoria
    if (strcmp(categoria, "Plata") == 0) return 2;   // y el beneficio
//en el caso de bronce retorna nada mas.
    return 1;
}
