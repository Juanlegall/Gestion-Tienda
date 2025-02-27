#include<iostream>
#include<cstring>
#include "claseDetalle.h"
#include "claseProductos.h"
#include "claseArchivoDetalle.h"
#include "claseArchivoVentas.h"
#include "claseArchivoProductos.h"
using namespace std;

void Detalle::Cargar(){
    ArchivoDetalle obj;
    ArchivoVenta ven;
    ArchivoProducto pro;
    Producto prod;
        while(true){
                int pos=0;
        cout<<"codigo: "<<endl;
        cin>>codigo;
        pos=obj.buscarRegistro(codigo);
        if(pos>=0){
            cout<<"El id ya existe, pruebe con otro "<<endl;
        }
        else{ break;}
        }
        while(true){
        int pos=0;
        cout<<"codigo venta: "<<endl;
        cin>>codigoVenta;
        pos=ven.buscarRegistro(codigoVenta);
        if(pos>=0){
        break;
        }
        else{ cout<<"El codigo de venta no existe, pruebe con otro"<<endl;}
    }
     while(true){
int pospro=0;
        cout<<"codigo producto: "<<endl;
        cin>>codigoProducto;
        pospro=pro.buscarRegistro(codigoProducto);
        if(pospro>=0){
        prod=pro.leerRegistro(pospro);
        break;

        }
        else{ cout<<"El codigo de producto no existe, pruebe con otro"<<endl;}
    }
        cout<<"precio unitario : "<<endl;
        cout<<prod.getPrecio()<<endl;
        precioU=prod.getPrecio();
        cout<<"cantidad: "<<endl;
        cin>>cantidad;
        estado=true;
    }
    int Detalle::getCodigo(){return codigo;}
    int Detalle::getCodigoVenta(){return codigoVenta;}
    int Detalle::getCodigoProducto(){return codigoProducto;}
    int Detalle::getCantidad(){return cantidad;}
    float Detalle::getPrecioU(){return precioU;}
    bool Detalle::getEstado(){return estado;}
    void Detalle::setCodigo(int det){codigo=det;}
    void Detalle::setCodigoVenta(int ven){codigoVenta=ven;}
    void Detalle::setCodigoProducto(int pro){codigoProducto=pro;}
    void Detalle::setPrecioU(float p){precioU=p;}
    void Detalle::setCantidad(int c){cantidad=c;}
    void Detalle::setEstado(bool e){estado=e;}
