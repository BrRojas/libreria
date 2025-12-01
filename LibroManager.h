#pragma once
#include "Libro.h"
//se sobre escribio mal
class LibroManager {
public:
    void CargarLibro();
    void MostrarLibros();
    void BuscarIdLibro();
    void BorrarLibro();
    void LibroCout(Libro l);
    void EditarLibro();
    bool ManejarStock(int id, int cantidad);

    //reportes
    int CantidadLibrosConStock();
    int CantidadLibrosSinStock();
    void ReporteLibrosStock();

    //filtros
    void BuscarPorGenero();
    void BuscarPorTitulo();

};
