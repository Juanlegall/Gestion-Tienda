#pragma once
#include "claseCompras.h"
#include <cstdio>
#include <cstring>
class ArchivoCompras{
    private:
        char nombre[30];
    public:
        ArchivoCompras(const char *n="Compras.dat"){strcpy(nombre, n);}
        Compra leerRegistro(int pos);
        int contarRegistros();
        int buscarRegistro(int num);
        bool grabarRegistro(Compra reg);
        void modificar(Compra obj, int pos);
         bool crearBackup(const char *nombreB="compras.bak");
        bool restaurarRegistros(const char *nombreB="compras.bak");
        bool baja();
        bool crearBajaFisica();
};
