#include <iostream>
#include "Menu.h"
#include "rlutil.h"
#include "Libro.h"
#include "MenuVetados.h"
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
                MenuLibros();
                break;
            case 3:
                cout << "menuSocios" << endl;
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


void MenuLibros() {
    int opcion;
    do {
        cout << "========================================" << endl;
        cout << "           GESTION DE LIBROS     " << endl;
        cout << "========================================" << endl;
        cout << "1. Agregar Libro" << endl;
        cout << "2. Buscar Libro (id)" << endl;
        cout << "3. Ver todos los libros" << endl;
        cout << "4. Editar un Libro" << endl;
        cout << "0. Volver" << endl;
        cout << "========================================" << endl;

            cout << "Seleccione una opcion: ";
            cin >> opcion;
            Libro lbr;
                    switch (opcion) {
                        case 1:
                            lbr.cargar();
                            break;
                        case 2:
                            lbr.mostrar();
                            break;
                        case 3:
                            lbr.mostrarLibros();
                            break;
                        case 4:
                            //  remains
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opci�n inv�lida. Intente nuevamente." << endl;
                            break;
                    }
                } while(opcion != 0);
}
