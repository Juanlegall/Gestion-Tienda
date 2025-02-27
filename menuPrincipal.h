#pragma once
#include "claseClientesManager.h"
#include "claseProductosManager.h"
#include "claseCategoriaManager.h"
#include "claseComprasManager.h"
#include "claseVentasManager.h"
#include "claseDetalleManager.h"
class menuPrincipal{
public:
    void menu();
   clientesManager clientesManager;
   ProductoManager productoManager;
   CompraManager compraManager;
   CategoriaManager categoriaManager;
    VentaManager ventaManager;
    DetalleManager detalleManager;
private:
    void menuClientes();
    void menuProducto();
    void menuCategoria();
    void menuCompra();
    void menuDetalle();
    void menuVenta();
};
