#include <iostream>
#include <cstdio>
#include "PrestamoManager.h"
#include <vector>
using namespace std;

void PrestamoManager::CargarPrestamo() {
    Prestamo p;

    int idSocio, idNuevo = 1;
    char isBn[20];
    Fecha fechaPrestamo, fechaDevolucion;

    cout << "Ingrese el Id del socio: ";
    cin >> idSocio;
    cin.ignore();
    cout << "Ingrese el isBn: ";
    cin.getline(isBn, 20);
    cout << "Ingrese la fecha del prestamo: ";
    fechaPrestamo.cargar();
    cout << "Ingrese la fecha de devolucion: ";
    fechaDevolucion.cargar();

    p.setIdSocio(idSocio);
    p.setIsBn(isBn);
    p.setFechaPrestamo(fechaPrestamo);
    p.setFechaDevolucion(fechaDevolucion);
    p.setEstado(true);

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
            PrestamoCout(aux);
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
        cout << "No hay ningun libro agregado hasta el momento" << endl;
        return;
    }


    Prestamo aux;
    bool encontrado = false;
    while(fread(&aux,sizeof(Prestamo), 1, archivo ) == 1) {
        if(aux.getIdSocio() == id) {
            encontrado = true;
            PrestamoCout(aux);
            break;
        }
    }

    fclose(archivo);

    if(!encontrado) {
        cout << "No encontramos ningun prestamo" << endl;
    }
}

void PrestamoManager::BorrarPrestamo() {
    int id;
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
            cout << "\nPrestamo encontrado y eliminado:\n";
            PrestamoCout(aux);
        } 
        else {
            prestamos.push_back(aux);   // guardar resto de prestamos
        }
    }
    fclose(archivo);

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

    cout << "Prestamo eliminado correctamente." << endl;
}

void PrestamoManager::PrestamoCout(Prestamo p) {
    cout << endl << "ID del prestamo: " << p.getIdPrestamo() << endl;
    cout << "ID del socio: " << p.getIdSocio() << endl;
    cout << "ISBN: " << p.getIsBn() << endl;
    cout << "Fecha del prestamo: " << p.getFechaPrestamo().getDia() << "/" << p.getFechaPrestamo().getMes() << "/" << p.getFechaPrestamo().getAnio() << endl;
    cout << "Fecha de devolucion: " << p.getFechaDevolucion().getDia() << "/" << p.getFechaDevolucion().getMes() << "/" << p.getFechaDevolucion().getAnio() << endl;
    cout << "Estado: " << (p.getEstado() == true ? "El prestamo esta activo" : "El prestamo esta inactivo") << endl;
    cout << "----------------------------";
}