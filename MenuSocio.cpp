#include <iostream>
#include "SocioManager.h"
#include "rlutil.h"
using namespace std;

static void MostrarMenuSocio() {
    rlutil::cls();

    int x = 4;
    int y = 2;

    rlutil::setColor(rlutil::LIGHTCYAN);
    rlutil::locate(x, y);     cout << "====================";
    rlutil::locate(x, y + 1); cout << "     MENU SOCIOS    ";
    rlutil::locate(x, y + 2); cout << "====================";

    rlutil::setColor(rlutil::LIGHTGREEN);
    rlutil::locate(x, y + 4); cout << "1) Cargar socio";
    rlutil::locate(x, y + 5); cout << "2) Mostrar socios";
    rlutil::locate(x, y + 6); cout << "3) Buscar por ID";
    rlutil::locate(x, y + 7); cout << "4) Sumar o restar puntos manualmente";

    rlutil::setColor(rlutil::LIGHTRED);
    rlutil::locate(x, y + 9); cout << "0) Salir";

    rlutil::resetColor();
    rlutil::locate(x, y + 11);
}

void MenuSocio() {
    SocioManager manager;
    int opcion;

    do {
        MostrarMenuSocio();
        cout << "Opcion: "<< endl;
        cin >> opcion;

        switch(opcion) {
        case 1:
            rlutil::cls();
            manager.CargarSocio();
            rlutil::anykey();
            break;
        case 2:
            rlutil::cls();
            manager.MostrarSocios();
            rlutil::anykey();
            break;
        case 3:
            rlutil::cls();
            manager.BuscarIdSocio();
            rlutil::anykey();
            break;
        case 4:
            rlutil::cls();
            manager.SumarPuntosManual();
            rlutil::anykey();
            break;
        case 0:
            break;
        default:
            rlutil::cls();
            cout << "OPCION INCORRECTA" << endl;
            cout << "\nPresione una tecla para continuar...";
            rlutil::anykey();
        }

    } while (opcion != 0);
}


