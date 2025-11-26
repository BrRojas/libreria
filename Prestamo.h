#pragma once
#include "Fecha.h"

class Prestamo {
    private:
        int idPrestamo, idSocio, idLibro;
        Fecha fechaPrestamo, fechaDevolucion;
        bool estado;

    public:
        Prestamo();
        int getIdPrestamo();
        int getIdSocio();
        int getIdLibro();
        Fecha getFechaPrestamo();
        Fecha getFechaDevolucion();
        bool getEstado();

        void setIdPrestamo(int idPrestamo);
        void setIdSocio(int idSocio);
        void setIdLibro(int idLibro);
        void setFechaPrestamo(Fecha fechaPrestamo);
        void setFechaDevolucion(Fecha fechaDevolucion);
        void setEstado(bool estado);
};
