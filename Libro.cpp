#include "Libro.h"
#include <cstring>
#include <iostream>

using namespace std;
    Libro::Libro(){
        return;
    }

// Getters

    char* Libro::getIsbn() {
        return isbn;
    }

    int Libro::getId(){
        return id;
    }

    char* Libro::getGenero(){
        return genero;
    }
    char* Libro::getTitulo(){
        return titulo;
    }
    char* Libro::getEditorial(){
        return editorial;
    }
    int Libro::getCantidadEjemplares(){
        return cantidadEjemplares;
    }
    int Libro::getVecesPrestado(){
        return vecesPrestado;
    }
    bool Libro::getEstado(){
        return estado;
    }
    int Libro::getIdAutor(){
        return idAutor;
    }

// Setters

    void Libro::setIsbn(char* isbn)
    {
        strcpy(this->isbn, isbn);
    }
    
    void Libro::setId(int id) {
        this->id = id;
    }

    void Libro::setGenero(char* genero)
    {
        strcpy(this->genero, genero);
    }

    void Libro::setTitulo(char* titulo)
    {
        strcpy(this->titulo, titulo);
    }

    void Libro::setEditorial(char* editorial)
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
