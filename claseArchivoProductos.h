#pragma once
#include "claseProductos.h"
#include <cstdio>
#include <cstring>
class ArchivoProducto{
    private:
        char nombre[30];
    public:
        ArchivoProducto(const char *n="productos.dat"){strcpy(nombre, n);}
        Producto leerRegistro(int pos);
        int contarRegistros();
        int buscarRegistro(int num);
        bool grabarRegistro(Producto reg);
        void modificar(Producto obj, int pos);
         bool crearBackup(const char *nombreB="productos.bak");
        bool restaurarRegistros(const char *nombreB="productos.bak");
        bool baja();
        bool crearBajaFisica();
};
