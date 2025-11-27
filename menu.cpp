#include <iostream>
#include "Menu.h"
#include "rlutil.h"
#include "Libro.h"
#include "MenuVetados.h"
#include "MenuLibro.h"
#include "MenuSocio.h"
#include "MenuSuscripcion.h"
#include "MenuPrestamo.h"
#include "MenuAutor.h"
using namespace std;

void ejecutar() {
    int opcion;
    do {
        rlutil::cls();
        mostrarMenuPrincipal();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                rlutil::cls();
                MenuAutor();
                break;
            case 2:
                rlutil::cls();
                MenuLibro();
                break;
            case 3:
                rlutil::cls();
                MenuSocio();
                break;
            case 4:
                rlutil::cls();
                MenuSuscripcion();
                break;
            case 5:
                rlutil::cls();
                MenuPrestamo();
                break;
            case 6:
                rlutil::cls();
                MenuVetados();
                break;
            case 0:
                cout << "Gracias por usar el sistema de libreria" << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                cout << "\nPresione una tecla para continuar...";
                rlutil::anykey();
        }
    } while (opcion != 0);
}

void mostrarMenuPrincipal() {
    int x = 6;
    int y = 2;

    rlutil::setColor(rlutil::LIGHTCYAN);
    rlutil::locate(x, y);
    cout << "========================================";
    rlutil::locate(x, y + 1);
    cout << "     SISTEMA DE GESTION DE LIBRERIA     ";
    rlutil::locate(x, y + 2);
    cout << "========================================";

    rlutil::setColor(rlutil::LIGHTGREEN);
    rlutil::locate(x, y + 4); cout << "1) Gestion de Autores";
    rlutil::locate(x, y + 5); cout << "2) Gestion de Libros";
    rlutil::locate(x, y + 6); cout << "3) Gestion de Socios";
    rlutil::locate(x, y + 7); cout << "4) Gestion de Suscripciones";
    rlutil::locate(x, y + 8); cout << "5) Gestion de Prestamos";
    rlutil::locate(x, y + 10); cout << "6) Gestion de Vetados";

    rlutil::setColor(rlutil::LIGHTRED);
    rlutil::locate(x, y + 12); cout << "0) Salir";

    rlutil::resetColor();
    rlutil::locate(x, y + 14);
}

