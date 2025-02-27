#include "claseClientesManager.h"
#include <iostream>
using namespace std;
    void clientesManager::agregarClientes(){
        Clientes obj;
        obj.Cargar();
        if(archivoClientes.grabarRegistro(obj)==true){
           cout<<"Cliente grabado con exito."<<endl;
           }
           else{
            cout<<"No se pudo grabar."<<endl;
           }
    }
    void clientesManager::Mostrar(Clientes obj){
            if(obj.getEstado()==true){
        cout<< "DNI: " <<obj.getDni()<<endl;
        cout<< "NOMBRE: "<<obj.getNombreCompleto()<<endl;
        cout<< "EMAIL: "<<obj.getEmail()<<endl;
        cout<< "DIRECCION: "<<obj.getDireccion()<<endl;
        cout<< "TELEFONO: "<<obj.getTelefono()<<endl;
        cout << endl;

    }
    }
    void clientesManager::bajaFisica(){
    int id, pos;
    Clientes obj;
    cout<<"Ingrear el dni de cliente a dar de baja ";
    cin>>id;
    cout<<endl;
    pos=archivoClientes.buscarRegistro(id);
    if(pos>=0){
    obj=archivoClientes.leerRegistro(pos);
    obj.setEstado(false);
    archivoClientes.modificar(obj, pos);
    archivoClientes.baja();
    if(archivoClientes.crearBajaFisica()==true){
        cout<<"Cliente borrado con exito."<<endl;
    }
    else{
        cout<<"Error al borrar cliente."<<endl;
    }
    return;
    }
    cout<<"No existe el cliente"<<endl;
    }
    void clientesManager::buscarCliente(){
        Clientes obj;
        int num, pos;
        cout<<"Ingrese el numero de dni del cliente a buscar: "<<endl;
        cin>>num;
    pos=archivoClientes.buscarRegistro(num);
        if(pos>=0){
        obj=archivoClientes.leerRegistro(pos);
            Mostrar(obj);
            system("pause");
            return;
        }
        else{cout<<"No existe el cliente"<<endl;}
    }

    void clientesManager::listarTodosClientes(){
    FILE *c;
    Clientes obj;
    c=fopen("clientes.dat", "rb");
    if(c==NULL) return;
    while(fread(&obj, sizeof(Clientes), 1, c)==1){
        Mostrar(obj);
    }
    fclose(c);
    return;
    }
    void clientesManager::modificarPropiedades(){
    int opc, id, pos;
    Clientes obj;
    char email[30];
    char direccion[30];
    int telefono;
    cout<<"Ingresar el dni del cliente ";
    cin>>id;
    cout<<endl;
    cout<<"Campo a modificar  1)Telefono||2)Email||3)Direccion ";
    cin>>opc;
    pos=archivoClientes.buscarRegistro(id);
    if(pos>=0){
    obj=archivoClientes.leerRegistro(pos);
    switch(opc){
case 1:
    cout<<"Ingresar el numero de telefono nuevo: ";
    cin>>telefono;
    obj.setTelefono(telefono);
    archivoClientes.modificar(obj, pos);
    break;
    case 2:
    cout<<"Ingresar el email nuevo: ";
    aux.cargarCadena(email, 30);
    obj.setEmail(email);
    archivoClientes.modificar(obj, pos);
    break;
    case 3:
    cout<<"Ingresar la direccion nueva: ";
    aux.cargarCadena(direccion, 30);
    obj.setDireccion(direccion);
    archivoClientes.modificar(obj, pos);
    break;
    }
    return;
    }
    cout<<"No existe el cliente"<<endl;
    return;
    }
    void clientesManager::BajaLogica(){
    int id, pos;
    Clientes obj;
    cout<<"Ingrear el dni de cliente a dar de baja ";
    cin>>id;
    cout<<endl;
    pos=archivoClientes.buscarRegistro(id);
    if(pos>=0){
    obj=archivoClientes.leerRegistro(pos);
    obj.setEstado(false);
    archivoClientes.modificar(obj, pos);
    return;
    }
    cout<<"No existe el cliente"<<endl;
    }
    void clientesManager::AltaLogica(){
    int id, pos;
    Clientes obj;
    cout<<"Ingrear el dni de cliente a dar de alta ";
    cin>>id;
    cout<<endl;
    pos=archivoClientes.buscarRegistro(id);
    if(pos>=0){
    obj=archivoClientes.leerRegistro(pos);
    if (obj.getTelefono()>0){
    obj.setEstado(true);
    archivoClientes.modificar(obj, pos);
    return;
    } else if (obj.getTelefono()==0){
    return;
    }
    return;
    }
    cout<<"No existe el cliente en el archivo"<<endl;
    }
    void clientesManager::guardarBackup(){
           if(archivoClientes.crearBackup()==true){
            cout<<"Backup creado con exito."<<endl;
           }
           else{
            cout<<"Error al generar backup."<<endl;
           }
       }
    void clientesManager::restaurarArchivo(){
        int n;
        cout<<"Esta seguro que desea restaurar el archivo clientes.dat? 1 restaurar - 0 para volver atras."<<endl;
        cin>>n;
        if(n==0){
            return;
        }
        else{
            if(archivoClientes.restaurarRegistros()==true){
                cout<<"clientes.dat restaurado con exito."<<endl;
            }
            else{
                cout<<"Error al restaurar clientes.dat"<<endl;
            }
        }
    }
