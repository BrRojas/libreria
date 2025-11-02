# 📚 Proyecto de Librería en C++

### 🧾 Descripción general  
Este proyecto es un **sistema de gestión de librería** desarrollado en **C++**, utilizando **.dat** para guardar y recuperar información de forma persistente.  

El sistema se ejecuta en consola y está estructurado en clases separadas por archivos `.h` y `.cpp`, siguiendo un enfoque modular de Programación Orientada a Objetos (POO).

---

## 🧠 Estructura del proyecto  
```
📦 libreria/
 ┣ 📜 main.cpp
 ┣ 📜 Menu.h / Menu.cpp
 ┣ 📜 Fecha.h / Fecha.cpp
 ┣ 📜 Autor.h / Autor.cpp
 ┣ 📜 Libro.h / Libro.cpp
 ┣ 📜 ArchivoAutor.h / ArchivoAutor.cpp(aun por defini)
 ┣ 📜 ArchivoLibro.h / ArchivoLibro.cpp(aun por definir)
 ┣ 📜 autores.dat(aun por defini)
 ┣ 📜 libros.dat(aun por defini)
 ┣ 📜 Suscripcion.h / Suscripcion.cpp
 ┣ 📜 Prestamos.h / Prestamo.cpp
 ┗ 📜 README.md
```

---

## ⚙️ Requisitos  
- **Code::Blocks** (recomendado) o cualquier IDE C++ con soporte para proyectos  
- Sistema operativo **Windows** o **Linux**

---

## 🚀 Instrucciones para clonar y ejecutar  

### 1️⃣ Clonar el repositorio  
Abrir la terminal (Git Bash o VS Code) y ejecutar:  
```bash
git clone https://github.com/tu-usuario/libreria.git
```
> Reemplazá `tu-usuario` por el nombre real de tu usuario de GitHub.  

Luego entrar a la carpeta del proyecto:
```bash
cd libreria
```

---

### 2️⃣ Abrir el proyecto en Code::Blocks  
1. Abrir **Code::Blocks**  
2. Ir a **File → Open**  
3. Seleccionar la carpeta del proyecto y abrir el archivo del proyecto (`libreria.cbp` o `.workspace`)  
4. Asegurarse de que todos los archivos `.h` y `.cpp` estén agregados (si falta alguno: clic derecho → *Add files...*)

---

### 3️⃣ Compilar y ejecutar  
Presionar **F9** o ir a **Build → Run**.  
El programa mostrará el menú principal con las opciones de gestión (Autores, Libros, etc.).

---

## 🧩 Trabajo en equipo con Git

### Crear una rama para trabajar  
Cada integrante debe crear su propia rama para evitar conflictos:
```bash
git checkout -b ft/nombre-rama
```
Por ejemplo:
```bash
git checkout -b ft/braian-libros
```

Guardar los cambios y subirlos:
```bash
git add .
git commit -m "feat: agrego manejo de libros"
git push --set-upstream origin ft/braian-libros
```

---

### Actualizar el proyecto antes de trabajar  
Antes de empezar una nueva tarea, actualizar la rama principal:
```bash
git pull origin main
```

---

### Hacer un Pull Request (PR)
1. Subir los cambios a tu rama (`git push`)  
2. Entrar al repositorio en GitHub  
3. Crear un **Pull Request** desde tu rama hacia `main`  
4. Esperar la revisión del equipo y luego hacer **merge**  

---

## 💡 Buenas prácticas
- No trabajar directamente en `main`  
- Usar prefijos en las ramas:  
  - `ft/` → nueva funcionalidad  
  - `fix/` → corrección de errores  
- Escribir commits claros:  
  - ✅ `feat: agrego clase Fecha`  
  - ✅ `fix: corrijo error al leer archivo .dat`  
- No subir archivos `.dat` al repositorio (solo código fuente)

---

## 👥 Equipo de desarrollo  
Proyecto desarrollado por el grupo de **Programación en C++ - UTN**  

**Integrantes:**  
- Braian Rojas
- (agregar nombre)
