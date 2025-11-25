#include "Prestamo.h"
#include "Fecha.h"
#include <cstring>
#include <iostream>
using namespace std;

    //Fecha maxima agregar, fecha limite 1 mes

    Prestamo::Prestamo(){
        return;
    }

    // Getters
    int Prestamo::getIdPrestamo() {
        return idPrestamo;
    }
    int Prestamo::getIdSocio() {
        return idSocio;
    }
    char* Prestamo::getIsBn() {
        return isBn;
    }
    Fecha Prestamo::getFechaPrestamo() {
        return fechaPrestamo;
    }
    Fecha Prestamo::getFechaDevolucion() {
        return fechaDevolucion;
    }
    bool Prestamo::getEstado() {
        return estado;
    }

    // Setters
    void Prestamo::setIdPrestamo(int idPrestamo) {
        this->idPrestamo = idPrestamo;
    }
    void Prestamo::setIdSocio(int idSocio) {
        this->idSocio = idSocio;
    }
    void Prestamo::setIsBn(char* isBn) {
        strcpy(this->isBn, isBn);
    }
    void Prestamo::setFechaPrestamo(Fecha fechaPrestamo) {
        this->fechaPrestamo = fechaPrestamo;
    }
    void Prestamo::setFechaDevolucion(Fecha fechaDevolucion) {
        this->fechaDevolucion = fechaDevolucion;
    }
    void Prestamo::setEstado(bool estado) {
        this->estado = estado;
    }
