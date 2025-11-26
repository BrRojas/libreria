#include <iostream>
#include "rlutil.h"
#include "PrestamoManager.h"
using namespace std;

static void MostrarMenuPrestamo() {
    rlutil::cls();
    cout << "===== MENU PRESTAMO ====="<< endl;
    cout << "1) Cargar prestamo"<< endl;
    cout << "2) Mostrar prestamos"<< endl;
    cout << "3) Buscar prestamo por ID del socio"<< endl;
    cout << "4) Eliminar prestamo por ID"<< endl;
    cout << "0) Salir"<< endl;
}

void MenuPrestamo() {
    PrestamoManager manager;
    int opcion;

    do {
        MostrarMenuPrestamo();
        cout << "Opcion: "<< endl;
        cin >> opcion;

        switch(opcion) {
        case 1:
            manager.CargarPrestamo();
            rlutil::anykey();
            break;
        case 2:
            manager.MostrarPrestamos();
            rlutil::anykey();
            break;
        case 3:
            manager.BuscarIdPrestamoSocio();
            rlutil::anykey();
            break;
        case 4:
            manager.BorrarPrestamo();
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