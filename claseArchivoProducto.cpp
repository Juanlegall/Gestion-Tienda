#include "claseArchivoProductos.h"

        Producto ArchivoProducto::leerRegistro(int pos){
            Producto reg;
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return reg;
            }
            fseek(p, pos * sizeof reg, 0);
            fread(&reg, sizeof reg, 1, p);
            fclose(p);
            return reg;
        }
        int ArchivoProducto::contarRegistros(){
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return -1;
            }
            fseek(p, 0, 2);
            int cant=ftell(p)/sizeof(Producto);
            fclose(p);
            return cant;
        }
        int ArchivoProducto::buscarRegistro(int num){
            Producto obj;
            int pos=0;
            FILE *p;
            p=fopen(nombre,"rb");
            if(p==NULL){
                return -1;
            }
            while(fread(&obj,sizeof(Producto),1,p)){
                if(obj.getCodigo()==num){
                    break;
                }
                pos++;
            }
            fclose(p);
            if(obj.getCodigo()==num){return pos;}
            else{return -1;}
        }
        bool ArchivoProducto::grabarRegistro(Producto reg){
            FILE *p;
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
        void ArchivoProducto::modificar(Producto obj,int num){
        FILE *p;
        p=fopen(nombre, "rb+");
        if(p==NULL)return;
        fseek(p, sizeof(Producto)*num, 0);
        fwrite(&obj, sizeof(Producto), 1, p);
        fclose(p);
        return;
        }
      bool ArchivoProducto::crearBackup(const char *nombreB){
            FILE *pBk;
            Producto obj;
            pBk=fopen(nombreB,"wb");
            if(pBk==NULL)return false;
            int cantReg=contarRegistros();
            for(int i=0;i<cantReg;i++){
                obj=leerRegistro(i);
                fwrite(&obj,sizeof(Producto),1,pBk);
            }
            fclose(pBk);
            return true;
       }
       bool ArchivoProducto::baja(){
            FILE *pBk;
            Producto obj;
            pBk=fopen("borrarP.dat","wb");
            if(pBk==NULL)return false;
            int cantReg=contarRegistros();
            for(int i=0;i<cantReg;i++){
                obj=leerRegistro(i);
                fwrite(&obj,sizeof(Producto),1,pBk);
            }
            fclose(pBk);
            return true;
       }
      bool ArchivoProducto::restaurarRegistros(const char *nombreB){
           FILE *p;
           Producto obj;
           ArchivoProducto productoBackUp(nombreB);
           int cantReg=productoBackUp.contarRegistros();
           p=fopen(nombre,"wb");
           for(int i=0;i<cantReg;i++){
            obj=productoBackUp.leerRegistro(i);
            obj.setEstado(true);
            fwrite(&obj,sizeof(Producto),1,p);
           }
            fclose(p);
            return true;

       }
       bool ArchivoProducto::crearBajaFisica(){
           FILE *p;
           Producto obj;
           ArchivoProducto baja("borrarP.dat");
           int cantReg=baja.contarRegistros();
           p=fopen(nombre,"wb");
           for(int i=0;i<cantReg;i++){
            obj=baja.leerRegistro(i);
            if(obj.getEstado()==true){
            fwrite(&obj,sizeof(Producto),1,p);
            }
           }
            fclose(p);
            return true;
           }

