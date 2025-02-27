#include "claseCategoria.h"
#include "claseArchivoProductos.h"
#include <iostream>
using namespace std;

    void Categoria::cargarCadena(char *pal, int tam){
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
    void Categoria::Cargar(){

        cout << "NOMBRE PRODUCTO: ";
        cargarCadena(nombreProducto,29);
        cout << "ID CATEGORIA: ";
        cin>>idCategoria;
        estado=true;
    }


    const char* Categoria::getNombreProducto(){return nombreProducto;}
    int Categoria::getIdCategoria(){return idCategoria;}
    bool Categoria::getEstado(){return estado;}

    void Categoria::setNombreProducto(const char *nom){strcpy(nombreProducto,nom);}
    void Categoria::setIdCategoria(int idCat){idCategoria=idCat;}
    void Categoria::setEstado(bool e){estado=e;}
