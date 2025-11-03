#include <iostream>
#include <cstring>
#include "CSocio.h"
using namespace std;

Socio::Socio(){
    IdSocio = 0;
    strcpy(Categoria, "S/C");
    strcpy(Telefono, "000000000");
    Estado= false;
    IncluyeDonacion= false;
}
void Socio::setIdSocio(int){
    IdSocio = 1;
}
void Socio::setCategoria(char *Cat){
    strcpy(Categoria, Cat);
}
void Socio::setTelefono(char *tel){
    strcpy(Telefono, tel);
}
void Socio::setEstado(bool){
    Estado = false;
}
int Socio::getIdSocio(){
    return IdSocio;
}
char *Socio::getCategoria(){
    return Categoria;
}
char *Socio::getTelefono(){
    return Telefono;
}
bool Socio::getEstado(){
    return Estado;
}
bool Socio::getIncluyeDonacion(){
    return IncluyeDonacion;
}

void Socio::Cargar(){
    cout << "Ingrese el numero de socio: ";
    cin >> IdSocio;
    cout << "Ingrese la categoria del socio: ";
    cin >> Categoria;
    cin.ignore();
    cin.getline (Categoria, 30);
    cout << "Ingrese el telefono del socio: ";
    cin >> Telefono;
    cin.ignore();
    cin.getline (Telefono, 15);
    cout << "el socio se encuentra activo?: ";
    cin >> Estado;
    if (Estado==false){
        cout << "esta inactivo";
    }
    else {
        cout << "esta activo";
    }
    cout << "el socio incluyo donacion?: ";
    cin >> IncluyeDonacion;
    if (IncluyeDonacion==false){
        cout << "No dio donacion";
    }
    else {
        cout << "Es generoso y dono! ";
    }
}
void Socio::Mostrar(){
    cout << "El id del socio es: ";
    cout << "El telefono es: ";
    cout << "La categoria es: ";
    cout << "Se encuentra en estado: ";
    cout << "incluyo donacion?: ";
}
