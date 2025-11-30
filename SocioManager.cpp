#include <iostream>
#include "CSocio.h"
#include <cstdio>
#include "SocioManager.h"
#include "VetadosManager.h"
using namespace std;


void SocioManager::CargarSocio() {
    Socio s;

    int id;
    char nombre [30];
    char telefono[15];
    char estado;
    char donacion;
    cout << "Ingrese ID de socio: ";
    cin >> id;

    // Validar ID punto que marco el profesor
    FILE* p = fopen("Socios.dat", "rb");
    if (p != NULL) {
        Socio temp;
        while (fread(&temp, sizeof(Socio), 1, p) == 1) {
            if (temp.getIdSocio() == id) {
                cout << "ERROR: El ID " << id << " ya existe." << endl;
                fclose(p);
                return;
            }
        }
        fclose(p);
    }

    s.setIdSocio(id);
    cin.ignore();

    cout << "Ingrese nombre: ";
    cin.getline(nombre, 50);
    s.setNombre(nombre);

    cout << "Ingrese telefono: ";
    cin.ignore();
    cin.getline(telefono, 15);
    s.setTelefono(telefono);


    cout << "¿Está activo? (1=si, 0=no): ";
    cin >> estado;

    while (estado != '0' && estado != '1') {
        cout << "ERROR. Ingrese solo 1 o 0: ";
        cin >> estado;
    }
    s.setEstado(estado);

    cout << "¿Incluye donacion? (1=si, 0=no): ";
    cin >> donacion;

    while (donacion != '0' && donacion != '1') {
        cout << "ERROR. Ingrese solo 1 o 0: ";
        cin >> donacion;
    }

    s.setIncluyeDonacion(donacion);

    p = fopen("Socios.dat", "ab");
    if (p == NULL) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }
    s.setPuntos(100);
    s.setCategoria("Bronce");

    fwrite(&s, sizeof(Socio), 1, p);
    fclose(p);
    cout << "Socio guardado correctamente." << endl;

}

void SocioManager::MostrarSocios() {
    FILE* p = fopen("Socios.dat", "rb");
    if (p == NULL) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    Socio s;

    cout << "====== LISTA DE SOCIOS ======" << endl;

    while (fread(&s, sizeof(Socio), 1, p) == 1) {
        cout << "Nombre: " << s.getNombre() << endl;
        cout << "ID: " << s.getIdSocio() << endl;
        cout << "Categoria: " << s.getCategoria() << endl;
        cout << "Puntos: " << s.getPuntos() << endl;
        cout << "Telefono: " << s.getTelefono() << endl;
        cout << "Estado: " << (s.getEstado() ? "Activo" : "Inactivo") << endl;
        cout << "Incluye donacion: " << (s.getIncluyeDonacion() ? "Si" : "No") << endl;
        cout << "----------------------------" << endl;
    }
        fclose(p);
}

void SocioManager::BuscarIdSocio() {
    FILE* p = fopen("Socios.dat", "rb");
    if (p == NULL) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    int buscado;
    cout << "Ingrese ID a buscar: ";
    cin >> buscado;

    Socio s;
    bool encontrado = false;

    while (fread(&s, sizeof(Socio), 1, p) == 1) {
        if (s.getIdSocio() == buscado) {
            cout << "SOCIO ENCONTRADO:" << endl;
            cout << "ID: " << s.getIdSocio() << endl;
            cout << "Nombre: " << s.getNombre() << endl;
            cout << "Categoria: " << s.getCategoria() << endl;
            cout << "Telefono: " << s.getTelefono() << endl;
            cout << "Estado: " << (s.getEstado() ? "Activo" : "Inactivo") << endl;
            cout << "Incluye donacion: " << (s.getIncluyeDonacion() ? "Si" : "No") << endl;
            VetadosManager vm;
            if (vm.EstaVetado(buscado)) {
                cout << "ATENCION: ESTE SOCIO ESTA VETADO" << endl;
            }
            encontrado = true;
            break;
        }
    }

    if (!encontrado)
        cout << "No existe un socio con ese ID." << endl;

    fclose(p);
}

bool SocioManager::ExisteSocio(int idBuscado) {
    FILE* p = fopen("Socios.dat", "rb");
    if (!p) return false;

    Socio s;

    while (fread(&s, sizeof(Socio), 1, p) == 1) {
        if (s.getIdSocio() == idBuscado) {
            fclose(p);
            return true;
        }
    }

    fclose(p);
    return false;
}


void SocioManager::SumarPuntos(int idSocio, int puntos) {
    FILE* f = fopen("Socios.dat", "rb+");
    if (!f) return;

    Socio s;
    long pos = 0;

    while (fread(&s, sizeof(Socio), 1, f) == 1) {
        if (s.getIdSocio() == idSocio) {

            int nuevosPuntos = s.getPuntos() + puntos;
            if (nuevosPuntos < 0) nuevosPuntos = 0;

            s.setPuntos(nuevosPuntos);

            if (nuevosPuntos < 500) s.setCategoria("Bronce");
            else if (nuevosPuntos < 1000) s.setCategoria("Plata");
            else if (nuevosPuntos < 1500) s.setCategoria("Oro");
            else s.setCategoria("Platino");

            fseek(f, pos, SEEK_SET);
            fwrite(&s, sizeof(Socio), 1, f);
            break;
        }
        pos += sizeof(Socio);
    }

    fclose(f);
}

 void SocioManager::SumarPuntosManual() {
    int id, pts;

    cout << "Ingrese ID del socio: ";
    cin >> id;

    FILE* f = fopen("Socios.dat", "rb");
    if (!f) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    Socio s;
    long pos = 0;
    bool encontrado = false;

    while (fread(&s, sizeof(Socio), 1, f) == 1) {
        if (s.getIdSocio() == id) {
            encontrado = true;
            break;
        }
        pos += sizeof(Socio);
    }
    fclose(f);

    if (!encontrado) {
        cout << "No existe un socio con ese ID." << endl;
        return;
    }

    cout << "=== DATOS ACTUALES ===" << endl;
    cout << "Categoria: " << s.getCategoria() << endl;
    cout << "Puntos: " << s.getPuntos() << endl;
    cout << "\nIngrese puntos a sumar (negativo = restar): " << endl;
    cin >> pts;

    SumarPuntos(id, pts);

    f = fopen("Socios.dat", "rb");
    fseek(f, pos, SEEK_SET);
    fread(&s, sizeof(Socio), 1, f);
    fclose(f);

    cout << "=== DATOS ACTUALIZADOS ===" << endl;
    cout << "ID: " << s.getIdSocio() << endl;
    cout << "Categoria nueva: " << s.getCategoria() << endl;
    cout << "Puntos nuevos: " << s.getPuntos() << endl;

}

void SocioManager::ModificarSocio() {
    int idBuscado;
    cout << "Ingrese el ID del socio a modificar: ";
    cin >> idBuscado;

    FILE* f = fopen("Socios.dat", "rb+");
    if (!f) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    Socio s;
    long pos = 0;
    bool encontrado = false;

    // Buscamos el socio por ID
    while (fread(&s, sizeof(Socio), 1, f) == 1) {
        if (s.getIdSocio() == idBuscado) {
            encontrado = true;
            break;
        }
        pos += sizeof(Socio);
    }

    if (!encontrado) {
        cout << "No existe un socio con ese ID." << endl;
        fclose(f);
        return;
    }

    cout << "=== DATOS ACTUALES ===" << endl;
    cout << "Nombre: " << s.getNombre() << endl;
    cout << "Telefono: " << s.getTelefono() << endl;
    cout << "Estado (1 activo / 0 inactivo): " << s.getEstado() << endl;
    cout << "Incluye donacion (1 si / 0 no): " << s.getIncluyeDonacion() << endl;
    cout << "Puntos: " << s.getPuntos() << endl;
    cout << "Categoria: " << s.getCategoria() << endl;

    cout << "=== MODIFICANDO DATOS ===" << endl;

    char opcion;
    char NuevoDato[50];

    // Modificamos nombre
    cout << "¿Modificar nombre? (s/n): ";
    cin >> opcion;
    cin.ignore();
    if (opcion == 's' || opcion == 'S') {
        cout << "Nuevo nombre: ";
        cin.getline(NuevoDato, 50);
        s.setNombre(NuevoDato);
    }

    // Modificamos telefono
    cout << "¿Modificar telefono? (s/n): ";
    cin >> opcion;
    cin.ignore();
    if (opcion == 's' || opcion == 'S') {
        cout << "Nuevo telefono: ";
        cin.getline(NuevoDato, 15);
        s.setTelefono(NuevoDato);
    }

    // Modificamos estado
    cout << "¿Modificar estado (1 activo / 0 inactivo)? (s/n): ";
    cin >> opcion;
    if (opcion == 's' || opcion == 'S') {
        char est;
        cout << "Nuevo estado: ";
        cin >> est;
        while (est != '0' && est != '1') {
            cout << "ERROR. Ingrese 1 o 0: ";
            cin >> est;
        }
        s.setEstado(est);
    }

    // Modificamos donacion
    cout << "¿Modificar donacion (1 si / 0 no)? (s/n): ";
    cin >> opcion;
    if (opcion == 's' || opcion == 'S') {
        char don;
        cout << "Nuevo valor (1 si / 0 no): ";
        cin >> don;
        while (don != '0' && don != '1') {
            cout << "ERROR. Ingrese 1 o 0: ";
            cin >> don;
        }
        s.setIncluyeDonacion(don);
    }

    // Confirmacion
    cout << "\n¿Desea guardar los cambios? (s/n): ";
    cin >> opcion;
    if (opcion != 's' && opcion != 'S') {
        cout << "Cambios cancelados." << endl;
        fclose(f);
        return;
    }

    // Guardamos en archivo
    fseek(f, pos, SEEK_SET);
    fwrite(&s, sizeof(Socio), 1, f);

    fclose(f);

    cout << "\nDatos actualizados correctamente." << endl;
}



