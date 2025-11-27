#pragma once
#include "Autor.h"

class AutorManager {
public:
    void CargarAutor();
    void MostrarAutores();
    void BuscarPorIdAutor();
    void AutorCout(Autor a);
    void ModificarAutor();
    void BorrarAutor();
};
