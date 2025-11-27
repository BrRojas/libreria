#include <iostream>
#include <cstdio>
#include <cstring>
#include "AutorManager.h"
using namespace std;

static const char* AUTORES_FILE = "autores.dat";

void AutorManager::AutorCout(Autor a){
    a.mostrar();
}

void AutorManager::CargarAutor(){
    Autor a;
    // Cargar datos (incluye pedir ID), luego lo sobreescribimos con idNuevo
    a.cargar();

    int idNuevo = 1;
    FILE* p = fopen(AUTORES_FILE, "rb");
    if (p != NULL) {
        fseek(p, 0, SEEK_END);
        long bytes = ftell(p);
        if (bytes > 0) idNuevo = (int)(bytes / sizeof(Autor)) + 1;
        fclose(p);
    }
    a.setIdAutor(idNuevo);

    FILE* f = fopen(AUTORES_FILE, "ab");
    if (!f){ cout << "No se pudo abrir el archivo de autores." << endl; return; }
    if (fwrite(&a, sizeof(Autor), 1, f) != 1){ cout << "Error guardando autor." << endl; fclose(f); return; }
    fclose(f);
    cout << "Autor guardado correctamente. ID asignado: " << idNuevo << endl;
}

void AutorManager::MostrarAutores(){
    FILE* f = fopen(AUTORES_FILE, "rb");
    if (!f){ cout << "No hay autores." << endl; return; }
    Autor a;
    cout << "===== LISTA DE AUTORES =====" << endl;
    while (fread(&a, sizeof(Autor), 1, f) == 1){
        AutorCout(a);
    }
    fclose(f);
}

void AutorManager::BuscarPorIdAutor(){
    int id; cout << "Ingresar ID de autor: "; cin >> id;
    while(id <= 0){ cout << "ID invalida, reintente: "; cin >> id; }
    FILE* f = fopen(AUTORES_FILE, "rb");
    if (!f){ cout << "No hay autores." << endl; return; }
    Autor a; bool encontrado = false;
    while (fread(&a, sizeof(Autor), 1, f) == 1){
        if (a.getIdAutor() == id){ encontrado = true; AutorCout(a); break; }
    }
    fclose(f);
    if (!encontrado) cout << "No se encontro un autor con ese ID." << endl;
}

void AutorManager::ModificarAutor(){
    int id; cout << "ID de autor a modificar: "; cin >> id;
    FILE* f = fopen(AUTORES_FILE, "rb+");
    if (!f){ cout << "No hay autores." << endl; return; }
    Autor a; long pos = 0; bool ok = false;
    while (fread(&a, sizeof(Autor), 1, f) == 1){
        if (a.getIdAutor() == id){ ok = true; break; }
        pos += sizeof(Autor);
    }
    if (!ok){ fclose(f); cout << "No se encontro el autor." << endl; return; }

    cout << "Autor actual:" << endl; AutorCout(a); cout << endl;
    int opt;

    cout << "Modificar nombre? (1=si, 0=no): "; cin >> opt;
    if (opt == 1){
        cin.ignore();
        char nombre[40]; cout << "Nuevo nombre: "; cin.getline(nombre, 40);
        a.setNombre(nombre);
    }
    cout << "Modificar nacionalidad? (1=si, 0=no): "; cin >> opt;
    if (opt == 1){
        cin.ignore();
        char nac[30]; cout << "Nueva nacionalidad: "; cin.getline(nac, 30);
        a.setNacionalidad(nac);
    }
    cout << "Modificar fecha de nacimiento? (1=si, 0=no): "; cin >> opt;
    if (opt == 1){
        Fecha fN; cout << "Nueva fecha de nacimiento:" << endl; fN.cargar(); a.setFechaNacimiento(fN);
    }

    cout << "Confirmar guardado? (1=si, 0=no): "; cin >> opt;
    if (opt == 1){
        fseek(f, pos, SEEK_SET);
        if (fwrite(&a, sizeof(Autor), 1, f) != 1){ cout << "Error al guardar." << endl; fclose(f); return; }
        cout << "Autor actualizado correctamente." << endl;
    } else {
        cout << "Cambios descartados." << endl;
    }
    fclose(f);
}

void AutorManager::BorrarAutor(){
    int id; cout << "ID de autor a borrar: "; cin >> id;
    FILE* in = fopen(AUTORES_FILE, "rb");
    if (!in){ cout << "No hay autores." << endl; return; }
    FILE* out = fopen("autores.tmp", "wb");
    if (!out){ fclose(in); cout << "No se pudo abrir archivo temporal." << endl; return; }

    Autor a; bool borrado = false;
    while (fread(&a, sizeof(Autor), 1, in) == 1){
        if (a.getIdAutor() == id){ borrado = true; continue; }
        fwrite(&a, sizeof(Autor), 1, out);
    }
    fclose(in); fclose(out);
    // Reemplazar archivos
    remove(AUTORES_FILE);
    rename("autores.tmp", AUTORES_FILE);
    cout << (borrado ? "Autor borrado." : "No se encontro el autor.") << endl;
}
