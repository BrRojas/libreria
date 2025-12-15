#include <iostream>
#include "Fecha.h"
#include <ctime>
using namespace std;


static bool esBisiesto(int a){
    return (a % 4 == 0) && ((a % 100 != 0) || (a % 400 == 0));
}

static int diasEnMes(int m, int a){
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        return 31;
    else if (m == 4 || m == 6 || m == 9 || m == 11)
        return 30;
    else if (m == 2)
        return esBisiesto(a) ? 29 : 28;
    else return 30;
}

static bool validacionFecha(int d, int m, int a){
    if (a < 1)
        return false;
    if (m < 1 || m > 12)
        return false;
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
long Fecha::diasEntre(const Fecha& otra) const {
    // Convertimos ambas fechas a “día absoluto”
    auto diasAbs = [](const Fecha& f) {
        int a = f.anio;
        int m = f.mes;
        int d = f.dia;

        if (m < 3) {
            a--;
            m += 12;
        }

        long total = 365L * a + a / 4 - a / 100 + a / 400;
        total += (153 * (m - 3) + 2) / 5;
        total += d - 1;
        return total;
    };

    long d1 = diasAbs(*this);
    long d2 = diasAbs(otra);

    return d2 - d1;
}

int Fecha::diasEnMes(int m, int a) {
    return ::diasEnMes(m, a);
}

//con libreria cargamos la fecha actual para validaciones
void Fecha::cargarFechaActual() {
    time_t t = time(0);
    tm* now = localtime(&t);

    dia  = now->tm_mday;
    mes  = now->tm_mon + 1;
    anio = now->tm_year + 1900;
}

void Fecha::sumarDias(int n) {
    while (n > 0) {
        dia++;
        int maxD = diasEnMes(mes, anio);
        if (dia > maxD) {
            dia = 1;
            mes++;
            if (mes > 12) {
                mes = 1;
                anio++;
            }
        }
        n--;
    }
}
