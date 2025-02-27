#pragma once
#include "claseDetalle.h"
#include <cstdio>
#include <cstring>
class ArchivoDetalle{
    private:
        char nombre[30];
    public:
        ArchivoDetalle(const char *n="detalle.dat"){strcpy(nombre, n);}
        Detalle leerRegistro(int pos);
        int contarRegistros();
        int buscarRegistro(int num);
        bool grabarRegistro(Detalle reg);
        void modificar(Detalle obj, int pos);
        bool crearBackup(const char *nombreB="detalle.bak");
        bool restaurarRegistros(const char *nombreB="detalle.bak");
        bool baja();
        bool crearBajaFisica();
};
