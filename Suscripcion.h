#include "Fecha.h"

class Suscripcion {
  int idSuscripcion;
  int idSocio;
  Fecha fechaInicio;
  Fecha fechaFin;
  bool estado;

  public:
      Suscripcion();
  void setIdSuscripcion(int);
  void setIdSocio(int);
  void setFechaInicio(Fecha);
  void setFechaFin(Fecha);
  void setEstado(bool);
  int  getIdSuscripcion();
  int  getIdSocio();
  Fecha getFechaInicio();
  Fecha getFechaFin();
  bool getEstado();

  bool vigente(const Fecha& hoy);
  void agregarUnMes();
};
