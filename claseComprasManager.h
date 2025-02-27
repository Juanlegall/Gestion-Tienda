#pragma once
#include "claseCompras.h"
#include "claseArchivoCompras.h"
#include "claseProductos.h"
#include "claseArchivoProductos.h"
class CompraManager{
    public:
    void agregarCompra();
    void Mostrar(Compra obj);
    void buscarCompra();
    void modificarPropiedades();
    void listarCompras();
    ArchivoCompras archivocompras;
    Compra aux;
    void BajaLogica();
    void AltaLogica();
    Producto producto;
     ArchivoProducto archProducto;
    void sumarstock(const char *nombre, int cantidad);
     void bajaFisica();
    void guardarBackup();
    void restaurarArchivo();
    private:
};
