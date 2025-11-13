#pragma once
#include <string>
#include "Betados.h"

class VetadosManager{
    private:
        Vetados vetado;
    public:
        void CargarVetados();
        void MostrarVetados();
        void BuscarPorID();
};
