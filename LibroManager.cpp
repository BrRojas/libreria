#include <iostream>
#include <cstdio>
#include "LibroManager.h"
#include "Autor.h"
#include <vector>
#include <cstring>
#include <cctype>
using namespace std;

//se sobre escribio mal
// Pasa una cadena a minúsculas (con límite de tamaño)
static void aMinusculas(const char* origen, char* destino, int tamMax) {
    int i = 0;
    for (; i < tamMax - 1 && origen[i] != '\0'; i++) {
        destino[i] = tolower((unsigned char)origen[i]);
    }
    destino[i] = '\0';
}

// Devuelve true si 'texto' contiene 'filtro' (ignorando mayúsculas/minúsculas)
static bool contieneTextoCI(const char* texto, const char* filtro) {
    char t[100], f[100];
    aMinusculas(texto, t, 100);
    aMinusculas(filtro, f, 100);

    return strstr(t, f) != nullptr;  // substring
}


void LibroManager::CargarLibro() {
    Libro l;

    char isbn[20], genero[35], titulo[40], editorial[35];
    int cantidadEjemplares, vecesPrestado, idAutor, idNuevo = 1;
    bool estado;


    cout << "Ingrese el ID del Autor: ";
    cin >> idAutor;
    cin.ignore();
    cout << "Ingrese el ISBN: ";
    cin.getline(isbn, 20);
    cout << "Ingrese el Genero: ";
    cin.getline(genero, 35);
    cout << "Ingrese el Titulo: ";
    cin.getline(titulo, 40);
    cout << "Ingrese la Editorial: ";
    cin.getline(editorial, 35);
    cout << "Ingrese la Cantidad de Ejemplares: ";
    cin >> cantidadEjemplares;
    cout << "Ingrese la Cantidad de Veces Prestado: ";
    cin >> vecesPrestado;

    l.setIsbn(isbn);
    l.setGenero(genero);
    l.setTitulo(titulo);
    l.setEditorial(editorial);
    l.setCantidadEjemplares(cantidadEjemplares);
    l.setVecesPrestado(vecesPrestado);
    l.setIdAutor(idAutor);

    FILE *p = fopen("libros.dat", "rb");
    if(p != NULL) {
        fseek(p, 0, SEEK_END);
        idNuevo = ftell(p) / sizeof(Libro) + 1;
        fclose(p);
    }

    l.setId(idNuevo);

    FILE* archivo = fopen("libros.dat", "ab");
    
    if(archivo == NULL) {
        cout << "No se pudo abrir el archivo de libros" << endl;
        return;
    }

    if(fwrite(&l, sizeof(Libro), 1, archivo) != 1) {
        cout << "Error intentando agregar el libro." << endl;
        fclose(archivo);
        return;
    }
    fclose(archivo);

    cout << "Libro guardado correctamente." << endl;
    return;
}

void LibroManager::MostrarLibros() {
        FILE* archivo = fopen("libros.dat", "rb");
        if(archivo != nullptr) {
            cout << "====== LISTA DE SOCIOS ======" << endl;
            Libro aux;
            while(fread(&aux, sizeof(Libro), 1, archivo) == 1) {
                if(aux.getCantidadEjemplares() != 0) {
                    LibroCout(aux);
                }
            }
            fclose(archivo);
        } else {
            cout << "No se pudo abrir el archivo por lo que no hay libros." << endl;
        }
}

void LibroManager::BuscarIdLibro() {
    int id;
    cout << endl <<"Ingresar el id del libro: ";
    cin >> id;

    while(id <= 0) {
        cout << endl << "Ingresar una id valida (debe ser mayor a 0): ";
        cin >> id;
    }
    
    FILE* archivo = fopen("libros.dat", "rb");
    if(archivo == nullptr) {
        cout << "No hay ningun libro agregado hasta el momento" << endl;
        return;
    }


    Libro aux;
    bool encontrado = false;
    while(fread(&aux,sizeof(Libro), 1, archivo ) == 1) {
        if(aux.getId() == id) {
            encontrado = true;
            LibroCout(aux);
            break;
        }
    }

    fclose(archivo);

    if(!encontrado) {
        cout << "No encontramos el libro que buscaba" << endl;
    }
}

void LibroManager::BorrarLibro() {
    int id;
    cout << "Ingresar el ID del libro: ";
    cin >> id;

    while (id <= 0) {
        cout << "ID inválido. Ingrese un número mayor a 0: ";
        cin >> id;
    }

    FILE* archivo = fopen("libros.dat", "rb");
    if (!archivo) {
        cout << "No hay ningún libro agregado hasta el momento." << endl;
        return;
    }

    vector<Libro> libros;
    Libro aux;
    bool encontrado = false;

    // Leer todos los libros
    while (fread(&aux, sizeof(Libro), 1, archivo) == 1) {
        if (aux.getId() == id) {
            encontrado = true;
            aux.setCantidadEjemplares(0);
        } 
        libros.push_back(aux);   // guardar todos los libros
    }
    fclose(archivo);

    if (!encontrado) {
        cout << "No encontramos un libro con ese ID." << endl;
        return;
    }

    // reescribimos todo el archivo
    archivo = fopen("libros.dat", "wb");
    for (const Libro& l : libros) { // esto es un for loop que va a loopear por cada libro que haya en libros (donde guardamos todos los libros)
        fwrite(&l, sizeof(Libro), 1, archivo);
    }
    fclose(archivo);

    cout << "Libro eliminado correctamente." << endl;
}

void LibroManager::EditarLibro() {
    int id;
    cout << "Ingrese el ID del libro que desea editar: ";
    cin >> id;

    while (id <= 0) {
        cout << "ID inválido. Ingrese un número mayor a 0: ";
        cin >> id;
    }

    FILE* archivo = fopen("libros.dat", "rb");
    if (!archivo) {
        cout << "No hay ningún libro agregado hasta el momento." << endl;
        return;
    }

    vector<Libro> libros;
    Libro aux;
    bool encontrado = false;

    // Leer todos los libros y buscar el que se quiere editar
    while (fread(&aux, sizeof(Libro), 1, archivo) == 1) {
        if (aux.getId() == id) {
            encontrado = true;
            cout << "\nLibro encontrado, datos actuales:" << endl;
            LibroCout(aux);

            cout << "\n=== ¿Qué campo desea editar? ===" << endl;
            cout << "1. Titulo" << endl;
            cout << "2. Autor (ID)" << endl;
            cout << "3. ISBN" << endl;
            cout << "4. Genero" << endl;
            cout << "5. Editorial" << endl;
            cout << "6. Cantidad de ejemplares" << endl;
            cout << "0. Cancelar" << endl;
            cout << "Ingrese una opción: ";
            int opcion;
            cin >> opcion;

            cin.ignore(); // limpiar buffer
            switch(opcion) {
                case 1: {
                    char titulo[40];
                    cout << "Nuevo titulo: ";
                    cin.getline(titulo, 40);
                    aux.setTitulo(titulo);
                    break;
                }
                case 2: {
                    int idAutor;
                    cout << "Nuevo ID de Autor: ";
                    cin >> idAutor;
                    aux.setIdAutor(idAutor);
                    break;
                }
                case 3: {
                    char isbn[20];
                    cout << "Nuevo ISBN: ";
                    cin.ignore();
                    cin.getline(isbn, 20);
                    aux.setIsbn(isbn);
                    break;
                }
                case 4: {
                    char genero[35];
                    cout << "Nuevo genero: ";
                    cin.getline(genero, 35);
                    aux.setGenero(genero);
                    break;
                }
                case 5: {
                    char editorial[35];
                    cout << "Nueva editorial: ";
                    cin.getline(editorial, 35);
                    aux.setEditorial(editorial);
                    break;
                }
                case 6: {
                    int cantidad;
                    cout << "Nueva cantidad de ejemplares: ";
                    cin >> cantidad;
                    aux.setCantidadEjemplares(cantidad);
                    break;
                }
                case 0:
                    cout << "Edición cancelada." << endl;
                    break;
                default:
                    cout << "Opción inválida." << endl;
            }
        }
        libros.push_back(aux);
    }
    fclose(archivo);

    if (!encontrado) {
        cout << "No encontramos un libro con ese ID." << endl;
        return;
    }

    // Guardar todos los libros (incluido el editado)
    archivo = fopen("libros.dat", "wb");
    for (const Libro& l : libros) {
        fwrite(&l, sizeof(Libro), 1, archivo);
    }
    fclose(archivo);

    cout << "Libro editado correctamente." << endl;

}

bool LibroManager::ManejarStock(int id, int cantidad) {

    FILE* archivo = fopen("libros.dat", "rb");
    if (!archivo) {
        cout << "No hay ningún libro agregado hasta el momento." << endl;
        return false;
    }

    vector<Libro> libros;
    Libro aux;
    bool encontrado = false;

    // Leer todos los libros
    while (fread(&aux, sizeof(Libro), 1, archivo) == 1) {
        if (aux.getId() == id) {
            encontrado = true;
            if(aux.getCantidadEjemplares() + cantidad < 0) {
                cout << "No quedan mas ejemplares del libro" << endl;
                fclose(archivo);
                return false;
            }
            aux.setCantidadEjemplares(aux.getCantidadEjemplares() + cantidad);
        } 
        libros.push_back(aux);   // guardar todos los libros
    }
    fclose(archivo);

    if (!encontrado) {
        cout << "No encontramos un libro con ese ID." << endl;
        return false;
    }

    // reescribimos todo el archivo
    archivo = fopen("libros.dat", "wb");
    for (const Libro& l : libros) { // esto es un for loop que va a loopear por cada libro que haya en libros (donde guardamos todos los libros)
        fwrite(&l, sizeof(Libro), 1, archivo);
    }
    fclose(archivo);

    cout << "Stock del libro actualizado correctamente." << endl;
    return true;
}

void LibroManager::BuscarPorGenero() {
    char generoBuscado[35];

    cin.ignore(); // limpiar el \n que pudo quedar
    cout << "Ingrese el genero a buscar: ";
    cin.getline(generoBuscado, 35);

    FILE* archivo = fopen("libros.dat", "rb");
    if (archivo == nullptr) {
        cout << "No hay libros cargados." << endl;
        return;
    }

    Libro aux;
    bool alguno = false;

    cout << "\n=== LIBROS DEL GENERO: " << generoBuscado << " ===\n";

    while (fread(&aux, sizeof(Libro), 1, archivo) == 1) {
        if (aux.getCantidadEjemplares() > 0 &&
            contieneTextoCI(aux.getGenero(), generoBuscado)) {
            alguno = true;
            LibroCout(aux);
        }
    }

    fclose(archivo);

    if (!alguno) cout << "No se encontraron libros para ese genero." << endl;
}

void LibroManager::BuscarPorTitulo() {
    char tituloBuscado[40];

    cin.ignore();
    cout << "Ingrese parte del titulo a buscar: ";
    cin.getline(tituloBuscado, 40);

    FILE* archivo = fopen("libros.dat", "rb");
    if (archivo == nullptr) {
        cout << "No hay libros cargados." << endl;
        return;
    }

    Libro aux;
    bool alguno = false;

    cout << "\n=== LIBROS QUE COINCIDEN CON: " << tituloBuscado << " ===\n";

    while (fread(&aux, sizeof(Libro), 1, archivo) == 1) {
        if (aux.getCantidadEjemplares() > 0 &&
            contieneTextoCI(aux.getTitulo(), tituloBuscado)) {
            alguno = true;
            LibroCout(aux);
        }
    }

    fclose(archivo);

    if (!alguno) cout << "No se encontraron libros para ese titulo." << endl;
}

void LibroManager::BuscarPorIsbn() {
    char isbnBuscado[20];

    cin.ignore();
    cout << "Ingrese el ISBN a buscar: ";
    cin.getline(isbnBuscado, 20);

    FILE* archivo = fopen("libros.dat", "rb");
    if (archivo == nullptr) {
        cout << "No hay libros cargados." << endl;
        return;
    }

    Libro aux;
    bool alguno = false;

    cout << "\n=== LIBROS QUE COINCIDEN CON EL ISBN: " << isbnBuscado << " ===\n";

    while (fread(&aux, sizeof(Libro), 1, archivo) == 1) {
        if (aux.getCantidadEjemplares() > 0 &&
            contieneTextoCI(aux.getIsbn(), isbnBuscado)) {
            alguno = true;
            LibroCout(aux);
        }
    }

    fclose(archivo);

    if (!alguno) cout << "No se encontraron libros para ese ISBN." << endl;
}

void LibroManager::LibroCout(Libro l) {

// ======= BUSCAR NOMBRE DEL SOCIO =======
char nombreAutor[30] = "Desconocido";

FILE* fAut = fopen("Autores.dat", "rb");
if (fAut != nullptr) {
    Autor a;
    while (fread(&a, sizeof(Autor), 1, fAut) == 1) {
        if (a.getIdAutor() == l.getIdAutor()) {
            strcpy(nombreAutor, a.getNombre());
            break;
        }
    }
    fclose(fAut);
}

    cout << endl << "ID: " << l.getId() << endl;
    cout << "Titulo: " << l.getTitulo() << endl;
    cout << "AutorID: " << l.getIdAutor() << " | Nombre: " << nombreAutor << endl;
    cout << "ISBN: " << l.getIsbn() << endl;
    cout << "Genero: " << l.getGenero() << endl;
    cout << "Editorial: " << l.getEditorial() << endl;
    cout << "Cantidad de ejemplares: " << l.getCantidadEjemplares() << endl;
    cout << "Veces Prestado: " << l.getVecesPrestado() << endl;
    cout << "----------------------------";
}

int LibroManager::CantidadLibrosConStock() {
    FILE* archivo = fopen("libros.dat", "rb");
    if (!archivo) return 0;

    Libro aux;
    int contador = 0;

    while (fread(&aux, sizeof(Libro), 1, archivo) == 1) {
        if (aux.getCantidadEjemplares() > 0) {
            contador++;
        }
    }
    fclose(archivo);
    return contador;
}

int LibroManager::CantidadLibrosSinStock() {
    FILE* archivo = fopen("libros.dat", "rb");
    if (!archivo) return 0;

    Libro aux;
    int contador = 0;

    while (fread(&aux, sizeof(Libro), 1, archivo) == 1) {
        if (aux.getCantidadEjemplares() == 0) {
            contador++;
        }
    }
    fclose(archivo);
    return contador;
}

void LibroManager::ReporteLibrosStock() {
    int conStock = CantidadLibrosConStock();
    int sinStock = CantidadLibrosSinStock();

    cout << "====== REPORTE DE LIBROS ======" << endl;
    cout << "Libros con ejemplares disponibles: " << conStock << endl;
    cout << "Libros sin ejemplares (stock 0):   " << sinStock << endl;
}
