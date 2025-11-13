#include "VetadosManager.h"
#include "Betados.h"
#include <iostream>
#include <cstring>
using namespace std;



void VetadosManager::CargarVetados() {
    int id;
    cout << "Ingrese ID del vetado: ";
    cin >> id;

    vetado.setIdVetados(id);

    if(vetado.getIdVetados() != 0) {
        FILE* archivo = fopen("Vetados.dat", "ab");
        if(archivo != nullptr) {
            fwrite(&vetado, sizeof(Vetados), 1, archivo);
            fclose(archivo);
            cout << "Vetado guardado correctamente"<< endl;
        }
        else {
            cout << "No se pudo abrir el archivo"<< endl;
        }
    }
}


void VetadosManager::MostrarVetados() {
    FILE* archivo = fopen("Vetados.dat", "rb");
    if(archivo == nullptr) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    Vetados arc;
    int contador = 0;

    cout << "Lista de vetados:" << endl;

    while(fread(&arc, sizeof(Vetados), 1, archivo) == 1) {
        contador++;
        cout << contador << ") ID: " << arc.getIdVetados() << endl;
    }

    if(contador == 0)
        cout << "No hay vetados cargados" << endl;

    fclose(archivo);
}

void VetadosManager::BuscarPorID() {
    FILE* archivo = fopen("Vetados.dat", "rb");
    if(archivo == nullptr) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    int id;
    cout << "Ingrese el ID a buscar: " << endl;
    cin >> id;

    Vetados arc;
    bool encontrado = false;

    while(fread(&arc, sizeof(Vetados), 1, archivo) == 1) {
        if(arc.getIdVetados() == id) {
            cout << "ID encontrado: " << arc.getIdVetados() << endl;
            encontrado = true;
            break;
        }
    }

    if(!encontrado)
        cout << "ID no encontrado" << endl;

    fclose(archivo);
}
