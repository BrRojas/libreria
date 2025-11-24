#pragma once
#include "Libro.h"

class LibroManager {
public:
    void CargarLibro();
    void MostrarLibros();
    void BuscarIdLibro();
    void BorrarLibro();
    void LibroCout(Libro l);
};
