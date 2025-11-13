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
        cout << "========================================" << endl;
        cout << "    SISTEMA DE GESTION DE VETADOS       " << endl;
        cout << "========================================" << endl;
        cout << "1) Cargar vetado" << endl;
        cout << "2) Mostrar lista" << endl;
        cout << "3) Buscar por ID" << endl;
        cout << "0) Salir" << endl;
        cout << "Seleccione una opcion: ";
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

            case 0:
                break;

            default:
                cout << "OPCION INCORRECTA" << endl;
                break;
        }
    } while(opcion != 0);
}
