#include <iostream>
#include "Menu.h"
#include "Betados.h"

using namespace std;

void ejecutar() {
    int opcion;
    do {
        mostrarMenuPrincipal();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: cout << "menuAutores" << endl; break;
            case 2: cout << "menuLibros" << endl; break;
            case 3: cout << "menuSocios" << endl; break;
            case 4: cout << "menuSuscripciones" << endl; break;
            case 5: cout << "menuPrestamos" << endl; break;
            case 6: cout << "menuReportes" << endl; break;
            case 7: cout << "menuBetados" << endl; mostrarMenuBetados();
            case 0: cout << "�Gracias por usar el sistema de libreria!" << endl; break;
            default: cout << "Opci�n inv�lida. Intente nuevamente." << endl;
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


void mostrarMenuBetados() {
    // cout << "========================================" << endl;
    // cout << "    SISTEMA DE GESTION DE Betados     " << endl;
    // cout << "========================================" << endl;
    // cout << "1. Gestion de Autores" << endl;
    // cout << "2. Gestion de Libros" << endl;
    // cout << "3. Gestion de Socios" << endl;
    // cout << "0. Salir" << endl;
    // cout << "========================================" << endl;
    Betados betado;

    betado.MostrarBetados();
}

void mostrarMenuLibros() {

}
