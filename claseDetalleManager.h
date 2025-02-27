#pragma once
#include "claseDetalle.h"
#include "claseArchivoDetalle.h"
#include "claseProductos.h"
#include "claseArchivoProductos.h"

class DetalleManager{
    public:
    void agregarDetalle();
    void Mostrar(Detalle obj);
    void modificarPropiedades();
    void listarlosDetalles();
    void buscarDetalle();
    ArchivoDetalle archivoDetalles;
    Detalle aux;
    void BajaLogica();
    void AltaLogica();
    Producto producto;
     ArchivoProducto archProducto;
    void restarstock(int codigo, int cantidad);
     void bajaFisica();
    void guardarBackup();
    void restaurarArchivo();
    private:
};
