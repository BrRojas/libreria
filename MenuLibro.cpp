#include <iostream>
#include "rlutil.h"
#include "LibroManager.h"
using namespace std;
// se sobre escribio mal
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
    rlutil::locate(x, y + 8); cout << "5) Editar libro por ID";
    rlutil::locate(x, y + 9); cout << "6) Buscar libros por genero";
    rlutil::locate(x, y + 10); cout << "7) Buscar libros por titulo";
    rlutil::locate(x, y + 11); cout << "8) Buscar libros por ISBN";

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(x, y + 12); cout << "9) Reporte";

    rlutil::setColor(rlutil::LIGHTRED);
    rlutil::locate(x, y + 14); cout << "0) Salir";

    rlutil::resetColor();
    rlutil::locate(x, y + 16);
}

void MenuLibro() {
    LibroManager manager;
    int opcion;

    do {
        MostrarMenuLibro();
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
        case 1:
            rlutil::cls();
            manager.CargarLibro();
            rlutil::anykey();
            break;
        case 2:
            rlutil::cls();
            manager.MostrarLibros();
            rlutil::anykey();
            break;
        case 3:
            rlutil::cls();
            manager.BuscarIdLibro();
            rlutil::anykey();
            break;
        case 4:
            rlutil::cls();
            manager.BorrarLibro();
            rlutil::anykey();
            break;
        case 5:
            rlutil::cls();
            manager.EditarLibro();
            rlutil::anykey();
            break;
        case 6:
            rlutil::cls();
            manager.BuscarPorGenero();
            rlutil::anykey();
            break;
        case 7:
            rlutil::cls();
            manager.BuscarPorTitulo();
            rlutil::anykey();
            break;
        case 8:
            rlutil::cls();
            manager.BuscarPorIsbn();
            rlutil::anykey();
            break;
        case 9:
            rlutil::cls();
            manager.ReporteLibrosStock();
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