#pragma once
#include <string>
class Betados{
    private:
        int IdBetados;
        int RestaPuntos;
    public:
        Betados();
        void setIdBetados(int);
        void setRestaPuntos(int);
        int getIdBetados();
        int getRestaPuntos();
        void CargarBetados();
        void MostrarBetados();
};

