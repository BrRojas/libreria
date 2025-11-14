#pragma once
#include <string>
class Socio{
    private:
        int IdSocio;
        char Nombre [30];
        char Categoria[30];
        char Telefono[15];
        char Estado;
        char IncluyeDonacion;
    public:
        Socio();
        void setIdSocio(int);
        void setNombre(const char*);
        void setCategoria(char*);
        void setTelefono(char*);
        void setEstado(char);
        void setIncluyeDonacion(char);
        int getIdSocio();
        const char* getNombre();
        char *getCategoria();
        char *getTelefono();
        char getEstado();
        char getIncluyeDonacion();

};
