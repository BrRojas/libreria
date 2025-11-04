#include "Prestamo.h"
#include "Fecha.h"
#include <cstring>


    // Constructor
    Prestamo::Prestamo(int idPrestamo, int idSocio, char[20] isBn, Fecha fechaPrestamo, Fecha fechaDevolucion, bool estado) {
        this->idPrestamo = idPrestamo;
        this->idSocio = idSocio;
        this->isBn = isBn;
        this->fechaPrestamo = fechaPrestamo;
        this->fechaDevolucion = fechaDevolucion;
        this->estado = estado;
    }
    
    // Getters
    int Prestamo::getIdPrestamo() {
        return this->idPrestamo;
    }
    Fecha Prestamo::getFechaPrestamo() {
        return this->fechaPrestamo;
    }
    Fecha Prestamo::getFechaDevolucion() {
        return this->fechaDevolucion;
    }
    bool Prestamo::getEstado() {
        return this->estado;
    }

    // Setters
    void Prestamo::setIdPrestamo(int idPrestamo) {
        this->idPrestamo = idPrestamo;
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
