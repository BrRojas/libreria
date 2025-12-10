#include <iostream>
#include <cstring>
#include "CSocio.h"
using namespace std;

Socio::Socio(){
    puntos = 0;
    IdSocio = 0;
    strcpy(Nombre, "SIN NOMBRE");
    strcpy(Categoria, "S/C");
    strcpy(Telefono, "000000000");
    IncluyeDonacion = '0';
}
void Socio::setIdSocio(int id){
    IdSocio = id;
}
void Socio::setNombre(const char *nom) {
   strcpy(Nombre, nom);
}
void Socio::setCategoria(const char *Cat){
    strcpy(Categoria, Cat);
}
void Socio::setTelefono(const char *Tel) {
    strcpy(Telefono, Tel);
}
void Socio::setIncluyeDonacion(char d) {
    IncluyeDonacion = d;
}
void Socio::setPuntos(int p) {
    puntos = p;
}
int Socio::getIdSocio(){
    return IdSocio;
}
const char* Socio::getNombre() {
    return Nombre;
}
const char *Socio::getCategoria(){
    return Categoria;
}
const char *Socio::getTelefono(){
    return Telefono;
}
char Socio::getIncluyeDonacion(){
    return IncluyeDonacion;
}

int Socio::getPuntos() {
    return puntos;
}
