#include <iostream>
#include "Fecha.h"
using namespace std;


static bool esBisiesto(int a){
    return (a % 4 == 0) && ((a % 100 != 0) || (a % 400 == 0));
}

static int diasEnMes(int m, int a){
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        {return 31};
    else if (m == 4 || m == 6 || m == 9 || m == 11)
        {return 30};
    else if (m == 2)
        {return esBisiesto(a) ? 29 : 28};
    else {return 30};
}

static bool validacionFecha(int d, int m, int a){
    if (a < 1)
        {return false};
    if (m < 1 || m > 12)
        {return false};
    int maxD = diasEnMes(m, a);
    return d >= 1 && d <= maxD;
}

Fecha::Fecha() {
    dia = 1;
    mes = 1;
    anio = 2000;
}

Fecha::Fecha(int d, int m, int a) {
    if (!validacionFecha(d, m, a)) {
        dia = 1; mes = 1; anio = 2000;
    } else {
        dia = d; mes = m; anio = a;
    }
}

void Fecha::cargar() {
    int d, m, a;
    bool estaOk = false;
    do {
        cout << "Dia: ";  cin >> d;
        cout << "Mes: ";  cin >> m;
        cout << "Anio: "; cin >> a;

        if (validacionFecha(d, m, a)) {
            dia = d; mes = m; anio = a;
            estaOk = true;
        } else {
            cout << "Fecha incorrecta. Intente nuevamente.\n";
        }
    } while (!estaOk);
}

void Fecha::mostrar() {
    cout << dia << "/" << mes << "/" << anio;
}

void Fecha::setDia(int d) {
    if (validacionFecha(d, mes, anio)) dia = d;
    else cout << "Dia invalido para " << mes << "/" << anio << ". No se aplico el cambio.";
}

void Fecha::setMes(int m) {
    if (m < 1 || m > 12) {
        cout << "Mes invalido. No se aplico el cambio.";
        return;
    }

    if (validacionFecha(dia, m, anio)) mes = m;
    else cout << "Con mes " << m << " el dia " << dia << " no existe. No se aplico el cambio.";
}

void Fecha::setAnio(int a) {
    if (a < 1) {
        cout << "Anio invalido. No se aplico el cambio.";
        return;
    }
    if (validacionFecha(dia, mes, a)) anio = a;
    else cout << "Para " << mes << "/" << a << " el dia " << dia << " no existe. No se aplico el cambio.";
}

int Fecha::getDia() { return dia; }
int Fecha::getMes() { return mes; }
int Fecha::getAnio() { return anio; }
