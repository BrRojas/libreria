#include "Suscripcion.h"


static void sumarUnMes(Fecha &f){
    int d = f.getDia();
    int m = f.getMes();
    int a = f.getAnio();
    m += 1;
    if (m > 12){ m = 1; a += 1; }
    int dim = Fecha::diasEnMes(m, a);
    if (d > dim) d = dim;
    f.setDia(d);
    f.setMes(m);
    f.setAnio(a);
}

Suscripcion::Suscripcion(){
  idSuscripcion = 0;
  idSocio = 0;
  estado = false;
}

void Suscripcion::setIdSuscripcion(int v){ idSuscripcion = v; }
void Suscripcion::setIdSocio(int v){ idSocio = v; }
void Suscripcion::setFechaInicio(Fecha f){ fechaInicio = f; }
void Suscripcion::setFechaFin(Fecha f){ fechaFin = f; }
void Suscripcion::setEstado(bool e){ estado = e; }

int Suscripcion::getIdSuscripcion(){ return idSuscripcion; }
int Suscripcion::getIdSocio(){ return idSocio; }
Fecha Suscripcion::getFechaInicio(){ return fechaInicio; }
Fecha Suscripcion::getFechaFin(){ return fechaFin; }
bool Suscripcion::getEstado(){ return estado; }

bool Suscripcion::vigente(const Fecha& hoy){
  Fecha h = hoy;
  if (!estado) return false;
  // h debe estar entre [fechaInicio, fechaFin]
  if (h.diasEntre(fechaInicio) > 0) return false; // h < inicio
  if (fechaFin.diasEntre(h) > 0) return false;    // h > fin
  return true;
}

void Suscripcion::agregarUnMes(){
  sumarUnMes(fechaFin);
}
