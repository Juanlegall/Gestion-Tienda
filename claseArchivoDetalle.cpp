#include "claseArchivoDetalle.h"

        Detalle ArchivoDetalle::leerRegistro(int pos){
            Detalle reg;
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return reg;
            }
            fseek(p, pos * sizeof reg, 0);
            fread(&reg, sizeof reg, 1, p);
            fclose(p);
            return reg;
        }
        int ArchivoDetalle::contarRegistros(){
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return -1;
            }
            fseek(p, 0, 2);
            int cant=ftell(p)/sizeof(Detalle);
            fclose(p);
            return cant;
        }
        int ArchivoDetalle::buscarRegistro(int num){
            Detalle obj;
            int pos=0;
            FILE *p;
            p=fopen(nombre,"rb");
            if(p==NULL){
                return -1;
            }
            while(fread(&obj,sizeof(Detalle),1,p)){
                if(obj.getCodigo()==num){
                    break;
                }
                pos++;
            }
            fclose(p);
            if(obj.getCodigo()==num){return pos;}
            else{return -1;}
        }
        bool ArchivoDetalle::grabarRegistro(Detalle reg){
            FILE *p;
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
        void ArchivoDetalle::modificar(Detalle obj,int num){
        FILE *p;
        p=fopen(nombre, "rb+");
        if(p==NULL)return;
        fseek(p, sizeof(Detalle)*num, 0);
        fwrite(&obj, sizeof(Detalle), 1, p);
        fclose(p);
        return;
        }
        bool ArchivoDetalle::crearBackup(const char *nombreB){
            FILE *pBk;
            Detalle obj;
            pBk=fopen(nombreB,"wb");
            if(pBk==NULL)return false;
            int cantReg=contarRegistros();
            for(int i=0;i<cantReg;i++){
                obj=leerRegistro(i);
                fwrite(&obj,sizeof(Detalle),1,pBk);
            }
            fclose(pBk);
            return true;
       }
    bool ArchivoDetalle::baja(){
            FILE *pBk;
            Detalle obj;
            pBk=fopen("borrarDet.dat","wb");
            if(pBk==NULL)return false;
            int cantReg=contarRegistros();
            for(int i=0;i<cantReg;i++){
                obj=leerRegistro(i);
                fwrite(&obj,sizeof(Detalle),1,pBk);
            }
            fclose(pBk);
            return true;
       }
      bool ArchivoDetalle::restaurarRegistros(const char *nombreB){
           FILE *p;
           Detalle obj;
           ArchivoDetalle detalleBackUp(nombreB);
           int cantReg=detalleBackUp.contarRegistros();
           p=fopen(nombre,"wb");
           for(int i=0;i<cantReg;i++){
            obj=detalleBackUp.leerRegistro(i);
            obj.setEstado(true);
            fwrite(&obj,sizeof(Detalle),1,p);
           }
            fclose(p);
            return true;

       }
       bool ArchivoDetalle::crearBajaFisica(){
           FILE *p;
           Detalle obj;
           ArchivoDetalle baja("borrarDet.dat");
           int cantReg=baja.contarRegistros();
           p=fopen(nombre,"wb");
           for(int i=0;i<cantReg;i++){
            obj=baja.leerRegistro(i);
            if(obj.getEstado()==true){
            fwrite(&obj,sizeof(Detalle),1,p);
            }
           }
            fclose(p);
            return true;
           }


