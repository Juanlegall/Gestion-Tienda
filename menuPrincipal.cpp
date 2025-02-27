#include "menuPrincipal.h"
#include <iostream>
using namespace std;

void menuPrincipal::menuClientes(){
    while(true){
    system("cls");
    cout<<"------------------------"<<endl;
    cout<<"1) AGREGAR CLIENTE."<<endl;
    cout<<"2) DAR DE BAJA CLIENTE."<<endl;
    cout<<"3) BORRAR CLIENTE."<<endl;
    cout<<"4) MODIFICAR CLIENTE."<<endl;
    cout<<"5) BUSCAR CLIENTE."<<endl;
    cout<<"6) LISTAR TODOS LOS CLIENTES."<<endl;
    cout<<"7) DAR DE ALTA CLIENTE."<<endl;
    cout<<"8) GENERAR BACKUP."<<endl;
    cout<<"9) RESTAURAR DESDE BACKUP."<<endl;
    cout<<"0) VOLVER AL MENU PRINCIPAL."<<endl;
    cout<<"------------------------"<<endl;
    int opcion;
    cin>>opcion;
    switch(opcion){
        case 1:
            clientesManager.agregarClientes();
            break;
        case 2:
            clientesManager.BajaLogica();
            break;
        case 3:
            clientesManager.bajaFisica();
            break;
        case 4:
            clientesManager.modificarPropiedades();
            break;
        case 5:
            clientesManager.buscarCliente();
            break;
        case 6:
            clientesManager.listarTodosClientes();
            break;
        case 7:
            clientesManager.AltaLogica();
            break;
        case 8:
            clientesManager.guardarBackup();
            break;
        case 9:
            clientesManager.restaurarArchivo();
            break;
        case 0:
            return;
            break;
        default:
            cout<<"Ingrese otra tecla."<<endl;
            break;
    }
    system("pause");
    }
}
void menuPrincipal::menuProducto(){
while(true){
            system("cls");
    cout<<"------------------------"<<endl;
    cout<<"1) AGREGAR PRODUCTO."<<endl;
    cout<<"2) DAR DE BAJA PRODUCTO."<<endl;
    cout<<"3) BORRAR PRODUCTO."<<endl;
    cout<<"4) MODIFICAR PRODUCTO."<<endl;
    cout<<"5) LISTAR LOS PRODUCTOS."<<endl;
    cout<<"6) BUSCAR PRODUCTO."<<endl;
    cout<<"7) BUSCAR POR CATEGORIA."<<endl;
    cout<<"8) DAR DE ALTA CLIENTE."<<endl;
    cout<<"9) GENERAR BACKUP."<<endl;
    cout<<"10) RESTAURAR DESDE BACKUP."<<endl;
    cout<<"0) VOLVER AL MENU PRINCIPAL."<<endl;
    cout<<"------------------------"<<endl;
    int opcion;
    cin>>opcion;
    switch(opcion){
        case 1:
            productoManager.agregarProducto();
            break;
        case 2:
            productoManager.BajaLogica();
            break;
        case 3:
            productoManager.bajaFisica();
            break;
        case 4:
            productoManager.modificarPropiedades();
            break;
        case 5:
            productoManager.listarTodosProductos();
            break;
        case 6:
            productoManager.listarProducto();
            break;
        case 7:
            productoManager.buscarPorCategoria();
            break;
        case 8:
            productoManager.AltaLogica();
            break;
            case 9:
            productoManager.guardarBackup();
            break;
            case 10:
            productoManager.restaurarArchivo();
            break;
        case 0:
            return;
            break;
        default:
            cout<<"Ingrese otra tecla."<<endl;
            break;
    }
    system("pause");
    }
    return;
}
void menuPrincipal::menuCategoria(){
while(true){
            system("cls");
    cout<<"------------------------"<<endl;
    cout<<"1) AGREGAR CATEGORIAS."<<endl;
    cout<<"2) MODIFICAR CATEGORIA."<<endl;
    cout<<"3) BORRAR CATEGORIA."<<endl;
    cout<<"4) LISTAR CATEGORIAS."<<endl;
    cout<<"5) GENERAR BACKUP."<<endl;
    cout<<"6) RESTAURAR DESDE BACKUP."<<endl;
    cout<<"0) VOLVER AL MENU PRINCIPAL."<<endl;
    cout<<"------------------------"<<endl;
    int opcion;
    cin>>opcion;
    switch(opcion){
    case 1:
        categoriaManager.agregarCategoria();
        break;
    case 2:
        categoriaManager.modificarCategoria();
        break;
         case 3:
        categoriaManager.bajaFisica();
        break;
    case 4:
        categoriaManager.listarCategorias();
        break;
        case 5:
        categoriaManager.guardarBackup();
        break;
        case 6:
        categoriaManager.restaurarArchivo();
        break;
    case 0:
        return;
    default:
        cout<<"Ingrese otra tecla."<<endl;
        break;
    }
    system("pause");
    }
}
void menuPrincipal::menuCompra(){
while(true){
            system("cls");
    cout<<"------------------------"<<endl;
    cout<<"1) AGREGAR COMPRA."<<endl;
    cout<<"2) DAR DE BAJA COMPRA."<<endl;
    cout<<"3) BORRAR COMPRA."<<endl;
    cout<<"4) MODIFICAR COMPRA."<<endl;
    cout<<"5) BUSCAR COMPRA."<<endl;
    cout<<"6) LISTAR TODAS LAS COMPRAS."<<endl;
    cout<<"7) DAR DE ALTA CLIENTE."<<endl;
    cout<<"8) GENERAR BACKUP."<<endl;
    cout<<"9) RESTAURAR DESDE BACKUP."<<endl;
    cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
    cout<<"------------------------"<<endl;
    int opcion;
    cin>>opcion;
    switch(opcion){
        case 1:
            compraManager.agregarCompra();
            break;
        case 2:
            compraManager.BajaLogica();
            break;
        case 3:
            compraManager.bajaFisica();
            break;
        case 4:
            compraManager.modificarPropiedades();
            break;
        case 5:
            compraManager.listarCompra();
            break;
        case 6:
            compraManager.listarCompras();
            break;
        case 7:
            compraManager.AltaLogica();
            break;
            case 8:
            compraManager.guardarBackup();
            break;
            case 9:
            compraManager.restaurarArchivo();
            break;
        case 0:
            return;
            break;
        default:
            cout<<"Ingrese otra tecla."<<endl;
            break;
    }
    system("pause");
    }
    return;
}
void menuPrincipal::menuVenta(){
while(true){
            system("cls");
    cout<<"------------------------"<<endl;
    cout<<"1) AGREGAR VENTA."<<endl;
    cout<<"2) DAR DE BAJA VENTA."<<endl;
    cout<<"3) BORRAR VENTA."<<endl;
    cout<<"4) MODIFICAR VENTA."<<endl;
    cout<<"5) BUSCAR VENTA."<<endl;
    cout<<"6) LISTAR TODAS LAS VENTAS."<<endl;
    cout<<"7) DAR DE ALTA CLIENTE."<<endl;
    cout<<"8) GENERAR BACKUP."<<endl;
    cout<<"9) RESTAURAR DESDE BACKUP."<<endl;
    cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
    cout<<"------------------------"<<endl;
    int opcion;
    cin>>opcion;
    switch(opcion){
        case 1:
            ventaManager.agregarVenta();
            break;
        case 2:
            ventaManager.BajaLogica();
            break;
        case 3:
            ventaManager.bajaFisica();
            break;
        case 4:
            ventaManager.modificarPropiedades();
            break;
        case 5:
            ventaManager.listarVenta();
            break;
        case 6:
            ventaManager.listarlasVentas();
            break;
        case 7:
            ventaManager.AltaLogica();
            break;
            case 8:
            ventaManager.guardarBackup();
            break;
            case 9:
            ventaManager.restaurarArchivo();
            break;

        case 0:
            return;
            break;
        default:
            cout<<"Ingrese otra tecla."<<endl;
            break;
    }
    system("pause");
    }
    return;
}
void menuPrincipal::menuDetalle(){
while(true){
            system("cls");
    cout<<"------------------------"<<endl;
    cout<<"1) AGREGAR DETALLE."<<endl;
    cout<<"2) DAR DE BAJA DETALLE."<<endl;
    cout<<"3) BORRAR DETALLE."<<endl;
    cout<<"4) MODIFICAR DETALLE."<<endl;
    cout<<"5) BUSCAR DETALLE."<<endl;
    cout<<"6) LISTAR TODOS LOS DETALLES."<<endl;
    cout<<"7) DAR DE ALTA CLIENTE."<<endl;
    cout<<"8) GENERAR BACKUP."<<endl;
    cout<<"9) RESTAURAR DESDE BACKUP."<<endl;
    cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
    cout<<"------------------------"<<endl;
    int opcion;
    cin>>opcion;
    switch(opcion){
        case 1:
            detalleManager.agregarDetalle();
            break;
        case 2:
            detalleManager.BajaLogica();
            break;
        case 3:
            detalleManager.bajaFisica();
            break;
        case 4:
            detalleManager.modificarPropiedades();
            break;
        case 5:
            detalleManager.buscarDetalle();
            break;
        case 6:
            detalleManager.listarlosDetalles();
            break;
        case 7:
            detalleManager.AltaLogica();
            break;
            case 8:
            detalleManager.guardarBackup();
            break;
            case 9:
            detalleManager.restaurarArchivo();
            break;
        case 0:
            return;
            break;
        default:
            cout<<"Ingrese otra tecla."<<endl;
            break;
    }
    system("pause");
    }
    return;
}
void menuPrincipal::menu(){
    while(true){
    system("cls");
    cout<<"------------------------"<<endl;
    cout<<"1) MENU DE CLIENTES."<<endl;
    cout<<"2) MENU DE PRODUCTOS."<<endl;
    cout<<"3) MENU DE CATEGORIAS."<<endl;
    cout<<"4) MENU DE COMPRAS."<<endl;
    cout<<"5) MENU DE VENTAS."<<endl;
    cout<<"6) MENU DETALLE VENTAS"<<endl;
    cout<<"0) SALIR."<<endl;
    cout<<"------------------------"<<endl;
    int opcion;
    cin>>opcion;
    switch(opcion){
        case 1:
           menuClientes();
            break;
        case 2:
            menuProducto();
            break;
        case 3:
            menuCategoria();
            break;
        case 4:
            menuCompra();
            break;
        case 5:
            menuVenta();
            break;
        case 6:
            menuDetalle();
            break;
        case 0:
            return;
        default:
            cout<<"Ingrese otra tecla."<<endl;
            break;
    }
    system("pause");
    }
}
