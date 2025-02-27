#include<iostream>
#include<cstring>
#include "claseCompras.h"
#include "claseArchivoCompras.h"
using namespace std;
void Compra::cargarCadena(char *pal, int tam){
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

void Compra::Cargar(){
    ArchivoCompras obj;
        while(true){
                int pos;
        cout<<"Codigo: "<<endl;
        cin>>codigo;
        pos=obj.buscarRegistro(codigo);
        if(pos>=0){
            cout<<"El id ya existe pruebe con otro "<<endl;
        }
        else{ break;}
        }
        cout<<"Nombre: "<<endl;
        cargarCadena(nombre,29);
        cout<<"Importe: "<<endl;
        cin>>importe;
        cout<<"Cantidad: "<<endl;
        cin>>cantidad;
        estado=true;
    }
    int Compra::getCodigo(){return codigo;}
    const char* Compra::getNombre(){return nombre;}
    int Compra::getCantidad(){return cantidad;}
    float Compra::getImporte(){return importe;}
    bool Compra::getEstado(){return estado;}
    void Compra::setCodigo(int num){codigo=num;}
    void Compra::setNombre(const char *nom){strcpy(nombre,nom);}
    void Compra::setImporte(float i){ importe=i;}
    void Compra::setCantidad(int c){cantidad=c;}
    void Compra::setEstado(bool e){estado=e;}
