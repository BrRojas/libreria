#include <iostream>
#include "SocioManager.h"
#include "rlutil.h"
using namespace std;

void MenuSocio() {
    SocioManager manager;
    int opcion;

    do {
        rlutil::cls();
        cout << "===== MENU SOCIOS ====="<< endl;
        cout << "1) Cargar socio"<< endl;
        cout << "2) Mostrar socios"<< endl;
        cout << "3) Buscar por ID"<< endl;
        cout << "4) Sumar o restar puntos manualmente" << endl;
        cout << "0) Salir"<< endl;
        cout << "Opcion: "<< endl;
        cin >> opcion;

        switch(opcion) {
        case 1:
            manager.CargarSocio();
            rlutil::anykey();
            break;
        case 2:
            manager.MostrarSocios();
            rlutil::anykey();
            break;
        case 3:
            manager.BuscarIdSocio();
            rlutil::anykey();
            break;
        case 4:
            manager.SumarPuntosManual();
            rlutil::anykey();
            break;
        case 0:
            break;
        default:
            cout << "OPCION INCORRECTA" << endl;
            cout << "\nPresione una tecla para continuar...";
            rlutil::anykey();
        }

    } while (opcion != 0);
}


