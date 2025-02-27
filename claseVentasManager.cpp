#include "claseVentasManager.h"
#include <iostream>
using namespace std;
    void VentaManager::agregarVenta(){
        Venta obj;
        obj.Cargar();
        if(archivoVentas.grabarRegistro(obj)==true){
           cout<<"Venta grabada con exito."<<endl;
           }
           else{
            cout<<"No se pudo grabar."<<endl;
           }
    }
    void VentaManager::Mostrar(Venta obj){
    if(obj.getEstado()==true){
        cout<< "CODIGO: " <<obj.getCodigo()<<endl;
        cout << "FECHA: ";
        obj.getFecha().mostrarFecha();
        cout<< "TIPO ENTREGA: " <<obj.getEntrega()<<endl;
        if(obj.getEntrega()==1){
            cout << obj.getDireccion()<< endl;
        }
        cout<< "METODO PAGO: " <<obj.getMetodo()<<endl;
        cout<< "IMPORTE TOTAL: " <<obj.getTotal()<<endl;
    }
    }
    void VentaManager::listarVenta(){

           Venta obj;
        int num, pos;
        cout<<"Ingrese el codigo de Venta a buscar: "<<endl;
        cin>>num;

    pos=archivoVentas.buscarRegistro(num);
    if(pos>=0){
        obj=archivoVentas.leerRegistro(pos);
            Mostrar(obj);
            system("pause");
            return;
        }
     else{cout<<"No existe la venta"<<endl;}
}
    void VentaManager::listarlasVentas(){
    FILE *c;
    Venta obj;
    c=fopen("venta.dat", "rb");
    if(c==NULL) return;
    while(fread(&obj, sizeof(Venta), 1, c)==1){
        Mostrar(obj);
    }
    fclose(c);
    return;
    }
    void VentaManager::modificarPropiedades(){
    int opc, id, pos;
    Venta obj;
    int metodo;
    float total;
    bool entrega;
    cout<<"Ingresar el numero de Venta ";
    cin>>id;
    cout<<endl;
    cout<<"Campo a modificar  1)total||2)metodo||3)entrega: ";
    cin>>opc;
    pos=archivoVentas.buscarRegistro(id);
    if(pos>=0){
    obj=archivoVentas.leerRegistro(pos);
    switch(opc){
case 1:
    cout<<"Ingresar el total nuevo: ";
    cin>>total;
    obj.setTotal(total);
    archivoVentas.modificar(obj, pos);
    break;
    case 2:
    cout<<"Ingresar el metodo de pago nuevo 0)Efectivo al recibir el producto||1)Transferencia||2)Tarjeta debito||3)Tarjeta credito: ";
    cin>>metodo;
    obj.setMetodo(metodo);
    archivoVentas.modificar(obj, pos);
    break;
    case 3:
    cout<<"Ingresar la forma de entrega nueva 0)Retiro por sucursal||1)Envio a domicilio: ";
    cin>>entrega;
    obj.setEntrega(entrega);
    archivoVentas.modificar(obj, pos);
    break;
    }
    return;
    }
    cout<<"No existe la venta"<<endl;
    return;
    }
    void VentaManager::BajaLogica(){
    int id, pos;
    Venta obj;
    cout<<"Ingrear el numero de Venta a dar de baja ";
    cin>>id;
    cout<<endl;
    pos=archivoVentas.buscarRegistro(id);
    if(pos>=0){
    obj=archivoVentas.leerRegistro(pos);
    obj.setEstado(false);
    archivoVentas.modificar(obj, pos);
    return;
    }
    cout<<"No existe la venta"<<endl;
    }

    void VentaManager::AltaLogica(){
    int id, pos;
    Venta obj;
    cout<<"Ingrear el numero de Venta a dar de alta ";
    cin>>id;
    cout<<endl;
    pos=archivoVentas.buscarRegistro(id);
    if(pos>=0){
    obj=archivoVentas.leerRegistro(pos);
    if(obj.getFecha().getAnio()>2023){
    obj.setEstado(true);
    archivoVentas.modificar(obj, pos);
    } else if (obj.getFecha().getAnio()<=2023){
    return;
    }
    return;
    }
    cout<<"No se encontro la venta"<<endl;
    }
 void VentaManager::bajaFisica(){
    int id, pos;
    Venta obj;
    cout<<"Ingrear el numero de venta a dar de baja ";
    cin>>id;
    cout<<endl;
    pos=archivoVentas.buscarRegistro(id);
    if(pos>=0){
    obj=archivoVentas.leerRegistro(pos);
    obj.setEstado(false);
    archivoVentas.modificar(obj, pos);
    archivoVentas.baja();
    if(archivoVentas.crearBajaFisica()==true){
        cout<<"Venta borrada con exito."<<endl;
    }
    else{
        cout<<"Error al borrar la venta."<<endl;
    }
    return;
    }
    cout<<"No se encontro la venta"<<endl;
    }
    void VentaManager::guardarBackup(){
           if(archivoVentas.crearBackup()==true){
            cout<<"Backup creado con exito."<<endl;
           }
           else{
            cout<<"Error al generar backup."<<endl;
           }
       }
    void VentaManager::restaurarArchivo(){
        int n;
        cout<<"Esta seguro que desea restaurar el archivo ventas.dat? 1 restaurar - 0 para volver atras."<<endl;
        cin>>n;
        if(n==0){
            return;
        }
        else{
            if(archivoVentas.restaurarRegistros()==true){
                cout<<"ventas.dat restaurado con exito."<<endl;
            }
            else{
                cout<<"Error al restaurar ventas.dat"<<endl;
            }
        }
    }
