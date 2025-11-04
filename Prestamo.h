#pragma once
#include "Prestamo.h"
#include "Fecha.h"

class Prestamo {
    private:
        int idPrestamo;
        int idSocio;
        char[20] isBn;
        Fecha fechaPrestamo;
        Fecha fechaDevolucion;
        bool estado;

    public:
        Prestamo(int idPrestamo, int idSocio, char[20] isBn, Fecha fechaPrestamo, Fecha fechaDevolucion, bool estado);
        int getIdPrestamo();
        Fecha getFechaPrestamo();
        Fecha getFechaDevolucion();
        bool getEstado();

        void setIdPrestamo(int idPrestamo);
        void setFechaPrestamo(Fecha fechaPrestamo);
        void setFechaDevolucion(Fecha fechaDevolucion);
        void setEstado(bool estado);
};