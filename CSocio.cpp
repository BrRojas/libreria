#include <iostream>
#include <cstring>
#include "CSocio.h"
using namespace std;

Socio::Socio(){
    IdSocio = 0;
    strcpy(Nombre, "SIN NOMBRE");
    strcpy(Categoria, "S/C");
    strcpy(Telefono, "000000000");
    Estado = '0';
    IncluyeDonacion = '0';
}
void Socio::setIdSocio(int id){
    IdSocio = id;
}
void Socio::setNombre(const char *nom) {
   strcpy(Nombre, nom);
}
void Socio::setCategoria(char *Cat){
    strcpy(Categoria, Cat);
}
void Socio::setTelefono(char *Tel) {
    strcpy(Telefono, Tel);
}
void Socio::setEstado(char e) {
    Estado = e;
}
void Socio::setIncluyeDonacion(char d) {
    IncluyeDonacion = d;
}

int Socio::getIdSocio(){
    return IdSocio;
}
const char* Socio::getNombre() {
    return Nombre;
}
char *Socio::getCategoria(){
    return Categoria;
}
char *Socio::getTelefono(){
    return Telefono;
}
char Socio::getEstado(){
    return Estado;
}
char Socio::getIncluyeDonacion(){
    return IncluyeDonacion;
}

