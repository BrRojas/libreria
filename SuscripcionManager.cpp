#include <iostream>
#include <cstdio>
#include "SuscripcionManager.h"
using namespace std;

static const char* SUSC_FILE = "suscripciones.dat";

void SuscripcionManager::CargarSuscripcion() {
    Suscripcion s;
    int idSocio;
    bool renovAuto;
    Fecha ini, fin;

    cout << "Ingrese el ID del Socio: ";
    cin >> idSocio;
    cout << "Fecha de inicio:\n";
    ini.cargar();
    cout << "Fecha de fin:\n";
    fin.cargar();
    cout << "Renovacion automatica (1=si, 0=no): ";
    cin >> renovAuto;

    s.setIdSocio(idSocio);
    s.setFechaInicio(ini);
    s.setFechaFin(fin);
    s.setRenovacionAutomatica(renovAuto);
    s.setEstado(true);

    int idNuevo = 1;
    FILE* p = fopen(SUSC_FILE, "rb");
    if (p != NULL) {
        fseek(p, 0, SEEK_END);
        long bytes = ftell(p);
        if (bytes > 0) idNuevo = (int)(bytes / sizeof(Suscripcion)) + 1;
        fclose(p);
    }
    s.setIdSuscripcion(idNuevo);

    FILE* a = fopen(SUSC_FILE, "ab");
    if (a == NULL) {
        cout << "No se pudo abrir el archivo de suscripciones" << endl;
        return;
    }
    if (fwrite(&s, sizeof(Suscripcion), 1, a) != 1) {
        cout << "Error intentando agregar la suscripcion." << endl;
        fclose(a);
        return;
    }
    fclose(a);
    cout << "Suscripcion guardada correctamente." << endl;
}

void SuscripcionManager::MostrarSuscripciones() {
    FILE* a = fopen(SUSC_FILE, "rb");
    if (a == nullptr) {
        cout << "No hay suscripciones." << endl;
        return;
    }
    cout << "====== LISTA DE SUSCRIPCIONES ======" << endl;
    Suscripcion aux;
    while (fread(&aux, sizeof(Suscripcion), 1, a) == 1) {
        SuscripcionCout(aux);
    }
    fclose(a);
}

void SuscripcionManager::BuscarPorIdSocio() {
    int id;
    cout << "Ingresar el id del socio: ";
    cin >> id;
    while (id <= 0) {
        cout << "Ingresar una id valida (mayor a 0): ";
        cin >> id;
    }
    FILE* a = fopen(SUSC_FILE, "rb");
    if (a == nullptr) {
        cout << "No hay suscripciones." << endl;
        return;
    }
    Suscripcion aux;
    bool alguno = false;
    while (fread(&aux, sizeof(Suscripcion), 1, a) == 1) {
        if (aux.getIdSocio() == id) {
            alguno = true;
            SuscripcionCout(aux);
        }
    }
    fclose(a);
    if (!alguno) cout << "No encontramos suscripciones para ese socio." << endl;
}

void SuscripcionManager::RenovarAutomaticas() {
    Fecha hoy;
    cout << "Ingresar fecha 'hoy' para procesar renovaciones:\n";
    hoy.cargar();

    FILE* a = fopen(SUSC_FILE, "rb+");
    if (a == nullptr) {
        cout << "No hay suscripciones." << endl;
        return;
    }
    Suscripcion aux;
    long pos = 0;
    int renovadas = 0;
    while (fread(&aux, sizeof(Suscripcion), 1, a) == 1) {
        bool vigente = aux.vigente(hoy);
        if (!vigente && aux.getRenovacionAutomatica() && aux.getEstado()) {
            aux.renovacionMensual();
            fseek(a, pos, SEEK_SET);
            fwrite(&aux, sizeof(Suscripcion), 1, a);
            fseek(a, 0, SEEK_CUR);
            renovadas++;
        }
        pos += sizeof(Suscripcion);
    }
    fclose(a);
    cout << "Renovaciones aplicadas: " << renovadas << endl;
}

void SuscripcionManager::SuscripcionCout(Suscripcion s) {
    cout << endl;
    cout << "ID Suscripcion: " << s.getIdSuscripcion() << endl;
    cout << "ID Socio: " << s.getIdSocio() << endl;
    cout << "Inicio: "; s.getFechaInicio().mostrar(); cout << endl;
    cout << "Fin: "; s.getFechaFin().mostrar(); cout << endl;
    cout << "Estado: " << (s.getEstado() ? 1 : 0) << endl;
    cout << "Renovacion automatica: " << (s.getRenovacionAutomatica() ? 1 : 0) << endl;
    cout << "----------------------------";
}
