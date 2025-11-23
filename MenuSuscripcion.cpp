#include <iostream>
#include "MenuSuscripcion.h"
#include "SuscripcionManager.h"
#include "rlutil.h"
using namespace std;

static void mostrarMenuSuscripcion() {
    cout << "===== GESTION DE SUSCRIPCIONES =====" << endl;
    cout << "1. Alta de suscripcion" << endl;
    cout << "2. Listar suscripciones" << endl;
    cout << "3. Buscar por ID de socio" << endl;
    cout << "4. Renovar automaticas (segun fecha ingresada)" << endl;
    cout << "0. Volver" << endl;
}

void MenuSuscripcion() {
    SuscripcionManager mgr;
    int op;
    do {
        mostrarMenuSuscripcion();
        cout << "Seleccione una opcion: ";
        cin >> op;
        switch (op) {
            case 1:
                rlutil::cls();
                mgr.CargarSuscripcion();
                break;
            case 2:
                rlutil::cls();
                mgr.MostrarSuscripciones();
                break;
            case 3:
                rlutil::cls();
                mgr.BuscarPorIdSocio();
                break;
            case 4:
                rlutil::cls();
                mgr.RenovarAutomaticas();
                break;
            case 0:
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
        if (op != 0) {
            cout << "\nPresione una tecla para continuar...";
            rlutil::anykey();
            rlutil::cls();
        }
    } while (op != 0);
}
