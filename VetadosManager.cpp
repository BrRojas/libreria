#include "VetadosManager.h"
#include "SocioManager.h"
#include "Betados.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;



void VetadosManager::CargarVetados() {
    int id;
    cout << "Ingrese ID del vetado: ";
    cin >> id;

    SocioManager sm;
    if (!sm.ExisteSocio(id)) {
        cout << "No existe un socio con ese ID. No se puede vetar." << endl;
        return;
    }

    if (EstaVetado(id)) {
        cout << "El socio ya esta vetado." << endl;
        return;
    }

    vetado.setIdVetados(id);

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

bool VetadosManager::EstaVetado(int idBuscado) {
    FILE* archivo = fopen("Vetados.dat", "rb");
    if (archivo == nullptr) return false;

    Vetados arc;

    while (fread(&arc, sizeof(Vetados), 1, archivo) == 1) {
        if (arc.getIdVetados() == idBuscado) {
            fclose(archivo);
            return true;
        }
    }

    fclose(archivo);
    return false;
}

void VetadosManager::CancelarVeto() {
    int id;
    cout << "Ingresar el ID del socio a quitar del veto: ";
    cin >> id;

    while (id <= 0) {
        cout << "ID invalido. Ingrese un numero mayor a 0: ";
        cin >> id;
    }

    FILE* archivo = fopen("Vetados.dat", "rb");
    if (!archivo) {
        cout << "No existe archivo de vetados o esta vacío." << endl;
        return;
    }

    vector<Vetados> lista;
    Vetados aux;
    bool encontrado = false;

    // Leer todos los vetados
    while (fread(&aux, sizeof(Vetados), 1, archivo) == 1) {
        if (aux.getIdVetados() == id) {
            encontrado = true;
            cout << "El socio con ID " << id << " estaba vetado y será removido." << endl;
            // NO lo agregamos → lo eliminamos
        } else {
            lista.push_back(aux);  // Guardamos el resto
        }
    }

    fclose(archivo);

    if (!encontrado) {
        cout << "El ID no se encuentra en la lista de vetados." << endl;
        return;
    }

    // Reescribir archivo sin el vetado eliminado
    archivo = fopen("Vetados.dat", "wb");
    if (!archivo) {
        cout << "Error al abrir Vetados.dat para reescribir." << endl;
        return;
    }

    for (const Vetados& v : lista) {
        fwrite(&v, sizeof(Vetados), 1, archivo);
    }

    fclose(archivo);

    cout << "El veto ha sido cancelado correctamente." << endl;
}
