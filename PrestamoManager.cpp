#include <iostream>
#include <cstdio>
#include "Beneficios.h"
#include "PrestamoManager.h"
#include "Prestamo.h"
#include <vector>
#include "Fecha.h"
#include "SocioManager.h"
#include "VetadosManager.h"
#include "CSocio.h"
#include "LibroManager.h"
using namespace std;

void PrestamoManager::CargarPrestamo() {
    Prestamo p;

    int idSocio, idNuevo = 1, idLibro;
    Fecha fechaPrestamo, fechaDevolucion;

    bool encontradoSocio = false;

    do {
        cout << "Ingrese el Id del socio: ";
        cin >> idSocio;

        FILE* pSocio = fopen("Socios.dat", "rb");
        if (pSocio == NULL) {
            cout << "No se pudo abrir el archivo." << endl;
            return;
        }

        Socio s;
        encontradoSocio = false;

        while (fread(&s, sizeof(Socio), 1, pSocio) == 1) {
            if (s.getIdSocio() == idSocio) {
                VetadosManager vm;
                if (!vm.EstaVetado(idSocio)) {
                    encontradoSocio = true;
                }
                break;
            }
        }
        fclose(pSocio);

        if (!encontradoSocio) {
            cout << "No existe un socio con ese ID o esta vetado. Intente nuevamente." << endl;
        }
    } while (!encontradoSocio);
    Socio socioData;
    FILE* archSoc = fopen("Socios.dat", "rb");
    if (!archSoc) {
    cout << "No se pudo abrir Socios.dat" << endl;
    return;
}

// buscamos la categoria del socio
    while (fread(&socioData, sizeof(Socio), 1, archSoc) == 1) {
    if (socioData.getIdSocio() == idSocio) break;
}
    fclose(archSoc);

    BeneficiosManager bm;
    int maxPermitidos = bm.MaxPrestamosSegunCategoria(socioData.getCategoria());

// contamos los prestamos activos actuales
    FILE* archPrest = fopen("prestamos.dat", "rb");
    Prestamo pr;
    int activos = 0;

    if (archPrest != NULL) {
        while (fread(&pr, sizeof(Prestamo), 1, archPrest) == 1) {
            if (pr.getIdSocio() == idSocio && pr.getEstado()) {
                activos++;
        }
    }
    fclose(archPrest);
}

// validamos el limite
if (activos >= maxPermitidos) {
    cout << "LIMITE DE PRÉSTAMOS ALCANZADOS" << endl;
    cout << "Categoria del socio: " << socioData.getCategoria() << endl;
    cout << "Maximo permitido: " << maxPermitidos << endl;
    cout << "Prestamos activos actuales: " << activos << endl;
    return;
}


    cin.ignore();
    cout << "Ingrese el ID del libro: ";
    cin >> idLibro;


    LibroManager l;
    if(!l.ManejarStock(idLibro, -1)) {
        cout << "Hubo un problema con el libro del prestamo, intentar devuelta con otro libro" << endl;
        return;
    }

    cout << "Ingrese la fecha del prestamo: ";
    fechaPrestamo.cargar();
    cout << "Ingrese la fecha de devolucion: ";
    fechaDevolucion.cargar();

    p.setIdSocio(idSocio);
    p.setIdLibro(idLibro);
    p.setFechaPrestamo(fechaPrestamo);
    p.setFechaDevolucion(fechaDevolucion);
    p.setEstado(true);
    long dias = fechaPrestamo.diasEntre(fechaDevolucion);
    SocioManager sm;
        if (dias <= 31) {
        sm.SumarPuntos(idSocio, 10);
        }
        else {
        sm.SumarPuntos(idSocio, -20);
        }
    FILE *pArchivo = fopen("prestamos.dat", "rb");
    if(pArchivo != NULL) {
        fseek(pArchivo, 0, SEEK_END);
        idNuevo = ftell(pArchivo) / sizeof(Prestamo) + 1;
        fclose(pArchivo);
    }

    p.setIdPrestamo(idNuevo);

    FILE* archivo = fopen("prestamos.dat", "ab");

    if(archivo == NULL) {
        cout << "No se pudo abrir el archivo de Prestamos" << endl;
        return;
    }

    if(fwrite(&p, sizeof(Prestamo), 1, archivo) != 1) {
        cout << "Error intentando agregar el prestamo." << endl;
        return;
    }
    fclose(archivo);

    cout << "Prestamo guardado correctamente." << endl;
    return;
}

void PrestamoManager::MostrarPrestamos() {
    FILE* archivo = fopen("prestamos.dat", "rb");
    if(archivo != nullptr) {
        cout << "====== LISTA DE PRESTAMOS ======" << endl;
        Prestamo aux;
        while(fread(&aux, sizeof(Prestamo), 1, archivo) == 1) {
            if(aux.getEstado()) {
                PrestamoCout(aux);
            }
        }
        fclose(archivo);
    } else {
        cout << "No se pudo abrir el archivo por lo que no hay prestamos." << endl;
    }
}

void PrestamoManager::BuscarIdPrestamoSocio() {

    int id;
    cout << endl <<"Ingresar el id del Socio del prestamo: ";
    cin >> id;

    while(id <= 0) {
        cout << endl << "Ingresar una id valida (debe ser mayor a 0): ";
        cin >> id;
    }

    FILE* archivo = fopen("prestamos.dat", "rb");
    if(archivo == nullptr) {
        cout << "No hay ningun prestamo agregado hasta el momento" << endl;
        return;
    }


    Prestamo aux;
    bool encontrado = false;
    while(fread(&aux,sizeof(Prestamo), 1, archivo ) == 1) {
        if(aux.getIdSocio() == id) {
            encontrado = true;
            PrestamoCout(aux);
        }
    }

    fclose(archivo);

    if(!encontrado) {
        cout << "No encontramos ningun prestamo" << endl;
    }
}

void PrestamoManager::BorrarPrestamo() {
    int id, idLibro;
    cout << "Ingresar el ID del prestamo: ";
    cin >> id;

    while (id <= 0) {
        cout << "ID inválido. Ingrese un número mayor a 0: ";
        cin >> id;
    }

    FILE* archivo = fopen("prestamos.dat", "rb");
    if (!archivo) {
        cout << "No hay ningún prestamo agregado hasta el momento." << endl;
        return;
    }

    vector<Prestamo> prestamos;
    Prestamo aux;
    bool encontrado = false;

    // Leer todos los prestamos
    while (fread(&aux, sizeof(Prestamo), 1, archivo) == 1) {
        if (aux.getIdPrestamo() == id) {
            encontrado = true;
            aux.setEstado(false);  // Cambiar estado a false
            idLibro = aux.getIdLibro();
            cout << "\nPrestamo encontrado y marcado como inactivo:\n";
            PrestamoCout(aux);
        }
        prestamos.push_back(aux);   // guardar todos los prestamos (incluyendo el modificado)
    }
    fclose(archivo);

    LibroManager l;
    if(!l.ManejarStock(idLibro, 1)) {
        cout << "Hubo un error manejando el stock del libro";
        return;
    }

    if (!encontrado) {
        cout << "No encontramos un prestamo con ese ID." << endl;
        return;
    }

    // reescribimos todo el archivo
    archivo = fopen("prestamos.dat", "wb");
    for (const Prestamo& p : prestamos) { // esto es un for loop que va a loopear por cada prestamo que haya en prestamos (donde guardamos todos los prestamos)
        fwrite(&p, sizeof(Prestamo), 1, archivo);
    }
    fclose(archivo);

    cout << "Prestamo marcado como inactivo correctamente." << endl;
}

// sacar estado logico poniendo estado en false

void PrestamoManager::PrestamoCout(Prestamo p) {
    cout << endl << "ID del prestamo: " << p.getIdPrestamo() << endl;
    cout << "ID del socio: " << p.getIdSocio() << endl;
    cout << "ID Libro: " << p.getIdLibro() << endl;
    cout << "Fecha del prestamo: " << p.getFechaPrestamo().getDia() << "/" << p.getFechaPrestamo().getMes() << "/" << p.getFechaPrestamo().getAnio() << endl;
    cout << "Fecha de devolucion: " << p.getFechaDevolucion().getDia() << "/" << p.getFechaDevolucion().getMes() << "/" << p.getFechaDevolucion().getAnio() << endl;
    cout << "Estado: " << (p.getEstado() == true ? "El prestamo esta activo" : "El prestamo esta inactivo") << endl;
    cout << "----------------------------";
}
