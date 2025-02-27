#pragma once
#include "claseCategoria.h"
#include <cstring>
class ArchivoCategoria{
    private:
        char nombre[30];
    public:
        ArchivoCategoria(const char *n="categoria.dat"){
            strcpy(nombre, n);
        }
        Categoria leerRegistro(int pos);
        int contarRegistros();
        bool grabarRegistro(Categoria reg);
        void modificar (Categoria obj, int num);
        int buscarRegistro (int num);
         bool crearBackup(const char *nombreB="categoria.bak");
        bool restaurarRegistros(const char *nombreB="categoria.bak");
        bool baja();
        bool crearBajaFisica();
};
