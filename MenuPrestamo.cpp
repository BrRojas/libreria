#include <iostream>
#include "rlutil.h"
#include "PrestamoManager.h"
using namespace std;

static void MostrarMenuPrestamo() {
    rlutil::cls();

    int x = 4;
    int y = 2;

    rlutil::setColor(rlutil::LIGHTCYAN);
    rlutil::locate(x, y);     cout << "=======================";
    rlutil::locate(x, y + 1); cout << "     MENU PRESTAMO     ";
    rlutil::locate(x, y + 2); cout << "=======================";

    rlutil::setColor(rlutil::LIGHTGREEN);
    rlutil::locate(x, y + 4); cout << "1) Cargar prestamo";
    rlutil::locate(x, y + 5); cout << "2) Mostrar prestamos";
    rlutil::locate(x, y + 6); cout << "3) Buscar prestamo por ID del socio";
    rlutil::locate(x, y + 7); cout << "4) Devolucion de prestamo por ID";
    rlutil::locate(x, y + 8); cout << "5) Eliminar prestamo por ID";
    rlutil::locate(x, y + 9); cout << "6) Reporte de libros mas prestados";
    rlutil::setColor(rlutil::LIGHTRED);
    rlutil::locate(x, y + 10); cout << "0) Salir";

    rlutil::resetColor();
    rlutil::locate(x, y + 12);
}

void MenuPrestamo() {
    PrestamoManager manager;
    int opcion;

    do {
        MostrarMenuPrestamo();
        rlutil::locate(4, 12); cout << "Opcion: "<< endl;
        cin >> opcion;

        switch(opcion) {
        case 1:
            rlutil::cls();
            manager.CargarPrestamo();
            rlutil::anykey();
            break;
        case 2:
            rlutil::cls();
            manager.MostrarPrestamos();
            rlutil::anykey();
            break;
        case 3:
            rlutil::cls();
            manager.BuscarIdPrestamoSocio();
            rlutil::anykey();
            break;
        case 4:
            rlutil::cls();
            manager.DevolucionPrestamo();
            rlutil::anykey();
            break;
        case 5:
            rlutil::cls();
            manager.BorrarPrestamo();
            rlutil::anykey();
            break;
        case 6:
            rlutil::cls();
            manager.RankingLibrosMasPrestados();
            rlutil::anykey();
            break;
        case 0:
            break;
        default:
            rlutil::cls();
            cout << "OPCION INCORRECTA" << endl;
            cout << "Presione una tecla para continuar..." << endl;
            rlutil::anykey();
        }

    } while (opcion != 0);
}
