#include "Fecha.h"

class Suscripcion {
  int idSuscripcion;
  int idSocio;
  Fecha fechaInicio;
  Fecha fechaFin;
  bool estado;
  bool renovacionAutomatica;

  public:
      Suscripcion();
  void setIdSocio(int);
  void setFechaInicio(Fecha);
  void setFechaFin(Fecha);
  void setEstado(bool);
  void setRenovacionAutomatica(bool);
  int  getIdSocio();
  Fecha getFechaInicio();
  Fecha getFechaFin();
  bool getEstado();
  bool getRenovacionAutomatica();

  bool vigente(const Fecha& hoy);
  void renovacionMensual();
};
