#pragma once
#include "Libro.h"
#include <cstring>

class Libro {
    private:
        char[20] isbn;
        char[35] genero;
        char[40] titulo;
        char[35] editorial;
        int cantidadEjemplares;
        int vecesPrestado;
        bool estado;
        int idAutor;

    public:
        Libro(char[20] isbn, char[35] genero, char[40] titulo, char[35] editorial, int cantidadEjemplares, int vecesPrestado, bool estado, int idAutor);
        char[20] getIsbn();
        char[35] getGenero();
        char[40] getTitulo();
        char[35] getEditorial();
        int getCantidadEjemplares();
        int getVecesPrestado();
        bool getEstado();
        int getIdAutor();

        void setIsbn(char[20] isbn);
        void setGenero(char[35] genero);
        void setTitulo(char[40] titulo);
        void setEditorial(char[35] editorial);
        void setCantidadEjemplares(int cantidadEjemplares);
        void setVecesPrestado(int vecesPrestado);
        void setEstado(bool estado);
        void setIdAutor(int idAutor);
        
};