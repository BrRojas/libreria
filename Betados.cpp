#include "Betados.h"
#include <iostream>
#include <cstring>
using namespace std;

Vetados::Vetados() {
    IdVetados = 0;
    RestaPuntos = -5;
}

void Vetados::setIdVetados(int id) {
  if(id > 0) {
        IdVetados = id;
    } else {
        cout << "ID inválido. Debe ser mayor que 0." << endl;
        IdVetados = 0;
    }
}
void Vetados::setRestaPuntos(int puntos){
    if (puntos >= 5) {
            RestaPuntos += puntos;
        } else {
            cout << "Error: no hay suficientes puntos para restar. ";
        }
    }

int Vetados::getIdVetados (){
    return IdVetados;
    }

int Vetados::getRestaPuntos(){
    return RestaPuntos;
    }

void Vetados::CargarVetados(){
    int id;
    cout << "Ingrese ID del vetado: ";
    cin >> id;

    setIdVetados(id);

    if(IdVetados != 0) {
        FILE* archivo = fopen("Vetados.dat", "ab");
        if(archivo != nullptr) {
            fwrite(&IdVetados, sizeof(int), 1, archivo);
            fclose(archivo);
            cout << "Vetado agregado y guardado correctamente." << endl;
        } else {
            cout << "No se pudo abrir el archivo." << endl;
        }
    }
}

void Vetados::MostrarVetados(){
    FILE* archivo = fopen("Vetados.dat", "rb");
    if(archivo != nullptr) {
        int id;
        int contador = 0;
        cout << "Lista de vetados:" << endl;
        while(fread(&id, sizeof(int), 1, archivo) == 1) {
            contador++;
            cout << contador << ". ID: " << id << endl;
        }
        if(contador == 0) {
            cout << "No hay vetados cargados." << endl;
        }
        fclose(archivo);
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    }
