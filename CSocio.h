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
        int puntos;

    public:
        Socio();
        void setIdSocio(int);
        void setNombre(const char*);
        void setCategoria(const char* cat);
        void setTelefono(const char*);
        void setEstado(char);
        void setIncluyeDonacion(char);
        void setPuntos(int);

        int getIdSocio();
        const char* getNombre();
        const char *getCategoria();
        const char *getTelefono();
        char getEstado();
        char getIncluyeDonacion();
        int getPuntos();

};
