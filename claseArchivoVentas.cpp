#include "claseArchivoVentas.h"

        Venta ArchivoVenta::leerRegistro(int pos){
            Venta reg;
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return reg;
            }
            fseek(p, pos * sizeof reg, 0);
            fread(&reg, sizeof reg, 1, p);
            fclose(p);
            return reg;
        }
        int ArchivoVenta::contarRegistros(){
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return -1;
            }
            fseek(p, 0, 2);
            int cant=ftell(p)/sizeof(Venta);
            fclose(p);
            return cant;
        }
        int ArchivoVenta::buscarRegistro(int num){
            Venta obj;
            int pos=0;
            FILE *p;
            p=fopen(nombre,"rb");
            if(p==NULL){
                return -1;
            }
            while(fread(&obj,sizeof(Venta),1,p)){
                if(obj.getCodigo()==num){
                    break;
                }
                pos++;
            }
            fclose(p);
            if(obj.getCodigo()==num){return pos;}
            else{return -1;}
        }
        bool ArchivoVenta::grabarRegistro(Venta reg){
            FILE *p;
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
        void ArchivoVenta::modificar(Venta obj,int num){
        FILE *p;
        p=fopen(nombre, "rb+");
        if(p==NULL)return;
        fseek(p, sizeof(Venta)*num, 0);
        fwrite(&obj, sizeof(Venta), 1, p);
        fclose(p);
        return;
        }
           bool ArchivoVenta::crearBackup(const char *nombreB){
            FILE *pBk;
            Venta obj;
            pBk=fopen(nombreB,"wb");
            if(pBk==NULL)return false;
            int cantReg=contarRegistros();
            for(int i=0;i<cantReg;i++){
                obj=leerRegistro(i);
                fwrite(&obj,sizeof(Venta),1,pBk);
            }
            fclose(pBk);
            return true;
       }
       bool ArchivoVenta::baja(){
            FILE *pBk;
            Venta obj;
            pBk=fopen("borrarV.dat","wb");
            if(pBk==NULL)return false;
            int cantReg=contarRegistros();
            for(int i=0;i<cantReg;i++){
                obj=leerRegistro(i);
                fwrite(&obj,sizeof(Venta),1,pBk);
            }
            fclose(pBk);
            return true;
       }
      bool ArchivoVenta::restaurarRegistros(const char *nombreB){
           FILE *p;
           Venta obj;
           ArchivoVenta ventasBackUp(nombreB);
           int cantReg=ventasBackUp.contarRegistros();
           p=fopen(nombre,"wb");
           for(int i=0;i<cantReg;i++){
            obj=ventasBackUp.leerRegistro(i);
            obj.setEstado(true);
            fwrite(&obj,sizeof(Venta),1,p);
           }
            fclose(p);
            return true;

       }
       bool ArchivoVenta::crearBajaFisica(){
           FILE *p;
           Venta obj;
           ArchivoVenta baja("borrarV.dat");
           int cantReg=baja.contarRegistros();
           p=fopen(nombre,"wb");
           for(int i=0;i<cantReg;i++){
            obj=baja.leerRegistro(i);
            if(obj.getEstado()==true){
            fwrite(&obj,sizeof(Venta),1,p);
            }
           }
            fclose(p);
            return true;
           }

