#pragma once
#include <cstring>

class Libro {
    private:
        char isbn[20], genero[35], titulo[40], editorial[35];
        int cantidadEjemplares, id, idAutor, vecesPrestado;
        bool estado;

    public:
        Libro();
        char* getIsbn();
        int getId();
        char* getGenero();
        char* getTitulo();
        char* getEditorial();
        int getCantidadEjemplares();
        int getVecesPrestado();
        bool getEstado();
        int getIdAutor();

        void setIsbn(char* isbn);
        void setId(int id);
        void setGenero(char* genero);
        void setTitulo(char* titulo);
        void setEditorial(char* editorial);
        void setCantidadEjemplares(int cantidadEjemplares);
        void setVecesPrestado(int vecesPrestado);
        void setEstado(bool estado);
        void setIdAutor(int idAutor);

};
