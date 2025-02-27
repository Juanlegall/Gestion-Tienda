#include<iostream>
#include<cstring>
#include "claseProductos.h"
#include "claseArchivoProductos.h"
#include "claseArchivoCategoria.h"
using namespace std;


void Producto::cargarCadena(char *pal, int tam){
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

void Producto::Cargar(){
    ArchivoProducto obj;
    ArchivoCategoria cat;
        while(true){
                int pos;
                cout<<"Codigo: "<<endl;
                cin>>codigo;
                pos=obj.buscarRegistro(codigo);
                if(pos>=0){
            cout<<"El id ya existe pruebe con otro."<<endl;
            }
        else{ break;}
        }
        cout<<"Nombre: "<<endl;
        cargarCadena(nombre,29);
        cout<<"Precio: "<<endl;
        cin>>precio;
        cout<<"stock: "<<endl;
        cin>>stock;
        while(true){
                int categorias;
                cout<<"categoria: "<<endl;
                cin>>categoria;
                categorias=cat.buscarRegistro(categoria);
                if(categorias>=0){break;}
            else{
            cout<<"Elija una categoría existente. "<<endl;
            }
        }
        estado=true;
    }
    int Producto::getCodigo(){return codigo;}
    const char* Producto::getNombre(){return nombre;}
    int Producto::getStock(){return stock;}
    int Producto::getCategoria(){return categoria;}
    float Producto::getPrecio(){return precio;}
    bool Producto::getEstado(){return estado;}
    void Producto::setCodigo(int num){codigo=num;}
    void Producto::setNombre(const char *nom){strcpy(nombre,nom);}
    void Producto::setPrecio(float p){precio=p;}
    void Producto::setStock(int s){stock=s;}
    void Producto::setCategoria(int cat){categoria=cat;}
    void Producto::setEstado(bool e){estado=e;}
