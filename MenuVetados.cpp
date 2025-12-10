#include <iostream>
#include "Betados.h"
#include "VetadosManager.h"
#include "MenuVetados.h"
#include "rlutil.h"
using namespace std;

void MenuVetados() {
    VetadosManager vet;
    int opcion;

    do {
        rlutil::cls();

        int x = 4;
        int y = 2;

        rlutil::setColor(rlutil::LIGHTCYAN);
        rlutil::locate(x, y);     cout << "========================================";
        rlutil::locate(x, y + 1); cout << "   SISTEMA DE GESTION DE VETADOS   ";
        rlutil::locate(x, y + 2); cout << "========================================";

        rlutil::setColor(rlutil::LIGHTGREEN);
        rlutil::locate(x, y + 4); cout << "1) Cargar vetado";
        rlutil::locate(x, y + 5); cout << "2) Mostrar lista";
        rlutil::locate(x, y + 6); cout << "3) Buscar por ID";
        rlutil::locate(x, y + 7); cout << "4) Cancelar veto por ID";

        rlutil::setColor(rlutil::LIGHTRED);
        rlutil::locate(x, y + 8); cout << "0) Salir";

        rlutil::resetColor();
        rlutil::locate(x, y + 10); cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                rlutil::cls();
                vet.CargarVetados();
                rlutil::anykey();
                break;

            case 2:
                rlutil::cls();
                vet.MostrarVetados();
                rlutil::anykey();
                break;

            case 3:
                rlutil::cls();
                vet.BuscarPorID();
                rlutil::anykey();
                break;
            case 4:
                rlutil::cls();
                vet.CancelarVeto();
                rlutil::anykey();
                break;
            case 0:
                break;

            default:
                cout << "OPCION INCORRECTA" << endl;
                cout << "\nPresione una tecla para continuar...";
                rlutil::anykey();
                break;
        }
    } while(opcion != 0);
}
