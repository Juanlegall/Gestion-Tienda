#pragma once

class Fecha{
  private:
    int dia;
    int mes;
    int anio;

  public:
    Fecha(int d=0, int m=0, int a=0){
        dia = d;
        mes = m;
        anio = a;
    }

    void cargarFecha();
    void mostrarFecha();
    int getDia();
    int getMes();
    int getAnio();
    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);

};


