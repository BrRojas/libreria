#pragma once
#include "Suscripcion.h"
#include "Fecha.h"

class SuscripcionManager {
private:
    void VerificarSuscripcionesVencidas();
public:
    void CargarSuscripcion();
    void MostrarSuscripciones();
    void BuscarPorIdSocio();
    void SuscripcionCout(Suscripcion s);
    void ModificarSuscripcion();
    void SumarUnMesPorSocio();
    bool tieneSuscripcionActiva(int idSocio);

    //reportes
    int CantidadActivas();
    int CantidadInactivas();
    void Reportes();
};
