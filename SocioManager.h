#pragma once
#include "CSocio.h"

class SocioManager {
public:
    void CargarSocio();
    void MostrarSocios();
    void BuscarIdSocio();
    void SumarPuntos(int idSocio, int puntos);
    void SumarPuntosManual();
};

