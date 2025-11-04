#include "Betados.h"
#include <iostream>
#include <cstring>
using namespace std;

Betados::Betados() {
    IdBetados = 0;
    RestaPuntos = -5;
}

void Betados::setIdBetados(int id) {
  if(id > 0) {
        IdBetados = id;
    } else {
        cout << "ID inválido. Debe ser mayor que 0." << endl;
        IdBetados = 0;
    }
}
void Betados::setRestaPuntos(int puntos){
    if (puntos >= 5) {
            RestaPuntos += puntos;
        } else {
            cout << "Error: no hay suficientes puntos para restar. ";
        }
    }

int Betados::getIdBetados (){
    return IdBetados;
    }

int Betados::getRestaPuntos(){
    return RestaPuntos;
    }

void Betados::CargarBetados(){
    int id;
    cout << "Ingrese ID del betado: ";
    cin >> id;

    setIdBetados(id);

    if(IdBetados != 0) {
        FILE* archivo = fopen("betados.dat", "ab");
        if(archivo != nullptr) {
            fwrite(&IdBetados, sizeof(int), 1, archivo);
            fclose(archivo);
            cout << "Betado agregado y guardado correctamente." << endl;
        } else {
            cout << "No se pudo abrir el archivo." << endl;
        }
    }
}

void Betados::MostrarBetados(){
    FILE* archivo = fopen("betados.dat", "rb");
    if(archivo != nullptr) {
        int id;
        int contador = 0;
        cout << "Lista de betados:" << endl;
        while(fread(&id, sizeof(int), 1, archivo) == 1) {
            contador++;
            cout << contador << ". ID: " << id << endl;
        }
        if(contador == 0) {
            cout << "No hay betados cargados." << endl;
        }
        fclose(archivo);
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    }


