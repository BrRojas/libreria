#include "Libro.h"
#include <cstring>
#include <iostream>

using namespace std;
    Libro::Libro(){
        return;
    }

    void Libro::cargar(){
        char isbn[20], genero[35], titulo[40], editorial[35];
        int cantidadEjemplares, vecesPrestado, idAutor;
        bool estado;


        cout << "Ingrese el ID del Autor: ";
        cin >> idAutor;
        cin.ignore();
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

        setIsbn(isbn);
        setGenero(genero);
        setTitulo(titulo);
        setEditorial(editorial);
        setCantidadEjemplares(cantidadEjemplares);
        setVecesPrestado(vecesPrestado);
        setEstado(estado);
        setIdAutor(idAutor);

        int idNuevo = 1;
        FILE *p = fopen("libros.dat", "rb");
        if(p != NULL) {
            fseek(p, 0, SEEK_END);
            idNuevo = ftell(p) / sizeof(Libro) + 1;
            fclose(p);
        }

        setId(idNuevo);

        FILE* archivo = fopen("libros.dat", "ab");
        
        if(archivo == NULL) {
            cout << "No se pudo abrir el archivo de libros" << endl;
            return;
        }

        if(fwrite(this, sizeof(Libro), 1, archivo) != 1) {
            cout << "Error intentando agregar el libro." << endl;
            return;
        }
        fclose(archivo);

        return;
    }


    void Libro::mostrar() {
        int id;
        cout << endl <<"Ingresar el id del libro: ";
        cin >> id;

        FILE *p = fopen("libros.dat", "rb");
        while(id == 0) {
            cout << endl << "Ingresar una id valida: ";
            cin >> id;
        }
        
            FILE* archivo = fopen("libros.dat", "rb");
            if(archivo == nullptr) {
                cout << "No hay ningun libro agregado hasta el momento" << endl;
                return;
            }


                Libro aux;
                bool encontrado = false;
                while(fread(&aux,sizeof(Libro), 1, archivo ) == 1) {
                    if(aux.getId() == id) {
                        encontrado = true;
                        libroAux(aux);
                        break;
                    }
                }

                fclose(archivo);

                if(!encontrado) {
                    cout << "No encontramos el libro que buscaba" << endl;
                }
                
            
            
    }

    void Libro::mostrarLibros() {
        FILE* archivo = fopen("libros.dat", "rb");
        if(archivo != nullptr) {
            cout << "Lista de libros" << endl;
            Libro aux;
            while(fread(&aux, sizeof(Libro), 1, archivo) == 1) {
                libroAux(aux);
            }
            fclose(archivo);
        } else {
            cout << "No se pudo abrir el archivo por lo que no hay libros." << endl;
        }
    }

    //borrar libro function


    void Libro::libroAux(Libro aux) {
        cout << endl << "ID: " << aux.id << endl;
        cout << "Titulo: " << aux.titulo << endl;
        cout << "Autor: " << aux.idAutor << endl;
        cout << "ISBN: " << aux.isbn << endl;
        cout << "Genero: " << aux.genero << endl;
        cout << "Editorial: " << aux.editorial << endl;
        cout << "Cantidad de ejemplares: " << aux.cantidadEjemplares << endl;
        cout << "Veces Prestado: " << aux.vecesPrestado << endl;
        cout << "Estado: " << aux.estado << endl;
    }
// Getters

    char* Libro::getIsbn() {
        return isbn;
    }

    int Libro::getId(){
        return idAutor;
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
