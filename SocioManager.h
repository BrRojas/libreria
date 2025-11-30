#pragma once
#include "CSocio.h"

class SocioManager {
public:
    void CargarSocio();
    void MostrarSocios();
    void BuscarIdSocio();
    bool ExisteSocio(int idBuscado);
    void SumarPuntos(int idSocio, int puntos);
    void SumarPuntosManual();
    void ModificarSocio();
};

