#pragma once
#include "claseProductos.h"
#include "claseArchivoProductos.h"

class ProductoManager{
    public:
    void agregarProducto();
    void Mostrar(Producto obj);
    void listarProducto();
    void listarTodosProductos();
    void modificarPropiedades();
    ArchivoProducto archivoProducto;
    Producto aux;
    void BajaLogica();
    void buscarPorCategoria();
    void AltaLogica();
     void bajaFisica();
    void guardarBackup();
    void restaurarArchivo();
    private:
};
