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
  if (!estado) return false;
  // debe estar entre [fechaInicio, fechaFin]
    long desdeInicio = fechaInicio.diasEntre(hoy);   // hoy - inicio
    long hastaFin    = hoy.diasEntre(fechaFin);      // fin - hoy

    return (desdeInicio >= 0 && hastaFin >= 0);
}


void Suscripcion::agregarUnMes(){
  sumarUnMes(fechaFin);
}
