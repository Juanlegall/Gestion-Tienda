#pragma once
#include "claseVentas.h"
#include <cstdio>
#include <cstring>
class ArchivoVenta{
    private:
        char nombre[30];
    public:
        ArchivoVenta(const char *n="venta.dat"){strcpy(nombre, n);}
        Venta leerRegistro(int pos);
        int contarRegistros();
        int buscarRegistro(int num);
        bool grabarRegistro(Venta reg);
        void modificar(Venta obj, int pos);
        bool crearBackup(const char *nombreB="ventas.bak");
        bool restaurarRegistros(const char *nombreB="ventas.bak");
        bool baja();
        bool crearBajaFisica();
};
