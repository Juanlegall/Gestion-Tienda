#pragma once
#include "claseVentas.h"
#include "claseArchivoVentas.h"

class VentaManager{
    public:
    void agregarVenta();
    void Mostrar(Venta obj);
    void listarVenta();
    void modificarPropiedades();
    void listarlasVentas();
    ArchivoVenta archivoVentas;
    Venta aux;
    void BajaLogica();
    void AltaLogica();
    void bajaFisica();
    void guardarBackup();
    void restaurarArchivo();
    private:
};
