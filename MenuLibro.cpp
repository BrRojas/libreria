#include <iostream>
#include "rlutil.h"
#include "LibroManager.h"
using namespace std;

static void MostrarMenuLibro() {
    cout << "===== MENU LIBRO ====="<< endl;
    cout << "1) Cargar libro"<< endl;
    cout << "2) Mostrar libros"<< endl;
    cout << "3) Buscar por ID"<< endl;
    cout << "4) Eliminar libro por ID"<< endl;
    cout << "5) Editar un libro por ID"<< endl;
    cout << "0) Salir"<< endl;
}

void MenuLibro() {
    LibroManager manager;
    int opcion;

    do {
        rlutil::cls();
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
        case 5:
            manager.EditarLibro();
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