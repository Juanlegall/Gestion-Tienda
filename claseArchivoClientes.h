#pragma once
#include "claseClientes.h"
#include <cstdio>
class ArchivoClientes{
    private:
        char nombre[30];
    public:
        ArchivoClientes(const char *n="clientes.dat"){
            strcpy(nombre, n);
        }
        Clientes leerRegistro(int pos);
        int contarRegistros();
        int buscarRegistro(int num);
        bool grabarRegistro(Clientes reg);
        void modificar(Clientes obj, int pos);
        bool crearBackup(const char *nombreB="clientes.bak");
        bool restaurarRegistros(const char *nombreB="clientes.bak");
        bool baja();
        bool crearBajaFisica();
};
