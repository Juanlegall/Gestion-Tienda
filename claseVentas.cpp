#include<iostream>
#include<cstring>
#include "claseVentas.h"
#include "claseArchivoVentas.h"
#include "claseArchivoClientes.h"
using namespace std;
void Venta::cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}
void Venta::Cargar(){
    ArchivoVenta obj;
    ArchivoClientes aux;
    while(true){
        int pos;
        cout<<"codigo venta: "<<endl;
        cin >> codigo;
        pos=obj.buscarRegistro(codigo);
        if(pos>=0){
            cout<<"El codigo ya existe pruebe con otro "<<endl;
        }
        else{ break;}
    }
    while(true){
        int pos;
        cout<<"codigo cliente: "<<endl;
        cin>>codigoCliente;
        pos=aux.buscarRegistro(codigoCliente);
        if(pos>=0){
        break;
        }
        else{ cout<<"El codigo de cliente no existe pruebe con otro"<<endl;}
    }
        cout<<"fecha: "<<endl;
        fecha.cargarFecha();
        fecha.mostrarFecha();
        cout<<"entrega  0)Retiro por sucursal||1)Envio a domicilio: "<<endl;
        cin>>entrega;
        if(entrega==1){
            cout<<"Ingrese el domicilio de envío: "<<endl;
            cargarCadena(direccion,29);
        }
        else{
            direccion[30]={0};
        }
        cout<<"metodo de pago 0)Efectivo al recibir el producto||1)Transferencia||2)Tarjeta debito||3)Tarjeta credito: "<<endl;
        cin>>metodo;
        cout<<"total : "<<endl;
        cin>>total;
        estado=true;
    }
    int Venta::getCodigo(){return codigo;}
    int Venta::getCodigoCliente(){return codigoCliente;}
    Fecha Venta::getFecha(){return fecha;}
    int Venta::getMetodo(){return metodo;}
    float Venta::getTotal(){return total;}
    bool Venta::getEntrega(){return entrega;}
    const char* Venta::getDireccion(){return direccion;}
    bool Venta::getEstado(){return estado;}
    void Venta::setCodigo(int det){codigo=det;}
    void Venta::setCodigoCliente(int cli){codigoCliente=cli;}
    void Venta::setFecha(Fecha fe){fecha=fe;}
    void Venta::setTotal(float t){total=t;}
    void Venta::setMetodo(int m){metodo=m;}
    void Venta::setEntrega(bool ent){entrega=ent;}
    void Venta::setDireccion(const char *direc){strcpy(direccion,direc);}
    void Venta::setEstado(bool e){estado=e;}
