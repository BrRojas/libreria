#include "Suscripcion.h"

static int cmpFecha(Fecha a, Fecha b) {
    if (a.getAnio() != b.getAnio()) return (a.getAnio() < b.getAnio()) ? -1 : 1;
    if (a.getMes() != b.getMes())   return (a.getMes()   < b.getMes())   ? -1 : 1;
    if (a.getDia() != b.getDia())   return (a.getDia()   < b.getDia())   ? -1 : 1;
    return 0;
}

static int diasEnMes(int m, int a){
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    if (m == 2){
        bool bisiesto = (a % 400 == 0) || (a % 4 == 0 && a % 100 != 0);
        return bisiesto ? 29 : 28;
    }
    return 30;
}

static void sumarUnMes(Fecha &f){
    int d = f.getDia();
    int m = f.getMes();
    int a = f.getAnio();
    m += 1;
    if (m > 12){ m = 1; a += 1; }
    int dim = diasEnMes(m, a);
    if (d > dim) d = dim;
    f.setDia(d);
    f.setMes(m);
    f.setAnio(a);
}

Suscripcion::Suscripcion(){
  idSuscripcion = 0;
  idSocio = 0;
  estado = false;
  renovacionAutomatica = false;
}

void Suscripcion::setIdSuscripcion(int v){ idSuscripcion = v; }
void Suscripcion::setIdSocio(int v){ idSocio = v; }
void Suscripcion::setFechaInicio(Fecha f){ fechaInicio = f; }
void Suscripcion::setFechaFin(Fecha f){ fechaFin = f; }
void Suscripcion::setEstado(bool e){ estado = e; }
void Suscripcion::setRenovacionAutomatica(bool r){ renovacionAutomatica = r; }

int Suscripcion::getIdSuscripcion(){ return idSuscripcion; }
int Suscripcion::getIdSocio(){ return idSocio; }
Fecha Suscripcion::getFechaInicio(){ return fechaInicio; }
Fecha Suscripcion::getFechaFin(){ return fechaFin; }
bool Suscripcion::getEstado(){ return estado; }
bool Suscripcion::getRenovacionAutomatica(){ return renovacionAutomatica; }

bool Suscripcion::vigente(const Fecha& hoy){
  Fecha h = hoy;
  if (!estado) return false;
  if (cmpFecha(h, fechaInicio) < 0) return false;
  if (cmpFecha(h, fechaFin) > 0) return false;
  return true;
}

void Suscripcion::renovacionMensual(){
  if(!renovacionAutomatica) return;
  sumarUnMes(fechaFin);
}
