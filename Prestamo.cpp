#include "Prestamo.h"
#include "Fecha.h"
#include <cstring>
#include <iostream>
using namespace std;

    //Fecha maxima agregar, fecha limite 1 mes

    // Constructor
    Prestamo::Prestamo(int idPrestamo, int idSocio, char* isBn, Fecha fechaPrestamo, Fecha fechaDevolucion, bool estado) {
        this->idPrestamo = idPrestamo;
        this->idSocio = idSocio;
        strcpy(this->isBn, isBn);
        this->fechaPrestamo = fechaPrestamo;
        this->fechaDevolucion = fechaDevolucion;
        this->estado = estado;
    }

    Prestamo::Prestamo(){
        return;
    }

    int Prestamo::Cargar() {
        int idPrestamo, idSocio; // id del prestamo deberia generarse automaticamente
        char isBn[20];
        Fecha fechaPrestamo, fechaDevolucion;
        bool estado;
        cout << "Ingrese el Id del socio: ";
        cin >> idSocio;
        cin.ignore();
        cout << "Ingrese el isBn: ";
        cin.getline(isBn, 20);
        cout << "Ingrese la fecha del prestamo: ";
        fechaPrestamo.cargar();
        cout << "Ingrese la fecha de devolucion: ";
        fechaDevolucion.cargar();

        setIdSocio(idSocio);
        setIsBn(isBn);
        setFechaPrestamo(fechaPrestamo);
        setFechaDevolucion(fechaDevolucion);
        setEstado(true);
        return 0;
    }

    void Prestamo::Mostrar() {
        cout << "IDPrestamo: " << getIdPrestamo() << endl;
        cout << "Fecha de Prestamo: ";
        getFechaPrestamo().mostrar();
        cout << endl;
        cout << "Fecha de devolucion: ";
        getFechaDevolucion().mostrar();
        cout << endl;
        cout << "Estado: " << getEstado() << endl;
    }

    void Prestamo::MostrarPrestamos() {

    }

    // Getters
    int Prestamo::getIdPrestamo() {
        return idPrestamo;
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
