#include "claseProductosManager.h"
#include <iostream>
using namespace std;
    void ProductoManager::agregarProducto(){
        Producto obj;
        obj.Cargar();
        if(archivoProducto.grabarRegistro(obj)==true){
           cout<<"Producto grabada con exito."<<endl;
           }
           else{
            cout<<"No se pudo grabar."<<endl;
           }
    }
    void ProductoManager::Mostrar(Producto obj){
            if(obj.getEstado()==true){
        cout<< "CODIGO: " <<obj.getCodigo()<<endl;
        cout<< "NOMBRE: " <<obj.getNombre()<<endl;
        cout<< "PRECIO: " <<obj.getPrecio()<<endl;
        cout<< "STOCK: " <<obj.getStock()<<endl;
        cout<< "CATEGORIA: " <<obj.getCategoria()<<endl;
        cout << endl;
    }
    }
    void ProductoManager::listarProducto(){
        Producto obj;
        int num, pos;
        cout<<"Ingrese el numero de producto a buscar: "<<endl;
        cin>>num;
    pos=archivoProducto.buscarRegistro(num);
    if(pos>=0){
        obj=archivoProducto.leerRegistro(pos);
            Mostrar(obj);
            system("pause");
            return;
        }
        else{cout<<"No se encontro el producto"<<endl;}
    }


    void ProductoManager::listarTodosProductos(){
    Producto obj;
    int cantReg=archivoProducto.contarRegistros();
    for (int i=0;i<cantReg;i++){
        obj=archivoProducto.leerRegistro(i);
    if(obj.getEstado()==true){
        Mostrar(obj);
    }
    }
    return;
    }
    void ProductoManager::modificarPropiedades(){
    int opc, id, pos;
    Producto obj;
    int stock;
    float precio;
    cout<<"Ingresar el numero del producto ";
    cin>>id;
    cout<<endl;
    cout<<"Campo a modificar  1)Precio||2)Stock ";
    cin>>opc;
    pos=archivoProducto.buscarRegistro(id);
    if(pos>=0){
    obj=archivoProducto.leerRegistro(pos);
    switch(opc){
case 1:
    cout<<"Ingresar el precio nuevo: ";
    cin>>precio;
    obj.setPrecio(precio);
    archivoProducto.modificar(obj, pos);
    break;
    case 2:
    cout<<"Ingresar el stock nuevo: ";
    cin>>stock;
    obj.setStock(stock);
    archivoProducto.modificar(obj, pos);
    break;
    }
    return;
    }
    cout<<"No se encontro el producto"<<endl;
    }
    void ProductoManager::BajaLogica(){
    int id, pos;
    Producto obj;
    cout<<"Ingrear el numero de Producto a dar de baja ";
    cin>>id;
    cout<<endl;
    pos=archivoProducto.buscarRegistro(id);
    if(pos>=0){
    obj=archivoProducto.leerRegistro(pos);
    obj.setEstado(false);
    archivoProducto.modificar(obj, pos);
    return;
    }
    cout<<"No se encontro el producto"<<endl;
    }
    void ProductoManager::buscarPorCategoria(){
    Producto prod;
    int cat, pos;
    cout<<"Ingrese la categoria a buscar: "<<endl;
    cin>>cat;
    pos=archivoProducto.buscarRegistro(cat);
    if(pos>=0){
        prod=archivoProducto.leerRegistro(pos);
            Mostrar(prod);
            system("pause");
            return;
        }
        cout<<"No existe la categoria"<<endl;
    }

    void ProductoManager::AltaLogica(){
    int id, pos;
    Producto obj;
    cout<<"Ingrear el numero de Producto a dar de alta ";
    cin>>id;
    cout<<endl;
    pos=archivoProducto.buscarRegistro(id);
    if(pos>=0){
    obj=archivoProducto.leerRegistro(pos);
    if(strcmp(obj.getNombre(),"")!=0){
    obj.setEstado(true);
    archivoProducto.modificar(obj, pos);
    } else if(strcmp(obj.getNombre(),"")==0){
        return;
    }
    return;
    }
    cout<<"No existe tal producto"<<endl;
    }
void ProductoManager::bajaFisica(){
    int id, pos;
    Producto obj;
    cout<<"Ingrear el numero de producto a dar de baja ";
    cin>>id;
    cout<<endl;
    pos=archivoProducto.buscarRegistro(id);
    if(pos>=0){
    obj=archivoProducto.leerRegistro(pos);
    obj.setEstado(false);
    archivoProducto.modificar(obj, pos);
    archivoProducto.baja();
    if(archivoProducto.crearBajaFisica()==true){
        cout<<"producto borrado con exito."<<endl;
    }
    else{
        cout<<"Error al borrar el producto."<<endl;
    }
    return;
    }
    cout<<"No se encontro el producto"<<endl;
}
    void ProductoManager::guardarBackup(){
           if(archivoProducto.crearBackup()==true){
            cout<<"Backup creado con exito."<<endl;
           }
           else{
            cout<<"Error al generar backup."<<endl;
           }
       }
    void ProductoManager::restaurarArchivo(){
        int n;
        cout<<"Esta seguro que desea restaurar el archivo productos.dat? 1 restaurar - 0 para volver atras."<<endl;
        cin>>n;
        if(n==0){
            return;
        }
        else{
            if(archivoProducto.restaurarRegistros()==true){
                cout<<"productos.dat restaurado con exito."<<endl;
            }
            else{
                cout<<"Error al restaurar productos.dat"<<endl;
            }
        }
    }
