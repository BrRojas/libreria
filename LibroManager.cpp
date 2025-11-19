#include <iostream>
#include <cstdio>
#include "LibroManager.h"
using namespace std;


void LibroManager::CargarLibro() {
    Libro l;

    char isbn[20], genero[35], titulo[40], editorial[35];
    int cantidadEjemplares, vecesPrestado, idAutor, idNuevo = 1;
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

    l.setIsbn(isbn);
    l.setGenero(genero);
    l.setTitulo(titulo);
    l.setEditorial(editorial);
    l.setCantidadEjemplares(cantidadEjemplares);
    l.setVecesPrestado(vecesPrestado);
    l.setEstado(estado);
    l.setIdAutor(idAutor);

    FILE *p = fopen("libros.dat", "rb");
    if(p != NULL) {
        fseek(p, 0, SEEK_END);
        idNuevo = ftell(p) / sizeof(Libro) + 1;
        fclose(p);
    }

    l.setId(idNuevo);

    FILE* archivo = fopen("libros.dat", "ab");
    
    if(archivo == NULL) {
        cout << "No se pudo abrir el archivo de libros" << endl;
        return;
    }

    if(fwrite(&l, sizeof(Libro), 1, archivo) != 1) {
        cout << "Error intentando agregar el libro." << endl;
        return;
    }
    fclose(archivo);

    cout << "Libro guardado correctamente." << endl;
    return;
}

void LibroManager::MostrarLibros() {
        FILE* archivo = fopen("libros.dat", "rb");
        if(archivo != nullptr) {
            cout << "====== LISTA DE SOCIOS ======" << endl;
            Libro aux;
            while(fread(&aux, sizeof(Libro), 1, archivo) == 1) {
                LibroCout(aux);
            }
            fclose(archivo);
        } else {
            cout << "No se pudo abrir el archivo por lo que no hay libros." << endl;
        }
}

void LibroManager::BuscarIdLibro() {
    int id;
    cout << endl <<"Ingresar el id del libro: ";
    cin >> id;

    while(id <= 0) {
        cout << endl << "Ingresar una id valida (debe ser mayor a 0): ";
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
            LibroCout(aux);
            break;
        }
    }

    fclose(archivo);

    if(!encontrado) {
        cout << "No encontramos el libro que buscaba" << endl;
    }
}

void LibroManager::LibroCout(Libro l) {
    cout << endl << "ID: " << l.getId() << endl;
    cout << "Titulo: " << l.getTitulo() << endl;
    cout << "Autor: " << l.getIdAutor() << endl;
    cout << "ISBN: " << l.getIsbn() << endl;
    cout << "Genero: " << l.getGenero() << endl;
    cout << "Editorial: " << l.getEditorial() << endl;
    cout << "Cantidad de ejemplares: " << l.getCantidadEjemplares() << endl;
    cout << "Veces Prestado: " << l.getVecesPrestado() << endl;
    cout << "Estado: " << l.getEstado() << endl;
    cout << "----------------------------";
}

//borrar libro function