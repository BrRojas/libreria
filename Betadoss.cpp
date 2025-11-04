#include "Betados.h"
#include <iostream>
using namespace std;

Betados::Betados() {
    IdBetados = 0;
    AsignacionBetados = 0;
    RestaPuntos = 0;
}

void Betados::setIdBetados(int id) {
    if (id > 0)
        IdBetados = id;
    else {
        cout << "⚠️  ID inválido. Debe ser un número mayor que 0.\n";
        IdBetados = 0;
    }
}

void Betados::setAsignacionBetados(int puntos) {
    if (puntos >= 0)
        AsignacionBetados = puntos;
    else {
        cout << "⚠️  Asignación inválida. No se pueden asignar puntos negativos.\n";
        AsignacionBetados = 0;
    }
}

void Betados::setRestaPuntos(int puntos) {
    if (puntos < 0) {
        cout << "⚠️  No se puede restar una cantidad negativa.\n";
        return;
    }

    if (puntos > AsignacionBetados) {
        cout << "⚠️  No se pueden restar más puntos de los asignados.\n";
        RestaPuntos = AsignacionBetados; // o podrías dejarlo igual que antes
    } else {
        RestaPuntos = puntos;
    }
}

// ----------------------
// GETTERS
// ----------------------

int Betados::getIdBetados() { return IdBetados; }

int Betados::getAsignacionBetados() { return AsignacionBetados; }

int Betados::getRestaPuntos() { return RestaPuntos; }

// ----------------------
// FUNCIONES EXTRA
// ----------------------

void Betados::CargarBetados() {
    int id, puntos, resta;

    cout << "Ingrese ID del betado: ";
    cin >> id;
    setIdBetados(id);

    cout << "Ingrese puntos asignados: ";
    cin >> puntos;
    setAsignacionBetados(puntos);

    cout << "Ingrese puntos a restar: ";
    cin >> resta;
    setRestaPuntos(resta);
}

void Betados::MostrarBetados() {
    cout << "\n===== Datos del Betado =====" << endl;
    cout << "ID: " << IdBetados << endl;
    cout << "Puntos asignados: " << AsignacionBetados << endl;
    cout << "Puntos restados: " << RestaPuntos << endl;
}
