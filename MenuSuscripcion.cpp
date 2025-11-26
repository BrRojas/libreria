#include <iostream>
#include "MenuSuscripcion.h"
#include "SuscripcionManager.h"
#include "rlutil.h"
using namespace std;

static void mostrarMenuSuscripcion() {
    rlutil::cls();

    int x = 4;
    int y = 2;

    rlutil::setColor(rlutil::LIGHTCYAN);
    rlutil::locate(x, y);
    cout << "==============================";
    rlutil::locate(x, y + 1);
    cout << "   GESTION DE SUSCRIPCIONES   ";
    rlutil::locate(x, y + 2);
    cout << "==============================";

    rlutil::setColor(rlutil::LIGHTGREEN);
    rlutil::locate(x, y + 4);
    cout << "1) Alta de suscripcion";
    rlutil::locate(x, y + 5);
    cout << "2) Listar suscripciones";
    rlutil::locate(x, y + 6);
    cout << "3) Buscar por ID de socio";

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(x, y + 8);
    cout << "4) Renovar automaticas (segun fecha ingresada)";
    rlutil::locate(x, y + 9);
    cout << "5) Modificar suscripcion";

    rlutil::setColor(rlutil::LIGHTRED);
    rlutil::locate(x, y + 11);
    cout << "0) Volver";

    rlutil::resetColor();
    rlutil::locate(x, y + 13);
}

void MenuSuscripcion() {
    SuscripcionManager mgr;
    int op;
    do {
        mostrarMenuSuscripcion();
        cout << "Seleccione una opcion: ";
        cin >> op;
        switch (op) {
            case 1:
                rlutil::cls();
                mgr.CargarSuscripcion();
                break;
            case 2:
                rlutil::cls();
                mgr.MostrarSuscripciones();
                break;
            case 3:
                rlutil::cls();
                mgr.BuscarPorIdSocio();
                break;
            case 4:
                rlutil::cls();
                mgr.RenovarAutomaticas();
                break;
            case 5:
                rlutil::cls();
                mgr.ModificarSuscripcion();
                break;
            case 0:
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
        if (op != 0) {
            cout << "\nPresione una tecla para continuar...";
            rlutil::anykey();
            rlutil::cls();
        }
    } while (op != 0);
}
