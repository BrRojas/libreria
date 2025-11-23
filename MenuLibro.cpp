#include <iostream>
#include "rlutil.h"
#include "LibroManager.h"
using namespace std;

void MenuLibro() {
    LibroManager manager;
    int opcion;

    do {
        rlutil::cls();
        cout << "===== MENU LIBRO ====="<< endl;
        cout << "1) Cargar libro"<< endl;
        cout << "2) Mostrar libros"<< endl;
        cout << "3) Buscar por ID"<< endl;
        cout << "0) Salir"<< endl;
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
        case 0:
            break;
        default:
            cout << "OPCION INCORRECTA" << endl;
            cout << "\nPresione una tecla para continuar...";
            rlutil::anykey();
        }

    } while (opcion != 0);
}
