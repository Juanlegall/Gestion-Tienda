#include "claseCategoriaManager.h"
#include <iostream>
using namespace std;
void CategoriaManager::agregarCategoria(){
    Categoria obj;
    obj.Cargar();
    if(ArchivoCategoria.grabarRegistro(obj)==true){
        cout<<"Categoria grabada con exito."<<endl;
           }
        else{
            cout<<"No se pudo grabar."<<endl;
           }
    }

    void CategoriaManager::Mostrar(Categoria obj){
            if(obj.getEstado()==true){

         cout<< "NOMBRE PRODUCTO: " <<obj.getNombreProducto()<<endl;
        cout<< "ID CATEGORIA: " <<obj.getIdCategoria()<<endl;
        cout << endl;

    }
    }

void CategoriaManager::modificarCategoria(){
    int cat, id, opc, pos;
    char n[30];
    Categoria obj;
    cout<<"Ingrese la categoria a modificar: "<<endl;
    cin>>cat;
    cout<<"Campo a modificar  1)ID||2)NOMBRE ";
    cin>>opc;
    pos=ArchivoCategoria.buscarRegistro(cat);
    if(pos>=0){
    obj=ArchivoCategoria.leerRegistro(pos);
    switch(opc){
case 1:
    cout<<"Ingresar el ID nuevo: ";
    cin>>id;
    obj.setIdCategoria(id);
    ArchivoCategoria.modificar(obj, pos);
    break;
    case 2:
    cout<<"Ingresar el nombre nuevo: ";
    categoria.cargarCadena(n,29);
    obj.setNombreProducto(n);
    ArchivoCategoria.modificar(obj, pos);
    break;

    default:
        cout<<"Tecla no valida."<<endl;
        break;
    }
    return;
    }
    cout<<"No existe la categoria"<<endl;
    return;
}

void CategoriaManager::listarCategorias(){
    Categoria obj;
    int cantReg=ArchivoCategoria.contarRegistros();
    for(int i=0;i<cantReg;i++){
        obj=ArchivoCategoria.leerRegistro(i);
        Mostrar(obj);
    }
}
void CategoriaManager::bajaFisica(){
    int id, pos;
    Categoria obj;
    cout<<"Ingrear el numero de categoria a dar de baja ";
    cin>>id;
    cout<<endl;
    pos=ArchivoCategoria.buscarRegistro(id);
    if(pos>=0){
    obj=ArchivoCategoria.leerRegistro(pos);
    obj.setEstado(false);
    ArchivoCategoria.modificar(obj, pos);
    ArchivoCategoria.baja();
    if(ArchivoCategoria.crearBajaFisica()==true){
        cout<<"categoria borrada con exito."<<endl;
    }
    else{
        cout<<"Error al borrar la categoria."<<endl;
    }
    return;
    }
    cout<<"No existe la categoria"<<endl;
    }
    void CategoriaManager::guardarBackup(){
           if(ArchivoCategoria.crearBackup()==true){
            cout<<"Backup creado con exito."<<endl;
           }
           else{
            cout<<"Error al generar backup."<<endl;
           }
       }
    void CategoriaManager::restaurarArchivo(){
        int n;
        cout<<"Esta seguro que desea restaurar el archivo categoria.dat? 1 restaurar - 0 para volver atras."<<endl;
        cin>>n;
        if(n==0){
            return;
        }
        else{
            if(ArchivoCategoria.restaurarRegistros()==true){
                cout<<"categoria.dat restaurado con exito."<<endl;
            }
            else{
                cout<<"Error al restaurar categoria.dat"<<endl;
            }
        }
    }
