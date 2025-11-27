#ifndef FECHA_H
#define FECHA_H

class Fecha {
private:
    int dia;
    int mes;
    int anio;

public:
    Fecha();
    Fecha(int d, int m, int a);

    void cargar();
    void mostrar();

    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);
    int getDia();
    int getMes();
    int getAnio();
    long diasEntre(const Fecha& otra) const;
    static int diasEnMes(int m, int a);
};

#endif
