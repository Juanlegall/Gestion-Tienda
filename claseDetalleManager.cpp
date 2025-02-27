#include "claseDetalleManager.h"
#include <iostream>
using namespace std;
    void DetalleManager::agregarDetalle(){
        Detalle obj;
        obj.Cargar();
        if(archivoDetalles.grabarRegistro(obj)==true){
           cout<<"Detalle grabada con exito."<<endl;
           restarstock(obj.getCodigoProducto(),obj.getCantidad());
           }
           else{
            cout<<"No se pudo grabar."<<endl;
           }
    }
    void DetalleManager::Mostrar(Detalle obj){
            if(obj.getEstado()==true){
        cout<< "CODIGO: " <<obj.getCodigo()<<endl;
        cout<< "CODIGO VENTA: " <<obj.getCodigoVenta()<<endl;
        cout<< "CODIGO PRODUCTO: " <<obj.getCodigoProducto()<<endl;
        cout<< "PRECIO UNITARIO: " <<obj.getPrecioU()<<endl;
        cout<< "CANTIDAD: " <<obj.getCantidad()<<endl;
    }
    }
    void DetalleManager::buscarDetalle(){
        Detalle obj;
        int num;
        cout<<"Ingrese el numero de Detalle a buscar: "<<endl;
        cin>>num;
        int pos=archivoDetalles.buscarRegistro(num);
        if(pos>=0){
            obj=archivoDetalles.leerRegistro(pos);
            Mostrar(obj);
            return;
        }
        else{
            cout<<"No se pudo encontrar el Detalle."<<endl;
        }
    }
    void DetalleManager::listarlosDetalles(){
    FILE *c;
    Detalle obj;
    c=fopen("Detalle.dat", "rb");
    if(c==NULL) return;
    while(fread(&obj, sizeof(Detalle), 1, c)==1){
        Mostrar(obj);
    }
    fclose(c);
    return;
    }
    void DetalleManager::modificarPropiedades(){
    int opc, id, pos;
    Detalle obj;
    int cantidad;
    float precioU;
    cout<<"Ingresar el numero del Detalle ";
    cin>>id;
    cout<<endl;
    cout<<"Campo a modificar  1)Precio unitarioa||2)Cantidad ";
    cin>>opc;
    pos=archivoDetalles.buscarRegistro(id);
    if(pos>=0){
    obj=archivoDetalles.leerRegistro(pos);
    switch(opc){
case 1:
    cout<<"Ingresar el precio unitario nuevo: ";
    cin>>precioU;
    obj.setPrecioU(precioU);
    archivoDetalles.modificar(obj, pos);
    break;
    case 2:
    cout<<"Ingresar la cantidad nueva: ";
    cin>>cantidad;
    obj.setCantidad(cantidad);
    archivoDetalles.modificar(obj, pos);
    break;
    }
    return;
    }
    cout<<"No existe el detalle"<<endl;
    }
    void DetalleManager::BajaLogica(){
    int id, pos;
    Detalle obj;
    cout<<"Ingrear el numero de Detalle a dar de baja ";
    cin>>id;
    cout<<endl;
    pos=archivoDetalles.buscarRegistro(id);
    obj=archivoDetalles.leerRegistro(pos);
    obj.setEstado(false);
    archivoDetalles.modificar(obj, pos);
    return;
    }
    void DetalleManager::AltaLogica(){
    int id, pos;
    Detalle obj;
    cout<<"Ingrear el numero de Detalle a dar de alta ";
    cin>>id;
    cout<<endl;
    pos=archivoDetalles.buscarRegistro(id);
    obj=archivoDetalles.leerRegistro(pos);
    if(obj.getCantidad()>0){
    obj.setEstado(true);
    archivoDetalles.modificar(obj, pos);
    } else if (obj.getCantidad()==0){
    return;
    }
    }
    void DetalleManager::restarstock(int codigo, int cantidad){
    int i, cantreg, resta;
    cantreg=archProducto.contarRegistros();
    for(i=0;i<cantreg;i++){
        producto=archProducto.leerRegistro(i);
        if(producto.getCodigo()==codigo){
        resta=producto.getStock()-cantidad;
        if(resta<0){
            producto.setStock(0);
            archProducto.modificar(producto, i);
        }
        else{
            producto.setStock(resta);
            archProducto.modificar(producto, i);
        }
    }
    }
    return;
    }
    void DetalleManager::bajaFisica(){
    int id, pos;
    Detalle obj;
    cout<<"Ingrear el numero de detalle a dar de baja ";
    cin>>id;
    cout<<endl;
    pos=archivoDetalles.buscarRegistro(id);
    if(pos>=0){
    obj=archivoDetalles.leerRegistro(pos);
    obj.setEstado(false);
    archivoDetalles.modificar(obj, pos);
    archivoDetalles.baja();
    if(archivoDetalles.crearBajaFisica()==true){
        cout<<"detalle borrado con exito."<<endl;
    }
    else{
        cout<<"Error al borrar detalle."<<endl;
    }
    }
    cout<<"No se encontro el detalle"<<endl;
    }
    void DetalleManager::guardarBackup(){
           if(archivoDetalles.crearBackup()==true){
            cout<<"Backup creado con exito."<<endl;
           }
           else{
            cout<<"Error al generar backup."<<endl;
           }
       }
    void DetalleManager::restaurarArchivo(){
        int n;
        cout<<"Esta seguro que desea restaurar el archivo detalle.dat? 1 restaurar - 0 para volver atras."<<endl;
        cin>>n;
        if(n==0){
            return;
        }
        else{
            if(archivoDetalles.restaurarRegistros()==true){
                cout<<"detalle.dat restaurado con exito."<<endl;
            }
            else{
                cout<<"Error al restaurar detalle.dat"<<endl;
            }
        }
    }

