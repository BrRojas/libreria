#pragma once
#include "Suscripcion.h"

class SuscripcionManager {
public:
    void CargarSuscripcion();
    void MostrarSuscripciones();
    void BuscarPorIdSocio();
    void RenovarAutomaticas();
    void SuscripcionCout(Suscripcion s);
};
