#include <iostream>
#include "Menu.h"
#include "rlutil.h"
#include "Libro.h"
#include "MenuVetados.h"
#include "MenuLibro.h"
#include "MenuSocio.h"
using namespace std;

void ejecutar() {
    int opcion;
    do {
        mostrarMenuPrincipal();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "menuAutores" << endl;
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
                cout << "menuSuscripciones" << endl;
                break;
            case 5:
                cout << "menuPrestamos" << endl;
                break;
            case 6:
                cout << "menuReportes" << endl;
                break;
            case 7:
                rlutil::cls();
                MenuVetados();
                break;
            case 0:
                cout << "�Gracias por usar el sistema de libreria!" << endl;
                break;
            default:
                cout << "Opci�n inv�lida. Intente nuevamente." << endl;
        }
    } while (opcion != 0);
}

void mostrarMenuPrincipal() {
    cout << "========================================" << endl;
    cout << "    SISTEMA DE GESTION DE LIBRERIA     " << endl;
    cout << "========================================" << endl;
    cout << "1. Gestion de Autores" << endl;
    cout << "2. Gestion de Libros" << endl;
    cout << "3. Gestion de Socios" << endl;
    cout << "4. Gestion de Suscripciones" << endl;
    cout << "5. Gestion de Prestamos" << endl;
    cout << "6. Reportes" << endl;
    cout << "7. Gestion de Betados" << endl;
    cout << "0. Salir" << endl;
    cout << "========================================" << endl;
}

