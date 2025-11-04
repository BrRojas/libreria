#include "Libro.h"
#include <cstring>

// Constructor

Libro::Libro(char[20] isbn, char[35] genero, char[40] titulo, char[35] editorial, int cantidadEjemplares, int vecesPrestado, bool estado, int idAutor)
{
    setIsbn(isbn);
    setGenero(genero);
    setTitulo(titulo);
    setEditorial(editorial);
    setCantidadEjemplares(cantidadEjemplares);
    setVecesPrestado(vecesPrestado);
    setEstado(estado);
    setIdAutor(idAutor);
}

// Getters

    char* Libro::getIsbn() {
        return this->isbn;
    }

    char* Libro::getGenero(){   
        return this->genero;
    }
    char* Libro::getTitulo(){
        return this->titulo;
    }
    char* Libro::getEditorial(){
        return this->editorial;
    }
    int Libro::getCantidadEjemplares(){
        return this->cantidadEjemplares;
    }
    int Libro::getVecesPrestado(){
        return this->vecesPrestado;
    }
    bool Libro::getEstado(){
        return this->estado;
    }
    int Libro::getIdAutor(){
        return this->idAutor;
    }



// Setters
    void Libro::setIsbn(char[20] isbn)
    {
        strcpy(this->isbn, isbn);
    }

    void Libro::setGenero(char[35] genero)
    {
        strcpy(this->genero, genero);
    }

    void Libro::setTitulo(char[40] titulo)
    {
        strcpy(this->titulo, titulo);
    }

    void Libro::setEditorial(char[35] editorial)
    {
        strcpy(this->editorial, editorial);
    }

    void Libro::setCantidadEjemplares(int cantidadEjemplares)
    {
        this->cantidadEjemplares = cantidadEjemplares;
    }

    void Libro::setVecesPrestado(int vecesPrestado)
    {
        this->vecesPrestado = vecesPrestado;
    }

    void Libro::setEstado(bool estado)
    {
        this->estado = estado;
    }

    void Libro::setIdAutor(int idAutor)
    {
        this->idAutor = idAutor;    
    }