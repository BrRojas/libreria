#include <iostream>
#include "rlutil.h"
#include "LibroManager.h"
using namespace std;

static void MostrarMenuLibro() {
    rlutil::cls();

    int x = 4;
    int y = 2;

    rlutil::setColor(rlutil::LIGHTCYAN);
    rlutil::locate(x, y);     cout << "====================";
    rlutil::locate(x, y + 1); cout << "      MENU LIBRO    ";
    rlutil::locate(x, y + 2); cout << "====================";

    rlutil::setColor(rlutil::LIGHTGREEN);
    rlutil::locate(x, y + 4); cout << "1) Cargar libro";
    rlutil::locate(x, y + 5); cout << "2) Mostrar libros";
    rlutil::locate(x, y + 6); cout << "3) Buscar por ID";
    rlutil::locate(x, y + 7); cout << "4) Eliminar libro por ID";

    rlutil::setColor(rlutil::LIGHTRED);
    rlutil::locate(x, y + 9); cout << "0) Salir";

    rlutil::resetColor();
    rlutil::locate(x, y + 11);
}

void MenuLibro() {
    LibroManager manager;
    int opcion;

    do {
        MostrarMenuLibro();
        cout << "Opcion: "<< endl;
        cin >> opcion;

        switch(opcion) {
        case 1:
            manager.CargarLibro();
            rlutil::anykey();
            break;
        case 2:
            manager.MostrarLibros();
            rlutil::anykey();
            break;
        case 3:
            manager.BuscarIdLibro();
            rlutil::anykey();
            break;
        case 4:
            manager.BorrarLibro();
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