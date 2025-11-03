#ifndef AUTOR_H
#define AUTOR_H

#include "Fecha.h"

class Autor {
private:
    int idAutor;
    char nombre[40];
    char nacionalidad[30];
    Fecha fechaNacimiento;

public:
    Autor();
    Autor(int id, const char* nom, const char* nac, Fecha fNac);

    void cargar();
    void mostrar();

    void setIdAutor(int id);
    void setNombre(const char* nom);
    void setNacionalidad(const char* nac);
    void setFechaNacimiento(Fecha f);

    int getIdAutor();
    const char* getNombre();
    const char* getNacionalidad();
    Fecha getFechaNacimiento();
};

#endif
