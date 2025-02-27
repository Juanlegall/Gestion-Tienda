#pragma once
#include "claseFecha.h"
class Venta{
private:
    int codigo;
    Fecha fecha;
    int codigoCliente;
    float total;
    int metodo;
    bool entrega;
    char direccion[30];
    bool estado;

public:
    void cargarCadena(char *pal, int tam);
    void Cargar();
    int getCodigo();
    Fecha getFecha();
    int getCodigoCliente();
    int getMetodo();
    float getTotal();
    bool getEntrega();
    const char* getDireccion();
    bool getEstado();
    void setCodigo(int num);
    void setTotal(float t);
    void setFecha(Fecha f);
    void setCodigoCliente(int c);
    void setMetodo(int m);
    void setEntrega(bool e);
    void setDireccion(const char *direc);
    void setEstado(bool e);
};
