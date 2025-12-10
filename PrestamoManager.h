#pragma once
#include "Prestamo.h"

class PrestamoManager {
public:
    void CargarPrestamo();
    void MostrarPrestamos();
    void BuscarIdPrestamoSocio();
    void DevolucionPrestamo();
    void BorrarPrestamo();
    void PrestamoCout(Prestamo p);
    void RankingLibrosMasPrestados();

};
