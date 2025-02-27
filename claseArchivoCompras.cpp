#include "claseArchivoCompras.h"

        Compra ArchivoCompras::leerRegistro(int pos){
            Compra reg;
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return reg;
            }
            fseek(p, pos * sizeof reg, 0);
            fread(&reg, sizeof reg, 1, p);
            fclose(p);
            return reg;
        }
        int ArchivoCompras::contarRegistros(){
            FILE *p=fopen(nombre,"rb");
            if(p==NULL){
                return -1;
            }
            fseek(p, 0, 2);
            int cant=ftell(p)/sizeof(Compra);
            fclose(p);
            return cant;
        }
        int ArchivoCompras::buscarRegistro(int num){
            Compra obj;
            int pos=0;
            FILE *p;
            p=fopen(nombre,"rb");
            if(p==NULL){
                return -1;
            }
            while(fread(&obj,sizeof(Compra),1,p)){
                if(obj.getCodigo()==num){
                    break;
                }
                pos++;
            }
            fclose(p);
            if(obj.getCodigo()==num){return pos;}
            else{return -1;}
        }
        bool ArchivoCompras::grabarRegistro(Compra reg){
            FILE *p;
            p=fopen(nombre, "ab");
            if(p==NULL) return false;
            int escribio=fwrite(&reg, sizeof reg,1, p);
            fclose(p);
            return escribio;
        }
        void ArchivoCompras::modificar(Compra obj,int num){
        FILE *p;
        p=fopen(nombre, "rb+");
        if(p==NULL)return;
        fseek(p, sizeof(Compra)*num, 0);
        fwrite(&obj, sizeof(Compra), 1, p);
        fclose(p);
        return;
        }
        bool ArchivoCompras::crearBackup(const char *nombreB){
            FILE *pBk;
            Compra obj;
            pBk=fopen(nombreB,"wb");
            if(pBk==NULL)return false;
            int cantReg=contarRegistros();
            for(int i=0;i<cantReg;i++){
                obj=leerRegistro(i);
                fwrite(&obj,sizeof(Compra),1,pBk);
            }
            fclose(pBk);
            return true;
       }
       bool ArchivoCompras::baja(){
            FILE *pBk;
            Compra obj;
            pBk=fopen("borrarCom.dat","wb");
            if(pBk==NULL)return false;
            int cantReg=contarRegistros();
            for(int i=0;i<cantReg;i++){
                obj=leerRegistro(i);
                fwrite(&obj,sizeof(Compra),1,pBk);
            }
            fclose(pBk);
            return true;
       }
      bool ArchivoCompras::restaurarRegistros(const char *nombreB){
           FILE *p;
           Compra obj;
           ArchivoCompras comprasBackUp(nombreB);
           int cantReg=comprasBackUp.contarRegistros();
           p=fopen(nombre,"wb");
           for(int i=0;i<cantReg;i++){
            obj=comprasBackUp.leerRegistro(i);
            obj.setEstado(true);
            fwrite(&obj,sizeof(Compra),1,p);
           }
            fclose(p);
            return true;

       }
       bool ArchivoCompras::crearBajaFisica(){
           FILE *p;
           Compra obj;
           ArchivoCompras baja("borrarCom.dat");
           int cantReg=baja.contarRegistros();
           p=fopen(nombre,"wb");
           for(int i=0;i<cantReg;i++){
            obj=baja.leerRegistro(i);
            if(obj.getEstado()==true){
            fwrite(&obj,sizeof(Compra),1,p);
            }
           }
            fclose(p);
            return true;
           }


