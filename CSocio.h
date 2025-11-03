#pragma once
#include <string>
class Socio{
    private:
        int IdSocio;
        char Categoria[30];
        char Telefono[15];
        bool Estado;
        bool IncluyeDonacion;
    public:
        Socio();
        void setIdSocio(int);
        void setCategoria(char*);
        void setTelefono(char*);
        void setEstado(bool);
        void setIncluyeDonacion(bool);
        int getIdSocio();
        char *getCategoria();
        char *getTelefono();
        bool getEstado();
        bool getIncluyeDonacion();
        void Cargar();
        void Mostrar();
};
