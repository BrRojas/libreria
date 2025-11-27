#include <iostream>
#include "MenuAutor.h"
#include "AutorManager.h"
#include "rlutil.h"
using namespace std;

static void mostrarMenuAutor(){
    rlutil::cls();
    int x = 6, y = 2;
    rlutil::setColor(rlutil::LIGHTCYAN);
    rlutil::locate(x, y);     cout << "==============================";
    rlutil::locate(x, y + 1); cout << "     GESTION DE AUTORES      ";
    rlutil::locate(x, y + 2); cout << "==============================";

    rlutil::setColor(rlutil::LIGHTGREEN);
    rlutil::locate(x, y + 4); cout << "1) Alta de autor";
    rlutil::locate(x, y + 5); cout << "2) Listar autores";
    rlutil::locate(x, y + 6); cout << "3) Buscar por ID de autor";
    rlutil::locate(x, y + 7); cout << "4) Modificar autor";
    rlutil::locate(x, y + 8); cout << "5) Borrar autor";

    rlutil::setColor(rlutil::LIGHTRED);
    rlutil::locate(x, y + 10); cout << "0) Volver";

    rlutil::resetColor();
    rlutil::locate(x, y + 12);
}

void MenuAutor(){
    AutorManager mgr;
    int op;
    do{
        mostrarMenuAutor();
        cout << "Seleccione una opcion: ";
        cin >> op;
        switch(op){
            case 1:
                rlutil::cls();
                mgr.CargarAutor();
                break;
            case 2:
                rlutil::cls();
                mgr.MostrarAutores();
                break;
            case 3:
                rlutil::cls();
                mgr.BuscarPorIdAutor();
                break;
            case 4:
                rlutil::cls();
                mgr.ModificarAutor();
                break;
            case 5:
                rlutil::cls();
                mgr.BorrarAutor();
                break;
            case 0:
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
        if (op != 0){
            cout << "\nPresione una tecla para continuar...";
            rlutil::anykey();
            rlutil::cls();
        }
    } while(op != 0);
}
