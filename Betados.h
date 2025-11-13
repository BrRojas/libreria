#pragma once
#include <string>
class Vetados{
    private:
        int IdVetados;
        int RestaPuntos;
    public:
        Vetados();
        void setIdVetados(int);
        void setRestaPuntos(int);
        int getIdVetados();
        int getRestaPuntos();
        void CargarVetados();
        void MostrarVetados();
};
