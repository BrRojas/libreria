#include "Libro.h"
#include <cstring>
#include <iostream>

using namespace std;
    Libro::Libro(){
        return;
    }

    int Libro::Cargar()	{
        char isbn[20], genero[35], titulo[40], editorial[35];
        int cantidadEjemplares, vecesPrestado, idAutor;
        bool estado;
        cout << "Ingrese el ISBN: ";
        cin.getline(isbn, 20);
        cout << "Ingrese el Genero: ";
        cin.getline(genero, 35);
        cout << "Ingrese el Titulo: ";
        cin.getline(titulo, 40);
        cout << "Ingrese la Editorial: ";
        cin.getline(editorial, 35);
        cout << "Ingrese la Cantidad de Ejemplares: ";
        cin >> cantidadEjemplares;
        cout << "Ingrese la Cantidad de Veces Prestado: ";
        cin >> vecesPrestado;
        cout << "Ingrese el Estado (1 para activo, 0 para inactivo): ";
        cin >> estado;
        cout << "Ingrese el ID del Autor: ";
        cin >> idAutor;

        setIsbn(isbn);
        setGenero(genero);
        setTitulo(titulo);
        setEditorial(editorial);
        setCantidadEjemplares(cantidadEjemplares);
        setVecesPrestado(vecesPrestado);
        setEstado(estado);
        setIdAutor(idAutor);
        return 0;
    }


    void Libro::mostrar() {
        cout << "ISBN: " << getIsbn() << endl;
        cout << "Genero: " << getGenero() << endl;
        cout << "Titulo: " << getTitulo() << endl;
        cout << "Editorial: " << getEditorial() << endl;
        cout << "Cantidad de Ejemplares: " << getCantidadEjemplares() << endl;
        cout << "Veces Prestado: " << getVecesPrestado() << endl;
    }

    void Libro::MostrarLibros() {
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
    void Libro::setIsbn(char* isbn)
    {
        strcpy(this->isbn, isbn);
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
