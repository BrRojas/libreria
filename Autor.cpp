#include <iostream>
#include <cstring>
#include "Autor.h"
using namespace std;

Autor::Autor() {
    idAutor = 0;
    strcpy(nombre, "Sin nombre");
    strcpy(nacionalidad, "Desconocida");
}

Autor::Autor(int id, const char* nom, const char* nac, Fecha fNac) {
    idAutor = id;
    strcpy(nombre, nom);
    strcpy(nacionalidad, nac);
    fechaNacimiento = fNac;
}

void Autor::cargar() {
    cout << "ID Autor: ";
    cin >> idAutor;
    cin.ignore();
    cout << "Nombre: ";
    cin.getline(nombre, 40);
    cout << "Nacionalidad: ";
    cin.getline(nacionalidad, 30);

    cout << "Fecha de nacimiento:" << endl;
    fechaNacimiento.cargar();
}

void Autor::mostrar() {
    cout << "\n--- DATOS DEL AUTOR ---" << endl;
    cout << "ID: " << idAutor << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Nacionalidad: " << nacionalidad << endl;
    cout << "Fecha de nacimiento: ";
    fechaNacimiento.mostrar();
    cout << endl;
}

void Autor::setIdAutor(int id) { idAutor = id; }
void Autor::setNombre(const char* nom) { strcpy(nombre, nom); }
void Autor::setNacionalidad(const char* nac) { strcpy(nacionalidad, nac); }
void Autor::setFechaNacimiento(Fecha f) { fechaNacimiento = f; }

int Autor::getIdAutor() { return idAutor; }
const char* Autor::getNombre() { return nombre; }
const char* Autor::getNacionalidad() { return nacionalidad; }
Fecha Autor::getFechaNacimiento() { return fechaNacimiento; }
