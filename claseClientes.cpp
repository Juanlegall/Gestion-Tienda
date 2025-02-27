#include "claseClientes.h"
#include "claseArchivoClientes.h"
#include <iostream>
using namespace std;
void Clientes::cargarCadena(char *pal, int tam){
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

void Clientes::Cargar(){
    ArchivoClientes obj;
        while(true){
                int pos;
        cout<<"Numero dni: "<<endl;
        cin>>DNI;
        pos=obj.buscarRegistro(DNI);
        if(pos>=0){
            cout<<"El dni ya existe pruebe con otro "<<endl;
        }
        else{ break;}
        }
        cout<<"Nombre: "<<endl;
        cargarCadena(nombreCompleto,29);
        cout<<"Email: "<<endl;
        cargarCadena(email,29);
        cout<<"Direccion: "<<endl;
        cargarCadena(direccion,29);
        cout<<"Telefono: "<<endl;
        cin>>telefono;
        estado=true;
    }

    const char* Clientes::getNombreCompleto(){return nombreCompleto;}
    const char* Clientes::getEmail(){return email;}
    const char* Clientes::getDireccion(){return direccion;}
    int Clientes::getTelefono(){return telefono;}
    int Clientes::getDni(){return DNI;}
    bool Clientes::getEstado(){return estado;}

    void Clientes::setNombreCompleto(const char *nom){strcpy(nombreCompleto,nom);}
    void Clientes::setEmail(const char *correo){strcpy(email,correo);}
    void Clientes::setDireccion(const char *direc){strcpy(direccion,direc);}
    void Clientes::setTelefono(int tel){telefono=tel;}
    void Clientes::setDni(int identificacion){DNI=identificacion;}
    void Clientes::setEstado(bool e){estado=e;}
