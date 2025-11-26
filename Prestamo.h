#pragma once
#include "Fecha.h"

class Prestamo {
    private:
        int idPrestamo, idSocio;
        char isBn[20];
        Fecha fechaPrestamo, fechaDevolucion;
        bool estado;

    public:
        Prestamo();
        int getIdPrestamo();
        int getIdSocio();
        char* getIsBn();
        Fecha getFechaPrestamo();
        Fecha getFechaDevolucion();
        bool getEstado();

        void setIdPrestamo(int idPrestamo);
        void setIdSocio(int idSocio);
        void setIsBn(char* isBn);
        void setFechaPrestamo(Fecha fechaPrestamo);
        void setFechaDevolucion(Fecha fechaDevolucion);
        void setEstado(bool estado);
};
