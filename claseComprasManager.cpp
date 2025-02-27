#include "claseComprasManager.h"
#include <iostream>
using namespace std;
    void CompraManager::agregarCompra(){
        Compra obj;
        obj.Cargar();
        if(archivocompras.grabarRegistro(obj)==true){
           cout<<"Compra grabada con exito."<<endl;
           sumarstock(obj.getNombre(), obj.getCantidad());
           }
           else{
            cout<<"No se pudo grabar."<<endl;
           }
    }
    void CompraManager::Mostrar(Compra obj){
            if(obj.getEstado()==true){
        cout<< "CODIGO: " <<obj.getCodigo()<<endl;
        cout<< "NOMBRE: " <<obj.getNombre()<<endl;
        cout<< "IMPORTE: " <<obj.getImporte()<<endl;
        cout<< "CANTIDAD: " <<obj.getCantidad()<<endl;
    }
    }
    void CompraManager::buscarCompra(){
        Compra obj;
        int cod,pos;
        cout<<"Ingrese el codigo de Compra: "<<endl;
        cin>>cod;

    pos=archivocompras.buscarRegistro(cod);
    if(pos>=0){
        obj=archivocompras.leerRegistro(i);
            Mostrar(obj);
            system("pause");
            return;
        }
    else{cout<<"No se pudo encontrar la compra."<<endl;}
    }
    void CompraManager::listarCompras(){
    FILE *c;
    Compra obj;
    c=fopen("Compras.dat", "rb");
    if(c==NULL) return;
    while(fread(&obj, sizeof(Compra), 1, c)==1){
        Mostrar(obj);
    }
    fclose(c);
    return;
    }
    void CompraManager::modificarPropiedades(){
    int opc, id, pos;
    Compra obj;
    int cantidad;
    float importe;
    cout<<"Ingresar el numero del Compra ";
    cin>>id;
    cout<<endl;
    cout<<"Campo a modificar  1)importe||2)cantidad ";
    cin>>opc;
    pos=archivocompras.buscarRegistro(id);
    if(pos>=0){
    obj=archivocompras.leerRegistro(pos);
    switch(opc){
case 1:
    cout<<"Ingresar el importe nuevo: ";
    cin>>importe;
    obj.setImporte(importe);
    archivocompras.modificar(obj, pos);
    break;
    case 2:
    cout<<"Ingresar el cantidad nuevo: ";
    cin>>cantidad;
    obj.setCantidad(cantidad);
    archivocompras.modificar(obj, pos);
    break;
    }
    return;
    }
    cout<<"No se encontro la compra"<<endl;
    }
    void CompraManager::BajaLogica(){
    int id, pos;
    Compra obj;
    cout<<"Ingrear el numero de compra a dar de baja ";
    cin>>id;
    cout<<endl;
    pos=archivocompras.buscarRegistro(id);
    if(pos>=0){
    obj=archivocompras.leerRegistro(pos);
    obj.setEstado(false);
    archivocompras.modificar(obj, pos);
    return;
    }
    cout<<"No se encontro la compra"<<endl;
    }
    void CompraManager::AltaLogica(){
    int id, pos;
    Compra obj;
    cout<<"Ingresar el numero de compra a dar de alta ";
    cin>>id;
    cout<<endl;
    pos=archivocompras.buscarRegistro(id);
    if(pos>=0){
    obj=archivocompras.leerRegistro(pos);
    if(obj.getImporte()>0){
    obj.setEstado(true);
    archivocompras.modificar(obj, pos);
    }else if(obj.getImporte()==0){
    return;
    }
    return;
    }
    cout<<"No se encontro la compra"<<endl;
    }
    void CompraManager::sumarstock(const char *nombre, int cantidad){
    int i, cantreg, suma;
    cantreg=archProducto.contarRegistros();
    for(i=0;i<cantreg;i++){
        producto=archProducto.leerRegistro(i);
        if(strcmp(nombre, producto.getNombre())==0){
            suma=producto.getStock()+cantidad;
            producto.setStock(suma);
            archProducto.modificar(producto, i);
        }
    }
    return;

    }
    void CompraManager::bajaFisica(){
    int id, pos;
    Compra obj;
    cout<<"Ingrear el numero de compra a dar de baja ";
    cin>>id;
    cout<<endl;
    pos=archivocompras.buscarRegistro(id);
    if(pos>=0){
    obj=archivocompras.leerRegistro(pos);
    obj.setEstado(false);
    archivocompras.modificar(obj, pos);
    archivocompras.crearBackup();
    if(archivocompras.crearBajaFisica()==true){
        cout<<"compra borrada con exito."<<endl;
    }
    else{
        cout<<"Error al borrar la compra."<<endl;
    }
    return
    }
    cout<<"No se encontro la compra"<<endl;
    }
    void CompraManager::guardarBackup(){
           if(archivocompras.crearBackup()==true){
            cout<<"Backup creado con exito."<<endl;
           }
           else{
            cout<<"Error al generar backup."<<endl;
           }
       }
    void CompraManager::restaurarArchivo(){
        int n;
        cout<<"Esta seguro que desea restaurar el archivo Compras.dat? 1 restaurar - 0 para volver atras."<<endl;
        cin>>n;
        if(n==0){
            return;
        }
        else{
            if(archivocompras.restaurarRegistros()==true){
                cout<<"Compras.dat restaurado con exito."<<endl;
            }
            else{
                cout<<"Error al restaurar Compras.dat"<<endl;
            }
        }
    }

