#pragma once
#include "claseClientes.h"
#include "claseArchivoClientes.h"

class clientesManager{
    public:
    void agregarClientes();
    void Mostrar(Clientes obj);
    void bajaFisica();
    void buscarCliente();
    void modificarPropiedades();
    void listarTodosClientes();
    ArchivoClientes archivoClientes;
    Clientes aux;
    void BajaLogica();
    void AltaLogica();
    void guardarBackup();
    void restaurarArchivo();
    private:
};
