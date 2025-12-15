#include <iostream>
#include <cstdio>
#include <ctime>
#include "SocioManager.h"
#include "SuscripcionManager.h"
#include "CSocio.h"
#include "VetadosManager.h"
#include "rlutil.h"
using namespace std;

static const char* SUSC_FILE = "suscripciones.dat";
static const char* SOCIOS_FILE = "Socios.dat";

//   Verificamos  si existe un socio en Socios.dat
static bool existeSocio(int id) {
    FILE* f = fopen(SOCIOS_FILE, "rb");
    if (!f) return false;

    Socio s;
    while (fread(&s, sizeof(Socio), 1, f) == 1) {
        if (s.getIdSocio() == id) {
            fclose(f);
            return true;
        }
    }

    fclose(f);
    return false;
}

//  Verificamos si ya tiene una suscripcion activa
bool SuscripcionManager::tieneSuscripcionActiva(int idSocio) {
    VerificarSuscripcionesVencidas();  // actualiza vencidas antes de validar

    FILE* f = fopen(SUSC_FILE, "rb");
    if (!f) return false;

    Suscripcion aux;
    while (fread(&aux, sizeof(Suscripcion), 1, f) == 1) {
        if (aux.getIdSocio() == idSocio && aux.getEstado()) {
            fclose(f);
            return true;
        }
    }
    fclose(f);
    return false;
}

void SuscripcionManager::CargarSuscripcion() {
    Suscripcion s;
    int idSocio;
    Fecha ini, fin;

    cout << "Ingrese el ID del Socio: " << endl;
    cin >> idSocio;

    if (idSocio <= 0) {
        cout << "ID invalido." << endl;
        return;
    }

    // Validamos que exista el socio
    if (!existeSocio(idSocio)) {
        cout << "ERROR: No existe un socio con ese ID" << endl;
        return;
    }

    // Validamos que NO este vetado
    VetadosManager vm;
    if (vm.EstaVetado(idSocio)) {
        cout << "ERROR: Este socio este VETADO y no puede obtener suscripcion" << endl;
        return;
    }

    // Validamos si ya tiene suscripcion activa
    if (tieneSuscripcionActiva(idSocio)) {
        char opc;
        cout << "ATENCION: Este socio YA tiene una suscripcion activa" << endl;
        cout << "Desea agregar otra igualmente? (s/n): " << endl;
        cin >> opc;

        if (opc != 's' && opc != 'S') {
            cout << "Operacion cancelada." << endl;
            return;
        }
    }


    cout << "INICIA SU SUSCRPCION!" << endl;
    ini.cargarFechaActual();   // fecha de inicio = hoy
    fin = ini;                 // copiamos inicio en fin para modificar
    fin.sumarDias(41);

    s.setIdSocio(idSocio);
    s.setFechaInicio(ini);
    s.setFechaFin(fin);
    s.setEstado(true);

    // Calcular ID de suscripcion
    int idNuevo = 1;
    FILE* p = fopen(SUSC_FILE, "rb");
    if (p != NULL) {
        fseek(p, 0, SEEK_END);
        long bytes = ftell(p);
        if (bytes > 0) idNuevo = (int)(bytes / sizeof(Suscripcion)) + 1;
        fclose(p);
    }
    s.setIdSuscripcion(idNuevo);

    // GUARDAR EN ARCHIVO
    FILE* a = fopen(SUSC_FILE, "ab");
    if (!a) {
        cout << "No se pudo abrir el archivo de suscripciones.\n";
        return;
    }

    fwrite(&s, sizeof(Suscripcion), 1, a);
    fclose(a);

    cout << "Suscripcion guardada correctamente.\n";
}

void SuscripcionManager::VerificarSuscripcionesVencidas() {
    FILE* a = fopen(SUSC_FILE, "rb+");
    if (a == nullptr) {
        return;
    }

Suscripcion aux;
long pos = 0;
Fecha hoy;
hoy.cargarFechaActual();

while (fread(&aux, sizeof(Suscripcion), 1, a) == 1) {

    if (aux.getEstado()) {
        // Diferencia: fin - hoy
        long diff = aux.getFechaFin().diasEntre(hoy);

        // Si hoy > fechaFin /// diff > 0
        if (diff > 0) {

        // Desactivamos suscripción
        aux.setEstado(false);
        fseek(a, pos, SEEK_SET);
        fwrite(&aux, sizeof(Suscripcion), 1, a);
        fseek(a, 0, SEEK_CUR);

        cout << "Suscripcion vencida detectada. Socio "
                     << aux.getIdSocio() << " marcado como inactivo." << endl;
            }
        }

        pos += sizeof(Suscripcion);
    }

    fclose(a);
}



void SuscripcionManager::MostrarSuscripciones() {
    // Verificar suscripciones vencidas antes de mostrar
    VerificarSuscripcionesVencidas();

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


void SuscripcionManager::SuscripcionCout(Suscripcion s) {
    // ======= BUSCAR NOMBRE DEL SOCIO =======
    char nombreSocio[30] = "Desconocido";

    FILE* fSoc = fopen(SOCIOS_FILE, "rb");
    if (fSoc != nullptr) {
        Socio soc;
        while (fread(&soc, sizeof(Socio), 1, fSoc) == 1) {
            if (soc.getIdSocio() == s.getIdSocio()) {
                strcpy(nombreSocio, soc.getNombre());
                break;
            }
        }
        fclose(fSoc);
    }

    cout << endl;
    cout << "ID Suscripcion: " << s.getIdSuscripcion() << endl;
    cout << "ID Socio: " << s.getIdSocio() << " | Nombre: " << nombreSocio << endl;
    cout << "Inicio: "; s.getFechaInicio().mostrar(); cout << endl;
    cout << "Fin: "; s.getFechaFin().mostrar(); cout << endl;
    cout << "Estado: " << (s.getEstado() ? "Activo" : "Inactivo") << endl;
    cout << "----------------------------";
}

void SuscripcionManager::ModificarSuscripcion() {
    int idBuscado;
    cout << "Ingresar ID de suscripcion a modificar: ";
    cin >> idBuscado;

    FILE* a = fopen(SUSC_FILE, "rb+");
    if (a == nullptr) {
        cout << "No hay suscripciones." << endl;
        return;
    }

    Suscripcion aux;
    long pos = 0;
    bool encontrado = false;

    while (fread(&aux, sizeof(Suscripcion), 1, a) == 1) {
        if (aux.getIdSuscripcion() == idBuscado) {
            encontrado = true;
            break;
        }
        pos += sizeof(Suscripcion);
    }

    if (!encontrado) {
        fclose(a);
        cout << "No se encontro la suscripcion con ese ID." << endl;
        return;
    }

    cout << "Suscripcion actual:" << endl;
    SuscripcionCout(aux);
    cout << endl;

    int opt;

    cout << "Modificar fecha de inicio? (1=si, 0=no): ";
    cin >> opt;
    if (opt == 1) {
        Fecha f;
        cout << "Nueva fecha de inicio:" << endl;
        f.cargar();
        aux.setFechaInicio(f);
    }

    cout << "Modificar fecha de fin? (1=si, 0=no): ";
    cin >> opt;
    if (opt == 1) {
        Fecha f;
        cout << "Nueva fecha de fin:" << endl;
        f.cargar();
        aux.setFechaFin(f);
    }

    cout << "Modificar estado? (1=si, 0=no): ";
    cin >> opt;
    if (opt == 1) {
        int est;
        cout << "Nuevo estado (1=activo, 0=inactivo): ";
        cin >> est;
        aux.setEstado(est == 1);
    }

    cout << "Resumen actualizado:" << endl;
    SuscripcionCout(aux);
    cout << endl;

    cout << "Confirmar guardado? (1=si, 0=no): ";
    cin >> opt;
    if (opt == 1) {
    fseek(a, pos, SEEK_SET);
    if (fwrite(&aux, sizeof(Suscripcion), 1, a) != 1) {
        cout << "Error al guardar los cambios." << endl;
        fclose(a);
        return;
    }

    cout << "Suscripcion actualizada correctamente." << endl;

    fclose(a);
    VerificarSuscripcionesVencidas();
    return;
}
else {
    cout << "Cambios descartados." << endl;
    fclose(a);
}
}

void SuscripcionManager::SumarUnMesPorSocio() {
    int id;
    cout << "Ingresar el ID de socio para sumar un mes a sus suscripciones: ";
    cin >> id;
    while (id <= 0) {
        cout << "Ingresar una id valida (mayor a 0): ";
        cin >> id;
    }

    FILE* a = fopen(SUSC_FILE, "rb+");
    if (a == nullptr) {
        cout << "No hay suscripciones." << endl;
        return;
    }

    Suscripcion aux;
    long pos = 0;
    int cant = 0;
    while (fread(&aux, sizeof(Suscripcion), 1, a) == 1) {
        if (aux.getIdSocio() == id && aux.getEstado()) {
            aux.agregarUnMes();
            fseek(a, pos, SEEK_SET);
            fwrite(&aux, sizeof(Suscripcion), 1, a);
            fseek(a, 0, SEEK_CUR);
            cant++;
        }
        pos += sizeof(Suscripcion);
    }
    fclose(a);
    cout << "Suscripciones actualizadas: " << cant << endl;
}

// --------------Reportes-----------------------------------------

int SuscripcionManager::CantidadActivas() {
    VerificarSuscripcionesVencidas();  // actualiza vencidas antes de contar

    FILE* f = fopen(SUSC_FILE, "rb");
    if (!f) return 0;

    Suscripcion aux;
    int contador = 0;
    while (fread(&aux, sizeof(Suscripcion), 1, f) == 1) {
        if (aux.getEstado()) {
            contador++;
        }
    }
    fclose(f);
    return contador;
}

int SuscripcionManager::CantidadInactivas() {
    VerificarSuscripcionesVencidas();  // actualiza vencidas antes de contar

    FILE* f = fopen(SUSC_FILE, "rb");
    if (!f) return 0;

    Suscripcion aux;
    int contador = 0;
    while (fread(&aux, sizeof(Suscripcion), 1, f) == 1) {
        if (!aux.getEstado()) {
            contador++;
        }
    }
    fclose(f);
    return contador;
}

 //submenu de reportes
    void SuscripcionManager::Reportes() {
        int activas = CantidadActivas();
        int inactivas = CantidadInactivas();

        rlutil::setColor(rlutil::YELLOW);
        cout << "====== REPORTE DE SUSCRIPCIONES ======" << endl;
        cout << "Cantidad de suscripciones activas: " << activas << endl;
        cout << "Cantidad de suscripciones inactivas: " << inactivas << endl;
    }
